import { toJs } from 'immutable'
import { updateSocket } from '../actions/User'

const socketIoMiddleWare = socket => ({ dispatch, getState }) => {

  if (socket) { socket.on('action', dispatch) }
  return next => action => {
    const state = getState().session.toJS()
    if (socket && action.type && action.type.indexOf('server/') === 0) {
      const serverAction = action.type.split('/')
      socket.emit(serverAction[1], action.data)
    }
    if (socket.id && !state.socketId && action.type=== 'super/connect') {
      return next({ type: 'client/connect', data: socket.id })
  }
    return next(action)
  }
}

export default socketIoMiddleWare
