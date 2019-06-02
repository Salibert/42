import * as request from 'superagent'

const requestSignIn = (login, password, callback) => {
  if (!login || !password) {
    return callback(false)
  }
  request.post(`http://localhost:5000/usr/auth/${login}`)
    .send(password)
    .then((err, res) => {
      if (err) {
        const text = { message: null }
        if (res !== undefined || res) { JSON.parse(res.text) }
        callback(false, text.message)
      } else if (res.text) {
        let text = JSON.parse(res.text)
        if (!text) { text = '' }
        callback(true, text.message, text.data)
      }
    }).catch(e => {
      console.error(e)
    })
}

const requestSignUp = (data, callback) => {
  request.post('http://localhost:5000/usr/createAccount')
    .send({
      login: data.login,
      email: data.email,
      firstname: data.firstname,
      lastname: data.lastname,
      password: data.password,
    })
    .type('form')
    .end((err, res) => {
      if (err) {
        let text = { message: null }
          text.message = res.statusText ? res.statusText : 'internal server error'
        callback(false, text.message)
      } else if (res.text) {
        let text = ''
        if (res !== undefined || res && res.text) {
          text = res.text
        }
        callback(true, text.message)
      }
    })
}

const checkEmail = (email, callback) => {
  request.get(`http://localhost:5000/usr/checkEmail/${email}`)
    .end((err) => {
      if (err) { return callback(false, 'email déjà utilisé') }
      callback(true)
    })
}

const uploadPictures = (file, index) => {
  // request.post('http://localhost:5000/usr/')
}

const updateProfile = (login, newUser, oldUser, callback) => {
  return (null)
}

export { requestSignUp, updateProfile }
