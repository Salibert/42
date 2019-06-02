import User from '../models/userDB'
import _ from 'lodash'
import { con } from '../config/connect'
import moment from 'moment'
import match from '../models/matchDB'


con.connect((err) => {
  if (err)
  console.error('error connect : ', err)
})

export default (socket) => {
  socket.on('disconnect', (data) => disconnected(data, socket))

  socket.on('newmessage', (data) => newMsg(data, socket))

  socket.on('connect', (data) => connect(data, socket))

  socket.on('updateMatch', (data) => updateMatch(data, socket))

  socket.on('sendLike', (data) => userLike(data, socket))

  socket.on('sendBlock', (data) => userBlock(data, socket))

  socket.on('sendReport', (data) => userReport(data, socket))

  socket.on('iStalkYou', (data) => notifStalk(data, socket))

}


function upDbMatch(user, me) {
  return new Promise((resolve, reject) => {
    User.selectLogin(user.login).then(resArray => {
      let test = _.pull(_.split(resArray[0].matchs, "/"), "")
      User.pullMatchs(test, "PUBLIC").then(res => {
        resolve({matchs:res, socketId: user.socketId})
      })
    })
    //  reject()
  })
}

const notifStalk = (data, socket) => {
  User.addNotif(data.target.profile.id, `${data.me.login} saw your profile.`, data.me).then(() => {
    User.pullMatchs([data.target.profile.id], "PRIVATE")
    .then(resPullMatchs => {
      let user = resPullMatchs[0]
      if (user.socketId) {
        const socketId = user.socketId
        io.to(socketId).emit('action', {
          type: 'server/newAction',
          data: {user: user},
        })
      }
    }).catch(e => {console.error(e);})
  })
}

const connect = (data, socket) => {
  socket.emit({
    type: 'connection',
    data: socket,
  })
}

const disconnected = (data, socket) => {
  let arrayOfPromise = []
  User.selectSocketId(socket.id).then(user => {
    if (user === 'selectSocketId ntm' || user[0].matchs.length === 0) { return }
    let mtc = user[0].matchs
    User.pullMatchs(mtc, 'PRIVATE').then(matchs => {
      if(matchs === 'listMatch empty') { return }
      matchs.forEach(e => arrayOfPromise.push(upDbMatch(e,user[0])))
      Promise.all(arrayOfPromise).then(resArray => {
        resArray.forEach(e => {
                e.matchs.forEach(t => {
          io.to(t.socketId).emit('action', {
            type: 'server/updateMatchS',
            data: {login: user[0].login, socketId: null},
          })
          })
        })
      })
    })
  }).catch(e => {
    console.log(e);
  })
}

const userLike = async (data, socket) => {
  try {
    let check = await User.pullMatchs([data.userID, data.targetID], "PRIVATE")
    if (check.length != 2) {
      console.error("error userLike ");
    } else {
      let login = check[0],
      target = check[1]
      if (login.id != data.userID){
        login = check[1]
        target = check[0]
      }
      let arrayOfPromise = [],
      index = login.mylike.indexOf(target.id)

      if (index === -1){
        login.mylike.push(target.id)
        target.liked.push(login.id)
        target.popularity = target.popularity + 5
        arrayOfPromise.push(User.modifProfile({popularity: target.popularity},target.login))
        arrayOfPromise.push(User.addNotif(target.id, `${login.login} just like you`, login))
        arrayOfPromise.push(User.modifTabInDb(login.id, 'mylike', login.mylike))
        arrayOfPromise.push(User.modifTabInDb(target.id, 'liked', target.liked))
        if (target.mylike.indexOf(login.id) !== -1) {
          login.matchs.push(target.id)
          target.matchs.push(login.id)
          arrayOfPromise.push(User.modifTabInDb(login.id, 'matchs', login.matchs))
          arrayOfPromise.push(User.modifTabInDb(target.id, 'matchs', target.matchs))
          arrayOfPromise.push(User.addNotif(target.id, `${login.login} match with you`, login))
          arrayOfPromise.push(User.addNotif(login.id, `${target.login} match with you`, target))
        }
      } else {
        login.mylike.splice(index, 1)
        target.liked = _.pull(target.liked, login.id)
        target.popularity = target.popularity <= 0 ? 0 : target.popularity - 5
        arrayOfPromise.push(User.modifProfile({popularity: target.popularity},target.login))
        arrayOfPromise.push(User.modifTabInDb(login.id, 'mylike', login.mylike))
        arrayOfPromise.push(User.modifTabInDb(target.id, 'liked', target.liked))
        arrayOfPromise.push(User.addNotif(target.id, `${login.login} dislike you`, login))
        index = target.matchs.indexOf(login.id)
        if (index !== -1) {
          login.matchs = _.remove(login.matchs, (e) => { return e.id !== target.id })
          login.matchs = _.pull(login.matchs, target.id)
          target.matchs.splice(index, 1)
          arrayOfPromise.push(User.modifTabInDb(login.id, 'matchs', login.matchs))
          arrayOfPromise.push(User.modifTabInDb(target.id, 'matchs', target.matchs))
        }
      }
      Promise.all(arrayOfPromise)
      .then( async () => {
        let resPullMatchs = await User.pullMatchs([data.userID, data.targetID], "PRIVATE")
        let user = resPullMatchs[0]
        let target = resPullMatchs[1]
        if (data.userID != user.id){
          target = user
          user = resPullMatchs[1]
        }
        let dist = null
        if (user.socketId) {
          let dataMatchs = await User.pullMatchs(user.matchs, "PUBLIC")
          let otherUser = await User.pullAUser(target.id)
          dist = User.localisation((Math.PI * user.latitude)/180, (Math.PI * user.longitude)/180, (Math.PI * target.latitude)/180, (Math.PI * target.longitude)/180)
          otherUser.localisation = dist
          const UserSocketId = user.socketId
          io.to(UserSocketId).emit('action', {
            type: 'server/newAction',
            data: {user: user, other_User: otherUser, matchs: dataMatchs, key: data.key}
          })
        }
        if (target.socketId) {
          let dataMatchs = await User.pullMatchs(target.matchs, "PUBLIC")
          let otherUser = await User.pullAUser(user.id)
          otherUser.localisation = dist
          const TargetSocketId = target.socketId
          io.to(TargetSocketId).emit('action', {
            type: 'server/newAction',
            data: {user: target, other_User: otherUser, matchs: dataMatchs, key: data.key}
          })
        }
      }).catch(error => {console.error(error);})
    }
  } catch(e) {
    console.error(e);
  }
}

const userBlock = async (data, socket) => {
  try {
    let check = await User.pullMatchs([data.userID, data.targetID], "PRIVATE")
    if (check.length != 2) {
      console.error("error userLike ");
    } else {
      let login = check[0],
      target = check[1]
      if (login.id != data.userID){
        login = check[1]
        target = check[0]
      }
      let arrayOfPromise = [],
      index = login.myblock.indexOf(target.id)

      if (index === -1){
        login.myblock.push(target.id)
        target.blocked.push(login.id)
        target.popularity = (target.popularity - 10) <= 0 ? 0 : target.popularity - 10
        arrayOfPromise.push(User.modifProfile({popularity: target.popularity},target.login))
        arrayOfPromise.push(User.modifTabInDb(login.id, 'myblock', login.myblock))
        arrayOfPromise.push(User.modifTabInDb(target.id, 'blocked', target.blocked))
        arrayOfPromise.push(User.addNotif(login.id, `you have block ${target.login}`,target))
        index = target.matchs.indexOf(login.id)
        if (index != -1) {
          target.matchs.splice(index, 1)
          target.mylike = _.pull(target.mylike, login.id)
          target.liked = _.pull(target.liked, login.id)
          login.matchs = _.pull(login.matchs, target.id)
          login.mylike = _.pull(login.mylike, target.id)
          login.liked = _.pull(login.liked, target.id)
          arrayOfPromise.push(User.modifTabInDb(login.id, 'matchs', login.matchs))
          arrayOfPromise.push(User.modifTabInDb(login.id, 'mylike', login.mylike))
          arrayOfPromise.push(User.modifTabInDb(login.id, 'liked', login.liked))
          arrayOfPromise.push(User.modifTabInDb(target.id, 'matchs', target.matchs))
          arrayOfPromise.push(User.modifTabInDb(target.id, 'mylike', target.mylike))
          arrayOfPromise.push(User.modifTabInDb(target.id, 'liked', target.liked))
        }
      } else {
        login.myblock.splice(index, 1)
        target.blocked = _.pull(target.blocked, login.id)
        arrayOfPromise.push(User.modifProfile({popularity: target.popularity}, target.login))
        arrayOfPromise.push(User.modifTabInDb(login.id, 'myblock', login.myblock))
        arrayOfPromise.push(User.modifTabInDb(target.id, 'blocked', target.blocked))
      }
      Promise.all(arrayOfPromise)
      .then(async () => {
        let resPullMatchs = await User.pullMatchs([data.userID, data.targetID], "PRIVATE")
          let user = resPullMatchs[0]
          let target = resPullMatchs[1]

          if (user.id != data.userID){
            user = target
            target = resPullMatchs[0]
          }
          let dist = null
          if (user.socketId) {
            let dataMatchs = await User.pullMatchs(user.matchs, "PUBLIC")
            let otherUser = await User.pullAUser(target.id)
              dist = User.localisation((Math.PI * user.latitude)/180, (Math.PI * user.longitude)/180, (Math.PI * target.latitude)/180, (Math.PI * target.longitude)/180)
              otherUser.localisation = dist
              const socketId = user.socketId
              io.to(socketId).emit('action', {
                type: 'server/newAction',
                data: { user: user, other_User: otherUser,  matchs: dataMatchs, key: data.key },
              })
          }
          if (target.socketId) {
            let dataMatchs = await User.pullMatchs(target.matchs, "PUBLIC")
            let otherUser = await User.pullAUser(user.id)
            otherUser.localisation = dist
              const socketId = target.socketId
              io.to(socketId).emit('action', {
                type: 'server/newBlock',
                data: { user: target, other_User: otherUser,  matchs: dataMatchs},
              })
          }
      }).catch(error => { console.error(error) })
    }
  } catch(e) {
    console.error(e);
  }
}

const userReport = async (data, socket) => {
  try {
    let check = await User.pullMatchs([data.userID, data.targetID], "PRIVATE")
    if (check.length != 2) {
      console.error("error userLike ");
    } else {
      let login = check[0],
      target = check[1]
      if (login.id != data.userID){
        login = check[1]
        target = check[0]
      }
      let arrayOfPromise = [],
      index = target.usr_report.indexOf(login.id)

      if (index === -1){
        target.usr_report.push(login.id)
        target.report = target.report - 1
        arrayOfPromise.push(User.modifProfile({report: target.report}, target.login))
        arrayOfPromise.push(User.modifTabInDb(target.id, 'usr_report', target.usr_report))
        arrayOfPromise.push(User.addNotif(login.id, `you have report ${target.login} thank you`, target))
        if (!target.report) {
          arrayOfPromise.push(User.modifProfile({token: "YOU_ARE_BANNED_BITCH"}, target.login))
          arrayOfPromise.push(User.modifProfile({status: 2}, target.login))
        }
      } else {
        target.usr_report.splice(index, 1)
        arrayOfPromise.push(User.modifProfile({report: target.report + 1}, target.login))
        arrayOfPromise.push(User.modifTabInDb(target.id, 'usr_report', target.usr_report))
      }
      Promise.all(arrayOfPromise)
      .then(async () => {
        let dataTarget = await User.pullAUser(data.targetID)
        if (login.socketId) {
          const socketId = login.socketId
          io.to(socketId).emit('action', {
            type: 'server/newAction',
            data: {target: dataTarget, key: data.key},
          })
        }
      }).catch(error => {console.error(error);})
    }
  } catch(e) {
    console.error(e);
  }
}

const newMsg = (data, socket) => {
  if (data.message) {
    let idS = [data.chat.sender.id, data.chat.reciver.id]
    con.query(`SELECT * FROM chats WHERE user1 IN (${idS}) AND  user2 IN (${idS})`, (err1, result) => {
      if (err1) {
        console.error("message -> ", err1);
      }
      let date = new Date()
      date = moment(date).format('YYYY-MM-DD HH:mm:ss')
      if (result && result.length === 1) {
        let newMessages = result[0].messages
        newMessages.push({senderId: idS[0], reciverId: idS[1], message: data.message, date: date})
        newMessages = JSON.stringify(newMessages)
        con.query(`UPDATE chats SET messages=? WHERE id=?`, [newMessages, result[0].id], (err2, result) => {
          if (err2){
            console.error("update chats -> message => ", err2)
          }
        })
      } else {
        con.query(`INSERT INTO chats (user1, user2, messages) VALUES(?,?,?)`, [idS[0], idS[1], JSON.stringify([{senderId: idS[0], reciverId: idS[1], message: data.message, date: date}])], (err3, result) => {
          if (err3) {
            console.error(`INSERT INTO chats -> `,err3);
          }
        })
      }
    })
  }
  if (data.chat) {
    const socketId = data.chat.reciver.socketId
    io.to(socketId).emit('action', {
      type: 'server/newMsg',
      data: { sender: data.chat.sender, reciver: data.chat.reciver, message: data.message },
    })
  }
}

function upDbMatch(login, user) {
  return new Promise((resolve, reject) => {
    User.selectLogin(user.login).then(resArray => {
      let test = _.pull(_.split(resArray[0].matchs, "/"), "")
      User.pullMatchs(test, "PUBLIC").then(res => {
        resolve({matchs:res, socketId: user.socketId})
      })
    })
    //  reject()
  })
}

const updateMatch = (data, socket) => {
  let arrayOfPromise = []
  if (!data.matchs) { return }
  data.matchs.forEach(e => arrayOfPromise.push(upDbMatch(e,data.me)))
  Promise.all(arrayOfPromise).then(resArray => {
    resArray.forEach(e => {
      e.matchs.forEach(t => {
        io.to(t.socketId).emit('action', {
          type: 'server/updateMatchS',
          data: data.me,
        })
      })
    })
  }).catch(e => {
    console.error(e);
  })
}
