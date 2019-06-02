import moment from 'moment'
import { callApi } from '../../service/apiCaller.js'
import { closeToster, addToster } from '../Toaster/index.js'

export function openChat (data) {
  return {
    type: 'client/openChat',
    data,
  }
}

export function closeChat (data) {
  return {
    type: 'client/closeChat',
    data,
  }
}
export function addMessage (data) {
  return {
    type: 'client/addMessage',
    data,
  }
}
export function addMessages (data) {
  return {
    type: 'server/addMessages',
    data,
  }
}
export function send (chat, message) {
  return dispatch => {
    dispatch(addMessage({ sender: chat.sender, reciver: chat.reciver, message }))
    dispatch({
      type: 'server/newmessage',
      data: { chat, message },
    })
  }
}

export function getMessages (chat) {
  return dispatch => {
    callApi(`usr/getMessages/${chat.sender.id}/${chat.reciver.id}`, 'get')
      .then(data => {
        dispatch(addMessages(data))
      })
      .catch(err => {
        dispatch(addToster(err))
      })
  }
}
