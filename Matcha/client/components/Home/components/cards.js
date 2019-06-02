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
import { statusModal } from '../../../actions/Modal'
import Modal from 'react-modal'
import ViewProfile from './ViewProfile.js'
import IconMenu from 'material-ui/IconMenu'
import MenuItem from 'material-ui/MenuItem'
import IconButton from 'material-ui/IconButton'
import MoreVertIcon from 'material-ui/svg-icons/navigation/more-vert'
import moment from 'moment'

import {
  radioButtonStyle,
  radioButtonStyleError,
  radioButtonStyleNormal,
} from './style'

const customStyles = {
  content: {
    top: '20%',
    left: '17%',
    right: '16%',
    bottom: '20%',
    padding: '0px',
    overflow: '0',
    backgroundColor: '#fff7f7',
  },
}

class card extends Component {

  state = {
    modalIsOpen: false,
  }

    openModal = () => {
      if (!this.props.session.statusButton) {
        this.setState({ modalIsOpen: true })
        this.props.dispatch(statusModal(true))
      }
    }

    closeModal = () => {
      this.setState({ modalIsOpen: false})
      this.props.dispatch(statusModal(false))
    }

   openAnewChat = (sender, reciver) => {
     const { dispatch } = this.props
     dispatch(openChat({ sender, reciver }))
   }

   render () {
     const { me, info } = this.props
     const statusButton = this.props.session.statusButton
     return (
       <div style={{ margin: '5px', display: 'flex', flexDirection: 'row', justifyContent: 'space-between', alignItems: 'center' }}>
         <div style={{ marginLeft: '5px', display: 'flex', flexDirection: 'row', justifyContent: 'center' }}>
           {info.socketId ? (<Avatar
             style={{ boxShadow: '0px 0px 13px 5px #61ce74' }}
             src={info.image1 || 'https://www.workidol.com/assets/images/common/profile.png'}
             size={40}
           />
           ) : (
             <Avatar
               style={{ boxShadow: '0px 0px 13px 5px #ea677f' }}
               src={info.image1 || 'https://www.workidol.com/assets/images/common/profile.png'}
               size={40}
             />
           )}

         </div>
         <div style={{ marginLeft: '10px' }}>
           <p>{ info.firstname }</p>
           <p>{ moment(info.birthdate).isValid() ? moment(info.birthdate).fromNow(true) : '18 years' }</p>
           <p style={{fontSize:'0.85rem', marginTop:'5px'}}>{ !info.socketId ? `last connection: ${moment(info.reg_date).fromNow(true)} ago` : '' }</p>
         </div>
         <IconMenu style={{ justifyContent: 'fl' }}
           iconButtonElement={<IconButton disabled={statusButton}><MoreVertIcon /></IconButton>}
           anchorOrigin={{ horizontal: 'left', vertical: 'top' }}
           targetOrigin={{ horizontal: 'left', vertical: 'top' }}>
           <MenuItem primaryText='Chat' onClick={() => { this.openAnewChat(me, info) }} />
           <MenuItem primaryText='Profile' onClick={this.openModal} />
         </IconMenu>
         <Modal
           isOpen={this.state.modalIsOpen}
           onRequestClose={this.closeModal}
           style={customStyles}
           contentLabel='viewProfile'
         >
           <ViewProfile data={{profile:info}} closeModal={this.closeModal} status={true} />
         </Modal>

       </div>
     )
   }
}

const mapStateToProps = state => {
  return {
    session: state.session.toJS(),
  }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

card = connect(mapStateToProps, mapDispatchToProps)(card)

export default card
