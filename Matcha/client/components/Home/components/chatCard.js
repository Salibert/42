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
import { openChat, send, addMessage, getMessages } from '../../../actions/Chat'
import Divider from 'material-ui/Divider'
import IconMenu from 'material-ui/IconMenu'
import MenuItem from 'material-ui/MenuItem'
import IconButton from 'material-ui/IconButton'
import QuestionAnser from 'material-ui/svg-icons/action/question-answer'
import Close from 'material-ui/svg-icons/navigation/close'
import moment from 'moment'
import ChatBuble from './chatBuble'
import {
  radioButtonStyle,
  radioButtonStyleError,
  radioButtonStyleNormal,
} from './style'

class card extends Component {


  state = {
    message: '',
  }

  componentDidMount () {
    this.props.dispatch(getMessages(this.props.chat))
  }
  sendMessage = (e) => {
    e.preventDefault()
    const { message } = this.state
    const { chat, dispatch } = this.props
    this.setState({ message: '' })
    dispatch(send(chat, message))
  }

  render () {
    const { chat, closeChat } = this.props
    const { message } = this.state
    return (
      <Paper style={{ height: '400px', width: '300px', display: 'flex', flexDirection: 'column', justifyContent: 'space-between', alignItems: 'flex-start', marginRight: '10px', zIndex: '2' }}>
        <div style={{ padding: '10px', display: 'flex', flexDirection: 'row', alignItems: 'center', backgroundColor: '#3e4eb7', width: '100%' }}>
          <Avatar
            style={{ marginTop: '5px' }}
            src={chat.reciver.image1 || 'https://www.workidol.com/assets/images/common/profile.png'}
            size={40}
          />
          <p style={{ marginLeft: '10px' }}>{chat.reciver.firstname}</p>
          <IconButton style={{ textAlign: 'right', width: '100%' }} onClick={closeChat}><Close /></IconButton>
        </div>
        <Divider style={{ width: '300px' }} />
        <ChatBuble chat={chat} />
        <Divider style={{ width: '300px' }} />
        <div style={{ display: 'flex', flexDirection: 'row', height: '30px' }}>
          <form onSubmit={(e) => { this.sendMessage(e) }}>
            <input style={{ width: '250px' }} value={message} onChange={(e, a) => { this.setState({ message: e.target.value }) }} />
          </form>
          <IconButton style={{ alignSelf: 'center' }} onClick={this.sendMessage} ><QuestionAnser /></IconButton>
        </div>
      </Paper>
    )
  }
}

const mapStateToProps = state => {
  return { state }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

card = connect(mapStateToProps, mapDispatchToProps)(card)

export default card
