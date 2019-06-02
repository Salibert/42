import { getCookie } from './cookies.service.js'
import SHA from 'sha1'
import each from 'foreach'

function reckonAge (date) {
  if (date) {
    const actuelDate = new Date()
    let month = actuelDate.getMonth(),
      year = actuelDate.getFullYear(),
      day = actuelDate.getDate()
    const ageUser = actuelDate.getFullYear() - date.getFullYear()
    return ageUser
  }
  return null
}

function checkPassword (id, oldPassword, callback, newPassword) {
  const result = getCookie()
  if (result) {
    oldPassword = SHA(oldPassword)
    if (oldPassword === result.password) {
      if (id === 'oldPassword') { return callback(false) } else if (id === 'confirmPassword' || id === 'newPassword') {
        newPassword = SHA(newPassword)
        if (newPassword != oldPassword) { return callback(false) }
      }
    }
  }
  return callback(true)
}

function createUpdateObject (oldUser, newUser) {
  const modifProfile = {
    targetsexe: !newUser.targetsexe ? oldUser.targetsexe : newUser.targetsexe,
    firstname: !newUser.firstname ? oldUser.firstname : newUser.firstname,
    lastname: !newUser.lastname ? oldUser.lastname : newUser.lastname,
    password: !newUser.password ? oldUser.password : newUser.password,
    addresse: !newUser.addresse ? oldUser.addresse : newUser.addresse,
    email: !newUser.email ? oldUser.email : newUser.email,
    sexe: !newUser.sexe ? oldUser.sexe : newUser.sexe,
    age: !newUser.age ? oldUser.age : newUser.age,
    bio: !newUser.bio ? oldUser.bio : newUser.bio,
  }
  return modifProfile
}

export { reckonAge, checkPassword, createUpdateObject }
