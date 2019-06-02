function failLogin () {
  return {
    type: 'client/failLogin',
  }
}

function successLogin (data) {
  return {
    type: 'client/successLogin',
    data,
  }
}

export { successLogin, failLogin }
