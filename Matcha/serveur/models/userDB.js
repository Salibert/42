import async from 'async'
import SHA from 'sha1'
import { con } from '../config/connect'
import { configMail } from '../config/config'
import _ from 'lodash'
import dif from 'array-difference'
import each from 'each'
import moment from 'moment'

let msg = ""
let sendmail = require('sendmail')()

con.connect((err) => {
  if (err)
  console.error('error connect : ', err)
})

const User = {

  existMail: (email) => {
    return new Promise((resolve, reject) => {
      con.query(`SELECT * FROM users WHERE email=?`, [email], (error, result) => {
        if (error){
          return reject(error)
        }
        if (result.length != 0) {
          resolve(true)
        } else {
          resolve(false)
        }
      })
    })
  },

  existLogin: (login) => {
    return new Promise((resolve, reject) => {
      con.query(`SELECT * FROM users WHERE login=?`, [login], (error, result) => {
        if (error){
          return reject(error)
        }
        if (result.length != 0) {
          resolve(true)
        } else {
          resolve(false)
        }
      })
    })
  },

  existInDB: (table, columb, data, cb) => {
    let sql = 'SELECT * FROM '+table+' WHERE '+columb+'=?'
    con.query(sql, [data], (error, result) => {
      if (result[0]) {
        cb(error, result[0])
      }
      else {
        cb(error, null)
      }
    })
  },

  selectMail: (email) => {
    return new Promise((resolve, reject) => {
      con.query(`SELECT * FROM users WHERE email=?`, [email], (error, result) => {
        if (error){
          throw error
        }
        if (result.length === 1) {
          resolve(result)
        } else {
          reject("User not Found")
        }
      })
    })
  },

  selectLogin: (login) => {
    return new Promise((resolve, reject) => {
      con.query('SELECT * FROM users WHERE login=?', [login], (error, result) => {
        if (error){
          throw error
        }
        let length = result.length
        if (length === 1) {
          return resolve(result)
        } else {
          return reject(`selectLogin have found ${length}`)
        }
      })
    })
  },

  selectSocketId: (socketId) => {
    return new Promise((resolve, reject) => {
      con.query('SELECT * FROM users WHERE socketId=?', [socketId], (error, result) => {
        let date = new Date()
        date = moment(date).format('YYYY-MM-DD HH:mm:ss')
        con.query('UPDATE users SET socketId=null, reg_date=? WHERE socketId=?',[date,socketId], err => {
          if (error || err) { throw error }

          let length = result.length
          if (length === 1) {
            result[0].socketId = null
            return resolve(result)
          } else {
            return resolve(`selectSocketId ntm`)
          }
        })
      })
    })
  },

  modifNotif: (data, login) => {
    return new Promise((resolve, reject) => {
      con.query('SELECT * FROM users WHERE login=?', [login], (error, result) => {
        const newTab = _.remove(result[0].notif, (e) => { return e.date !== data.date })
         con.query('UPDATE users SET notif=? WHERE login=?',[JSON.stringify(newTab),login], err => {
           if (error || err) { throw error }
           let length = result.length
           if (length === 1) {
             result[0].notif = newTab
             return resolve(result)
           } else {
             return reject(`login have found ${length}`)
           }
         })
      })
    })
  },

  whoami: (login, password) => {
    return new Promise((resolve, reject) => {
      con.query(`SELECT * FROM users WHERE login=?`, [login], (error, result) => {
        if (error){
          throw error
        }
        let msg = ''
        if (result.length === 0) {
          msg = "login is invalid"
          return reject(msg)
        }
        result = result[0]
        if (result.password != password) {
          msg = "password invalid"
          return reject(msg)
        }
        if (!result.status){
          if (result.token === 'YOU_ARE_BANNED_BITCH'){
            msg = 'REVIEN JAMAIS'
          } else {
            msg = "please valid your account"
          }
          return reject(msg)
        } else {
          result.tags = _.pull(_.split(result.tags , "/"), "")
          resolve(result)
        }
      })
    })
  },

  modifProfile: (usr, login) => {
    return new Promise( async (resolve, reject) => {
      try {
        let msg = ""
        let success = await User.selectLogin(login)
        let data_usr  = Object.values(usr),
        keys_usr = Object.keys(usr),
        index = keys_usr.indexOf('tags')

        if (index != -1){
          let tags = usr.tags
          usr.tags = usr.tags.toString()
          data_usr[index] = `/${usr.tags.replace(/,/g, '/')}`
          User.controleNewTag(tags, success[0])
        }
        index = keys_usr.indexOf('login')
        if (index > -1){
          data_usr.splice(index, 1)
          keys_usr.splice(index, 1)
        }
        index = keys_usr.indexOf('password')
        if (index > -1) {
          data_usr[index] = SHA(usr.password)
        }
        index = keys_usr.indexOf('birthdate')
        if (index != -1 && !usr.birthdate){
          data_usr[index] = success[0].birthdate
        }
        index = keys_usr.indexOf('email')
        if (index > -1 && success[0].email != usr.email) {
          User.existMail(usr.email).then(data => {
            if (data === true) { return reject( "Email you want is already in use ") }
          }).catch(e => { return reject(e) })
        }
        let sql = "UPDATE `users` SET "
        for (let i = 0; i < keys_usr.length; i++) {
          let string = JSON.stringify(keys_usr[i])
          sql += string + " = ? "
          if (i != (keys_usr.length - 1))
          sql += ", "
        }
        sql += "WHERE login = ?"
        sql = sql.replace(/"/g, '`')
        data_usr.push(login)
        con.query(sql, data_usr, async (error, result) => {
          if (error){
            console.error(error);
            reject(error.code)
          } else {
            let data = await User.selectLogin(login)
            data = data[0]
            msg = `${data.login} your profile is update`
            data.tags = _.pull(_.split(data.tags , "/"), "")
            resolve([data, msg])
          }
        })
      } catch(e){
        console.error(e);
        reject(e)
      }
    })
  },

  createUser: (usr) => {
    return new Promise( async (resolve, reject) => {
      try {
        await User.parserUser(usr)
      } catch(e){
        console.error(e);
        return reject(e)
      }
      let arrayOfPromise = [User.existLogin(usr.login), User.existMail(usr.email)]
      Promise.all(arrayOfPromise)
      .then(values => {
        let msg = null

        if (values[0] || values[1]){
          if (values[0]) {
            msg = "login is used, change please"
          }
          if (values[1]) {
            msg = msg ? `${msg} and email is used, change please` : `email is used, change please`
          }
          return reject(msg)
        }
        usr.token = SHA(new Date())
        usr.password = SHA(usr.password)
        User.helpUser(usr.email, 'CreateUser', usr)
        .then(data => {
          con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report)
          VALUES( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)`,
          [usr.login, usr.firstname, usr.lastname, usr.email, usr.password, usr.token, '/','[]','[]','[]','[]','[]','[]','[]'], (err) => {
            if (err) {
              console.error('error createUser', err)
              return reject(err)
            }
              msg = "WELCOME TO MATCHA, please check your mail for activate your account"
              return resolve(msg)
            })
        }).catch(e => { return reject(e) })
      }).catch(reason => { return reject(reason) })
    })
  },

  helpUser: (email, action, usr) => {
    return new Promise((resolve, reject) => {
      if (action && action != 'ValideAccount' && action != 'ForgetMyPassword' && action != 'CreateUser'){
        return reject('url invalid')
      }
      if (action === 'CreateUser') {
        action = 'ValideAccount'
          sendmail({
            from: 'AssistanceMatcha@gmail.com',
            to: `${email}`,
            subject: 'Assistance MATCHA ',
            html: `<p align="center" > Welcome ${usr.login} <a href="http://localhost:5001/${action}?id=${usr.id}&token=${usr.token}">Validate my account</a></p>`,
          }, (err, reply) => {
            if (err) { return reject('This email is unvalid') }
            resolve(reply)
          });
      } else {
        con.query(`SELECT * FROM users WHERE email=?`, [email], (error, result) => {
          if (error) { return reject(error) }
          if(result.length === 1){
            result = result[0]
            if (result.token === 'YOU_ARE_BANNED_BITCH') {
              return reject("Your are banned sorry")
            } else {
              result.token = SHA(new Date())
              con.query(`UPDATE users SET token=? WHERE id=?`, [result.token, result.id], (error) => {
                if (error) {
                  return reject(error)
                }
              })
            }
            sendmail({
              from: 'AssistanceMatcha@gmail.com',
              to: `${email}`,
              subject: 'Assistance MATCHA ',
              html: `<p align="center" > Welcome ${result.login} <a href="http://localhost:5001/${action}?id=${result.id}&token=${result.token}">Validate my account</a></p>`,
            }, (err, reply) => {
              if (err) { return reject(err) }
              resolve(reply)
            });
          } else { return reject('sorry contact assistance please') }
        })
      }
    })
  },

  checkSexe: (id) => {
    return new Promise((resolve, reject) => {
      if (!id) {
        return reject("id undefined")
      }
      con.query("SELECT gender FROM users WHERE id=?", [id], (error, result) => {
        if (error) {
          return reject(error)
        }
        resolve(result[0])
      })
    })
  },

  filtre: (filtre, id) => {
    return new Promise( async (resolve, reject) => {
      let gender = null
      let date = new Date()
      let targetsexe = null
      let age = `AND birthdate <=`
      let fields = `id, login, firstname, lastname, birthdate, localisation, gender, targetsexe, popularity, image1, image2, image3, image4, image5, bio, tags, usr_report, mylike, longitude, latitude`
      let sql = null
      let popularity = ` AND popularity >= 0`
      let token = ''

      if (filtre.blocked){
        filtre.blocked.push(id)
      } else {
        filtre.blocked = [id]
      }
      let blocked = ` id NOT IN (${filtre.blocked})`

      if (!filtre.myGender) {
        try {
          let tmp = await User.checkSexe(id)
          filtre.myGender = tmp.gender
        } catch(e){
          console.error(e);
          return reject(e)
        }
      }
      if (filtre.popularity) {
        popularity = ` AND popularity >= ${filtre.popularity}`
      }

      let tmp = !filtre.age ? 18 : filtre.age
      date.setFullYear(date.getFullYear() - tmp)
      date.setHours(0, 0, 0, 0)
      date = moment(date).format('YYYY-MM-DD HH:mm:ss')
      age = `${age} '${date}'`
      if (filtre.male && filtre.female) {
        targetsexe = 3
        sql = `SELECT ${fields} FROM users WHERE status='1' AND targetsexe IN (${filtre.myGender},3) ${age} AND ${blocked} ${popularity}`
      } else {
        if (filtre.male) {
          targetsexe = 1
          gender = filtre.myGender === 1 ? `gender = 1 AND targetsexe IN (1,3) AND` : `gender = 1 AND targetsexe IN (2,3) AND`
        } else if (filtre.female) {
          targetsexe = 2
          gender = filtre.myGender === 1 ? `gender = 2 AND targetsexe IN (1,3) AND` : `gender = 2 AND targetsexe IN (2,3) AND`
        }
      }
      if (gender){
        sql = `SELECT ${fields} FROM users WHERE status='1' AND ${gender} ${blocked} ${age} ${popularity}`
      }
      if (sql) {
        con.query(sql, (err, result) => {
          if (err){
            return reject(err)
          }
          let myResult = []
          let lat_user = (Math.PI * filtre.latitude) / 180
          let lon_user = (Math.PI * filtre.longitude) / 180
          result.forEach((value) => {
            if (value.image1 && value.latitude && value.longitude) {
              let lat_target = (Math.PI * value.latitude) / 180
              let lon_target = (Math.PI * value.longitude) / 180
              let unionTags = null

              value.localisation = User.localisation(lat_user, lon_user, lat_target, lon_target)
              value.tags = _.pull(_.split(value.tags , "/"), "")
              unionTags = _.intersection(filtre.myTags, value.tags)
              let communTags = unionTags.length
              if (( filtre.km === 150 || value.localisation <= filtre.km ) && filtre.tagValue <= communTags){
                value.communTags = communTags
                myResult.push(value)
              }
            }
          })
          resolve(myResult)
          if (targetsexe && filtre.latitude && filtre.longitude) {
            con.query(`UPDATE users SET targetsexe=?, latitude=?, longitude=? WHERE id=?`, [targetsexe, filtre.latitude, filtre.longitude, id], (err) => {
              if(err) {
                console.error(err);
              }
            })
          }
        })
      } else {
        reject("Not Found")
      }
    })
  },

  localisation: (lat_user, lon_user, lat_target, lon_target) => {
    let localisation = (6378000 * ((Math.PI/2 - Math.asin( Math.sin(lat_target) * Math.sin(lat_user) + Math.cos(lon_target - lon_user) * Math.cos(lat_target) * Math.cos(lat_user)))))
    localisation = Math.round(localisation / 1000)
    return localisation
  },

  pullMatchs: (listMatch, etat) => {
    return new Promise((resolve, reject) => {
      if (!listMatch.length){
        return resolve("listMatch empty")
      }
      let sql = `SELECT id, login, firstname, lastname, birthdate, localisation, gender, targetsexe, popularity, image1, image2, image3, image4, image5, bio, tags, socketId, mylike, usr_report, reg_date FROM users WHERE id IN (${listMatch})`
      if (etat === "PRIVATE") {
        sql = `SELECT * FROM users WHERE id IN (${listMatch})`
      }
      con.query(sql, (err, result) => {
        if (err) {
          console.error(err);
          return reject(err)
        }
        result.forEach((value) => { value.tags = _.pull(_.split(value.tags , "/"), "") })
        resolve(result)
      })
    })
  },

  pullMessages: (id) => {
    return new Promise((resolve, reject) => {
      let idS= [id.senderId, id.reciverId]
      con.query(`SELECT * FROM chats WHERE user1 IN (${idS}) AND  user2 IN (${idS})`, (error, result) => {
        if(error){
          return reject(error)
        }
        if (result.length) {
          return resolve(result[0])
        }
        resolve(result)
      })
    })
  },

  parserUser: (usr)  => {
    return new Promise((resolve, reject) => {
      if (usr.login && (usr.login.length < 6 || !usr.login.match(/[0-9]/g))) {
        return reject("login invalid")
      }
      if (usr.password && (usr.password.length < 7
        || usr.password.length > 18
        || !usr.password.match(/[0-9]/g)
        || usr.password.toLowerCase() === usr.password)) {
          return reject("password invalid")
        }
        resolve(false)
      })
    },

    controleNewTag: (new_tags, old_profile) => {
      let array_old_tags = _.split(old_profile.tags, "/")
      let array_dif = dif(new_tags, array_old_tags)
      if(array_dif.length){
        _.each(array_dif, (dif_tags) => {
          if (!dif_tags || dif_tags === '') {return}
          User.existInDB('all_tags', 'name_tags', dif_tags,(error, result) => {
            if (error) { throw error}
            if (result){
              if (result.list_users.indexOf(`/${old_profile.id}/`) == -1){
                result.list_users = `${result.list_users}${old_profile.id}/`
              } else {
                result.list_users = result.list_users.replace(`${old_profile.id}/`, "")
              }
              con.query('UPDATE all_tags SET list_users=? WHERE name_tags=?', [result.list_users, dif_tags], (error,result) => {
                if (error) throw error;
              })
            } else {
              con.query(`INSERT INTO all_tags (name_tags, list_users) VALUES(?,?)`, [dif_tags, `/${old_profile.id}/`], (error, result) => {
                if (error) throw error;
              })
            }
          })
        })
      }
    },

    actifAccount: (id, token) => {
      return new Promise((resolve, reject) => {
          con.query(`SELECT token, status, id FROM users WHERE token=?`, [token], (error, result) => {
            if (error){
              return rejet(error)
            }
            if (result.length){
              if (result.token === 'YOU_ARE_BANNED_BITCH') {
                return reject("Your are banned sorry")
              }
              if (!result[0].status) {
                if (result[0].token === token) {
                  con.query(`UPDATE users SET token=?, status=? WHERE id=?`, ['', '1', result[0].id], (error) => {
                    if (error) { return reject(error) }
                    con.query(`SELECT * FROM users WHERE id=?`, [result[0].id], (err, result) => {
                        if (err) { return reject(err)}
                        result = result[0]
                        return resolve(result)
                      })
                    })
                } else { return reject('token invalid')}
              } else {return reject('your account is already activated')}
            } else { return reject("token invalid") }
          })
      })
    },


        addNotif: (id, notif, user) => {
          return new Promise( async (resolve, reject) => {
            let sql = `SELECT * FROM users WHERE id=?`
            con.query(sql, [id], async (error, result) => {
              if (error) {
                console.error("addNotif -> ", error);
                return reject(error)
              }
              let date = new Date()
              date = moment(date).format('YYYY-MM-DD HH:mm:ss')
              if (result && result.length == 1){
                result = result[0]
                let newNotif = []
                if (result.notif) {
                  newNotif = result.notif
                  if (result.notif[0] && result.notif[0].message === notif){
                    return resolve(true)
                  }
                }
                let dataUser = null
                try {
                  user = await User.pullAUser(user.id)
                } catch(e) {
                  return reject(e)
                }
                newNotif.unshift({message: notif, vue: false, date: date, user })
                let notifDB = JSON.stringify(newNotif)
                con.query(`UPDATE users SET notif=? WHERE id=?`, [notifDB, id], (error) => {
                  if (error) {
                    return reject(error)
                  }
                  if (result.socketId) {
                    const socketId = result.socketId
                    io.to(socketId).emit('action', {
                      type: 'server/newNotif',
                      data: newNotif,
                    })
                  }
                  resolve(true)
                })
              } else {
                reject("error check db")
              }
            })
          })
        },


    modifTabInDb: (id, key, newElement) => {
      return new Promise((resolve, reject) => {
        let sql = `SELECT ${key} FROM users WHERE id=${id}`
        con.query(sql, (error, result) => {
          if (error) {
            return reject(error)
          }
          newElement = JSON.stringify(newElement)
          sql = `UPDATE users SET ${key}=? WHERE id=?`
          con.query(sql,[newElement, id], (err2) => {
            if (err2)
            return reject(err2)
          })
          resolve(true)
        })
      })
    },

    pullNotif: (id) => {
      return new Promise((resolve, reject) => {
        let sql = `SELECT notif FROM users WHERE id=?`
        con.query(sql, [id], (error, result) => {
          if (error){
            return reject(error)
          }
          resolve("result pullNotif => ",result)
        })
      })
    },

    pullAUser: (id) => {
      return new Promise((resolve, reject) => {
        con.query(`SELECT id, login, firstname, lastname, birthdate, localisation, gender, targetsexe, popularity, image1, image2, image3, image4, image5, bio, tags, socketId, mylike, usr_report, reg_date FROM users WHERE id=?`, [id], (error, result) => {
            if (error) {
              return reject(error)
            }
            result = result[0]
            result.tags = _.pull(_.split(result.tags , "/"), "")
            return resolve(result)
        })
      })
    },

    forgetMyPassword: (id, token, password) => {
      return new Promise( async (resolve, reject) => {
        if (Number.isInteger(Number(id))) {
          con.query(`SELECT token, password, status FROM users WHERE id=?`, [id], (error, result) => {
            if (error){
              return rejet(error)
            }
            if (result.length){
              if (result[0].status && result[0].token === token){
                con.query(`UPDATE users SET token=?, password=? WHERE id=?`, ['', password.password, id], (error) => {
                  if (error) { return reject(error) }
                  return resolve(true)
                })
              } else { return reject('token invalid')}
            } else { return reject("id invalid") }
          })
        } else { return reject("id format invalid") }
      })
    }
}

  module.exports = User
