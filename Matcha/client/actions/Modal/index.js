import { callApi } from '../../service/apiCaller.js'

export function statusModal (openModal) {
  return dispatch => {
    dispatch({ type: 'client/statusButton', data: openModal })
  }
}

export function socketBlock (userID, targetID, key, statusButton) {
  return dispatch => {
    dispatch({
      type: 'server/sendBlock',
      data: { userID, targetID, key },
    })
    dispatch({
      type: 'client/closeChat',
      data: { sender:{ id: userID }, reciver:{ id: targetID }}
    })
    if (statusButton) {
      console.log("ACTION SOKECTLIKE");
      
      dispatch({
        type: 'client/statusButton',
        data: false
      })
    }
  }
}

export function socketReport (userID, targetID, key, statusButton) {
  return dispatch => {
    dispatch({
      type: 'server/sendReport',
      data: { userID, targetID, key },
    })
    if (statusButton) {
      console.log("ACTION SOKECTLIKE");

      dispatch({
        type: 'client/statusButton',
        data: false
      })
    }
  }
}

export function socketLike (userID, targetID, key, statusButton) {
  return dispatch => {
    dispatch({
      type: 'server/sendLike',
      data: { userID, targetID, key },
    })
    if (statusButton) {
      console.log("ACTION SOKECTLIKE");
      dispatch({
        type: 'client/statusButton',
        data: false
      })
    }
  }
}
