import moment from 'moment'
import { callApi } from '../../service/apiCaller.js'
import { getCookie } from '../../service/cookies.service.js'
import { closeToster, addToster } from '../Toaster/index.js'
import { Cookies } from 'react-cookie'

export function userUpdate (data) {
  return {
    type: 'server/updateUser',
    data,
  }
}

export function targetUpdate (data) {
  return {
    type: 'server/targetUpdate',
    data,
  }
}

export function userPull (data) {
  return {
    type: 'server/pullUser',
    data,
  }
}

export function matchsPull (data) {
  return {
    type: 'server/matchsPull',
    data,
  }
}

export function stateCheck (data) {
  return {
    type: 'server/resetState',
    data,
  }
}

export function matchs (data) {
  return {
    type: 'server/matchs',
    data,
  }
}

export function pictureUpload (data) {
  return {
    type: 'server/UploadPicture',
    data,
  }
}

export function successLogin (data) {
  return {
    type: 'client/successLogin',
    data,
  }
}

export function userDisconnet () {
  return {
    type: 'server/disconnect',
    data: {},
  }
}
export function cleanUser () {
  return {
    type: 'client/cleanUser',
    data: {},
  }
}
export function filterByTags (value) {
  return  {
    type: 'client/filterByTags',
    data: {value:value},
  }
}
export function filterByAge (value) {
  return  {
    type: 'client/filterByAge',
    data: {value:value},
  }
}

export function filterByDistance (value) {
  return  {
    type: 'client/filterByDistance',
    data: {value:value},
  }
}


export function filterByPopularity (value) {
  return  {
    type: 'client/filterByPopularity',
    data: {value:value},
  }
}

export function actifAccount (id, token) {
  return dispatch => {
    callApi(`usr/ActifAccount/${id}/${token}`, 'get').then(res => {
      let login = res.data.login
      let password = res.data.password
      callApi(`usr/auth/${login}`, 'post', {password}).then(res => {
        dispatch(successLogin(res.data))
        dispatch(addToster(res.message))
      }).catch(e => {
        dispatch(addToster(e))
      })
    }).catch(e => {
      dispatch(addToster(e))
    })
  }
}

export function requestSignIn (login, password) {
  return dispatch => {
    callApi(`usr/auth/${login}`, 'post', { password }).then(res => {
      dispatch(successLogin(res.data))
      dispatch(addToster(res.message))
    }).catch(e => {
      dispatch(addToster(e))
    })
  }

}

export function checkState (dataUser) {
  return dispatch => {
      callApi(`usr/auth/${dataUser.login}`, 'post', { password: dataUser.password }).then(body => {
          dispatch(stateCheck(body.data))
          dispatch({type: 'super/connect'})
      }).catch(e => {
        if(e === 'password invalid') {
          const cookies = new Cookies()
          cookies.remove('you')
          dispatch(userDisconnet())
          dispatch(addToster('password invalid pls reconnect'))
            window.location.reload()
        } else {

          dispatch(addToster(e))
        }
      })
    }
  }

export function updateUser (login, data, pos) {

  let tmp = null
  if (data.birthdate) {
    tmp = moment(data.birthdate).format('YYYY-MM-DD HH:mm:ss')
  }
  const objectReq = {
    firstname: data.firstname,
    lastname: data.lastname,
    email: data.email,
    gender: data.gender,
    birthdate: tmp,
    tags: data.tags,
    sizezone: data.sizezone,
    bio: data.biographie,
    password: data.password,
    longitude: pos.lng,
    latitude: pos.lat,
  }
  return dispatch => {
    callApi(`usr/${login}/modif`, 'post', objectReq).then(body => {
      dispatch(userUpdate(body))
      dispatch(addToster(body.statusMessage))
    }).catch(e => {
      dispatch(addToster(e))
    })
  }
}

export function updateMatch (login, socketId, matchs) {
  const m =  matchs.filter(e => e.socketId && e.login != login)
  return dispatch => {
    dispatch({
      type: 'server/updateMatch',
      data: { matchs: matchs.filter(e => e.socketId && e.login != login), me: { login, socketId } },
    })
    dispatch({ type: 'client/stopUpdate', data: false })
  }
}
export function updateSocket (login, socketId, matchs) {
  const socketsId = matchs
  return dispatch => {
    callApi(`usr/${login}/modif`, 'post', { socketId }).then(body => {
      dispatch(userUpdate(body))
    }).catch(e => {
      dispatch(addToster(e))
    })
  }
}
export function pullMatchs (id, data) {
  return dispatch => {
    callApi(`usr/pullMatchs/${id}`, 'post', data).then(body => {
      dispatch(matchs(body.data))
    }).catch(e => {
      dispatch(addToster(e))
    })
  }
}

export function pullUser (filtre, id) {
  return dispatch => {
    callApi(`match/filtre/${id}`, 'post', filtre).then(body => {
      dispatch(userPull(body))
    }).catch(e => {
      dispatch(userPull(null))
      dispatch(addToster(e))
    })
  }
}

export function uploadPicture (login, index, infoPicture) {
  return dispatch => {
    callApi(`usr/uploadPicture/${login}/${index}`, 'image', infoPicture).then(body => {
      dispatch(pictureUpload(body.data))
    }).catch(e => {
      dispatch(addToster(e))
    })
  }
}
