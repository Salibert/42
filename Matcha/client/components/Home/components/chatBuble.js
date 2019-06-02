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
import { openChat } from '../../../actions/Chat'
import Divider from 'material-ui/Divider'
import IconMenu from 'material-ui/IconMenu'
import MenuItem from 'material-ui/MenuItem'
import IconButton from 'material-ui/IconButton'
import MoreVertIcon from 'material-ui/svg-icons/action/question-answer'
import moment from 'moment'

class chatBuble extends Component {



  render () {
    const { chat } = this.props

    if (this.refs.chat) { this.refs.chat.scrollTop = this.refs.chat.scrollHeight }
    return (
      <div style={{ maxHeight: 'auto', width: '290px', overflow: 'auto', flex: 1, padding: '5px', display: 'flex', flexDirection: 'column' }} ref='chat'>
        {chat && chat.message && (
          chat.message.map((m, key) => m.senderId != chat.sender.id
            ? <Paper key={key} style={{ borderRadius: '20px', padding: '7px', marginBottom: '5px', flexGrow: '0', alignSelf: 'flex-start', backgroundColor: 'white' }}>{m.message}</Paper>
            : <Paper key={key} style={{ borderRadius: '20px', padding: '7px', marginBottom: '5px', alignSelf: 'flex-end', backgroundColor: 'white' }}>{m.message}</Paper>
          )
        )}
      </div>
    )
  }
}

export default chatBuble
