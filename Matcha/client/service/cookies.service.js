import { Cookies } from 'react-cookie'
import { fromJS } from 'immutable'
import { requestSignIn } from './user.service.js'
import { createCipher, createDecipher } from 'crypto'

function cookieLogin (data) {
  const cookies = new Cookies()

  cookies.set('you', data.login)
  let cipher = createCipher('aes192', data.login),
    data_cookie = `id:${data.id}`,
    crypted = cipher.update(data_cookie, 'utf8', 'hex') + cipher.final('hex')
  cookies.set('bob', crypted)
  cipher = createCipher('aes192', data_cookie)
  data_cookie = `login:${data.login}//password:${data.password}`
  crypted = cipher.update(data_cookie, 'utf8', 'hex') + cipher.final('hex')
  cookies.set('patrick', crypted)
}

function getCookie () {
  return new Promise((resolve, reject) => {
    try {
      const cookie = new Cookies()
      if (!cookie.get('you') || !cookie.get('bob') || !cookie.get('patrick')) { reject({}) }
      let data = cookie.get('you')
      let decipher = createDecipher('aes192', data)
      data = decipher.update(cookie.get('bob'), 'hex', 'utf8') + decipher.final('utf8')
      decipher = createDecipher('aes192', data)
      data = decipher.update(cookie.get('patrick'), 'hex', 'utf8') + decipher.final('utf8')
      data = data.split('//')
      const obj_data = {
        login: data[0].replace('login:', ''),
        password: data[1].replace('password:', ''),
      }
      resolve(obj_data)

    } catch (e) {
      console.error(e)
    }
  })
}

function checkState (callback) {
  const obj_data = getCookie()
  if (!obj_data) {
    callback(true)
  }
  requestSignIn(obj_data.login, obj_data.password, (statut, message, data) => {
    if (statut === true) {
      callback(false, data)
    } else {
      callback(true)
    }
  })
}

function cookieLogout () {
  const cookies = new Cookies()
  cookies.remove('you')
  cookies.remove('patrick')
  cookies.remove('bob')
}

export { cookieLogin, checkState, cookieLogout, getCookie }
