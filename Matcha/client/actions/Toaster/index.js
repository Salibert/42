export function addToster (message) {
  return {
    type: 'client/addToster',
    message,
  }
}
export function closeToster () {
  return {
    type: 'client/closeToster',
    data: {},
  }
}
