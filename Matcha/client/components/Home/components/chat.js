import React, { Component } from 'react'
import { connect } from 'react-redux'
import Slider from 'material-ui/Slider'
import TextField from 'material-ui/TextField'
import Paper from 'material-ui/Paper'
import { toJS } from 'immutable'
import RaisedButton from 'material-ui/RaisedButton'
import { RadioButton, RadioButtonGroup } from 'material-ui/RadioButton'
import Checkbox from 'material-ui/Checkbox'
import Avatar from 'material-ui/Avatar'
import DatePicker from 'material-ui/DatePicker'
import ChipInput from 'material-ui-chip-input'
import ChatCard from './chatCard.js'
import { closeChat } from '../../../actions/Chat'

import {
  radioButtonStyle,
  radioButtonStyleError,
  radioButtonStyleNormal,
} from './style'

class Chat extends Component {


  constructor (props) {
    super(props)
    this.state = { height: props.height, width: props.width }
  }
  componentWillMount () {
    this.setState({ height: window.innerHeight, width: window.innerWidth })
  }
  closeChat = (e) => {
    const { dispatch } = this.props
    dispatch(closeChat(e))
  }
  render () {
    const { session, openChat } = this.props
    return (
      <div style={{ display: 'flex', position: 'fixed', over: 'relative', zIndex: '100', top: this.state.height - 450, flexDirection: 'row', padding: '10px', justifyContent: 'flex-end', marginTop: '40px', width: 'max' }}>
        { openChat.length != 0 && session.data_user && (
          openChat.map((e, key) =>
            <ChatCard key={key} chat={e} closeChat={() => { this.closeChat(e) }} />)
        )}
      </div>
    )
  }
}

const mapStateToProps = state => {
  let openChat = []
  const session = state.session.toJS()
  if (session.openChat) { openChat = session.openChat }
  return {
    session,
    openChat,
  }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

Chat = connect(mapStateToProps, mapDispatchToProps)(Chat)

export default Chat
