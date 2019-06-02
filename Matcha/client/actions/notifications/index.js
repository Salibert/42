import moment from 'moment'
import { callApi } from '../../service/apiCaller.js'
import { getCookie } from '../../service/cookies.service.js'
import { closeToster, addToster } from '../Toaster/index.js'
import { statusModal } from '../Modal'

export function notifeUpdate (data) {
  return {
    type: 'server/updateNotife',
    data,
  }
}

export function setNotifModal (data) {
  return {
    type: 'client/setNotifModal',
    data
  }
}

export function updateNotife(login, data, status) {
  return dispatch => {
    if (status) {
      dispatch(setNotifModal(data))
      dispatch(statusModal(true))
    }
    callApi(`usr/${login}/notification/modif`, 'post', data).then(body => {
      dispatch(notifeUpdate(body.data))
    }).catch(e => {
      dispatch(addToster(e))
    })
  }
}

export function seeProfile(data) {
  return {
    type: 'server/iStalkYou',
    data
  }
}
