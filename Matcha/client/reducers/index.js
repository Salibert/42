import { fromJS, toJS } from 'immutable'
import { cookieLogin, cookieLogout } from '../service/cookies.service.js'
import moment from 'moment'
const intialState = fromJS({
  keyHome: null,
  data_user: null,
  statusButton: false,
  message_system: null,
  openChat: [],
  socketId: null,
  shouldUpdate: true,
  toasterMessage: '',
  dataNotifModal: null
})

const reducer = (state = intialState, action) => {

  const data = null

  switch (action.type) {
    case 'client/connect':
    return state.set('socketId', fromJS(action.data))
    case 'client/stopUpdate':
    return state.set('shouldUpdate', fromJS(action.data))
    case 'client/resetCookies':
    return
    case 'client/addToster':
    return state.set('toasterMessage', fromJS(action.message))
    case 'client/closeToster':
    return state.set('toasterMessage', fromJS(''))
    case 'server/resetState':
    return state.setIn(['data_user'], fromJS(action.data))
    case 'client/successLogin':
    cookieLogin(action.data)
    return state.setIn(['data_user'], fromJS(action.data))
    case 'client/signOut':
    cookieLogout()
    return state.setIn(['session'], null)
    case 'server/addMessages':
    if(action.data.length === 0) { return state }
    const conv = state.get('openChat').toJS()
    let idxC = state.get('openChat').toJS().findIndex(c => c.reciver.id === action.data.messages[0].reciverId && c.sender.id === action.data.messages[0].senderId)
    if(idxC === -1) {idxC = state.get('openChat').toJS().findIndex(c => c.reciver.id === action.data.messages[0].senderId && c.sender.id === action.data.messages[0].reciverId) }
    if(idxC === -1) {return state}
    const tmpC = {
      sender: conv[idxC].sender,
      reciver: conv[idxC].reciver,
      message: action.data.messages,
    }
    return state.updateIn(['openChat'], arr => arr.splice(idxC, 1, tmpC))
    case 'client/filterByTags':
    const user = state.get('data_user').toJS()
    let otherUser = state.get('other_User')
    if (!otherUser || !user || !user.tags) { return state }
    otherUser = otherUser.toJS()
    user.tags.forEach(meTag => {
      otherUser.data.forEach(oneUser => {
        if (!oneUser.grade) { oneUser.grade = 0 }
        if (oneUser.tags) { oneUser.tags.forEach(yTag => { if(yTag === meTag) { oneUser.grade++ } }) }
      })
    })
    if (action.data.value === 2) { otherUser.data = otherUser.data.sort((a,b) => a.grade - b.grade) } else { otherUser.data = otherUser.data.sort((a,b) => b.grade - a.grade) }
    return state.setIn(['other_User'], fromJS(otherUser))
    case 'client/filterByAge':
    let otherUser1 = state.get('other_User')
    if (!otherUser1) { return state }
    otherUser1 = otherUser1.toJS()
    if (action.data.value === 2) { otherUser1.data = otherUser1.data.sort((a,b) => moment(a.birthdate) - moment(b.birthdate)) } else { otherUser1.data = otherUser1.data.sort((a,b) => moment(b.birthdate) - moment(a.birthdate)) }
    return state.setIn(['other_User'], fromJS(otherUser1))
    case 'client/filterByDistance':
    let otherUser2 = state.get('other_User')
    if (!otherUser2) { return state }
    otherUser2 = otherUser2.toJS()
    if (action.data.value === 2) { otherUser2.data = otherUser2.data.sort((a,b) => a.localisation - b.localisation) } else { otherUser2.data = otherUser2.data.sort((a,b) => b.localisation - a.localisation) }
    return state.setIn(['other_User'], fromJS(otherUser2))
    case 'client/setNotifModal':
    return state.setIn(['dataNotifModal'], fromJS(action.data))
    case 'client/filterByPopularity':
    let otherUser3 = state.get('other_User')
    if (!otherUser3) { return state }
    otherUser3 = otherUser3.toJS()
    if (action.data.value === 2) { otherUser3.data = otherUser3.data.sort((a,b) => a.popularity - b.popularity) } else { otherUser3.data = otherUser3.data.sort((a,b) => b.popularity - a.popularity) }
    return state.setIn(['other_User'], fromJS(otherUser3))
    case 'client/updatemessage_system':
    return state.setIn(['message_system'], fromJS(action.data))
    case 'server/updateUser':
    return state.setIn(['data_user'], fromJS(action.data.data))
    case 'server/pullUser':
    return state.setIn(['other_User'], fromJS(action.data))
    case 'client/cleanUser':
    return state.setIn(['other_User'], fromJS(null))
    case 'client/statusButton':
    return state.setIn(['statusButton'], fromJS(action.data))
    case 'server/matchs':
    return state.setIn(['matchs'], fromJS(action.data))
    case 'server/updateMatchS':
    let mat = state.get('matchs')
    if (mat === "listMatch empty") { return states }
    mat = mat.toJS()
    const idx2 = state.get('matchs').toJS().findIndex(c => c.login === action.data.login)
    mat[idx2].socketId = action.data.socketId
    return state.setIn(['matchs'], fromJS(mat))
    case 'server/newMatch':
    let obj1 = state.get('openChat')
    if (!obj1) { return state }
    obj1 = obj1.toJS()
    if (!obj1.length) {
      return state.setIn(['matchs'], fromJS(action.data))
    }
    obj1.forEach((c, index) => {
      action.data.forEach(a => {
        if (c.reciver.id === a.id) {
          obj1[index].reciver = a
        }
      })
    })
    state.setIn(['matchs'], fromJS(action.data))
    state.setIn(['openChat'], fromJS(obj1))
    return state
    case 'server/UploadPicture':
    return state.setIn(['data_user'], fromJS(action.data))
    case 'server/updateNotife':
    return state.setIn(['data_user'], fromJS(action.data))
    case 'client/updateTarget':
    return state.setIn(['other_User'], fromJS(action.data))
    case 'client/openChat':
    const idx = state.get('openChat').toJS().findIndex(c => c.sender.id === action.data.sender.id && c.reciver.id === action.data.reciver.id)
    if (idx != -1) { return state }
    return state.updateIn(['openChat'], arr => arr.push(fromJS(action.data)))
    case 'client/closeChat':
    const index = state.get('openChat').toJS().findIndex(c => c.sender.id === action.data.sender.id && c.reciver.id === action.data.reciver.id)
    return state.updateIn(['openChat'], arr => arr.splice(index, 1))
    case 'client/addMessage':
    const index1 = state.get('openChat').toJS().findIndex(c => c.sender.id === action.data.sender.id && c.reciver.id === action.data.reciver.id)
    const tmp = state.get('openChat').toJS()[index1]
    if (!tmp.message) { tmp.message = [{ reciverId: action.data.reciver.id, senderId: action.data.sender.id, message: action.data.message }] } else { tmp.message.push({ reciverId: action.data.reciver.id, senderId: action.data.sender.id, message: action.data.message }) }
    return state.updateIn(['openChat'], arr => arr.splice(index1, 1, tmp))
    case 'server/newNotif':
    const notif = state.getIn(['data_user']).toJS()
    notif.notif = action.data
    return state.setIn(['data_user'], fromJS(notif))
    case 'server/newAction':
    if (action.data.user && action.data.matchs) {
      let other_User = state.get('other_User').toJS()
      let likeUser = other_User.data.findIndex(c => c.id === action.data.other_User.id)
      if (likeUser != -1){
        other_User.data[likeUser] = action.data.other_User
        return  state.setIn(['matchs'], fromJS(action.data.matchs)).setIn(['data_user'], fromJS(action.data.user)).setIn(['other_User'], fromJS(other_User))
      }
      other_User.data.push(action.data.other_User)
      return state.setIn(['matchs'], fromJS(action.data.matchs)).setIn(['data_user'], fromJS(action.data.user)).setIn(['other_User'], fromJS(other_User))
    } else if (action.data.user) { console.log("LA"); return  state.setIn(['data_user'], fromJS(action.data.user)) }
    const target = state.get('other_User').toJS()
    target.data[action.data.key] = action.data.target
    return state.setIn(['other_User'], fromJS(target))
    case 'server/newBlock':
      window.location.reload()
      let otherUser4 = state.get('other_User').toJS()
      let blockUser = otherUser4.data.findIndex(c => c.id === action.data.other_User.id)
      if (blockUser != -1){
        return state.updateIn(['other_User', 'data'], arr => arr.splice(blockUser, 1)).setIn(['matchs'], fromJS(action.data.matchs)).setIn(['data_user'], fromJS(action.data.user))
      }
      return state.updateIn(['other_User', 'data'], arr => arr.push(action.data.other_User)).setIn(['matchs'], fromJS(action.data.matchs)).setIn(['data_user'], fromJS(action.data.user))
    case 'server/newMsg':
    const obj = state.get('openChat').toJS()
    if (!obj) { return state }
    if (!action.data.reciver) { return state }
    const index2 = obj.findIndex(c => c.sender.id === action.data.reciver.id && c.reciver.id === action.data.sender.id)
    const tmp1 = state.get('openChat').toJS()[index2]
    if (index2 === -1) {
      const newObject = {
        sender: action.data.reciver,
        reciver: action.data.sender,
        message: [{ reciverId: action.data.reciver.id, senderId: action.data.sender.id, message: action.data.message }],
      }
      return state.updateIn(['openChat'], arr => arr.push(fromJS(newObject)))
    }
    if (!tmp1.message) { tmp1.message = [{ reciverId: action.data.reciver.id, senderId: action.data.sender.id, message: action.data.message }] } else { tmp1.message.push({ reciverId: action.data.reciver.id, senderId: action.data.sender.id, message: action.data.message }) }
    return state.updateIn(['openChat'], arr => arr.splice(index2, 1, tmp1))
    // cherche un chat ouver sinon en ouvrire un

    default:
    return state
  }
}

export default reducer
