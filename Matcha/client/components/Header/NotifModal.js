import React, { Component } from 'react'
import { connect } from 'react-redux'
import Modal from 'react-modal'
import { toJS } from 'immutable'
import ViewProfile from '../Home/components/ViewProfile.js'
import { statusModal } from '../../actions/Modal'
import { setNotifModal } from '../../actions/notifications'


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

class NotifModal extends Component {
  state = {
      modalIsOpen: true
  }

  closeModal = () => {
    this.setState({ modalIsOpen: false})
    this.props.dispatch(statusModal(false))
    this.props.dispatch(setNotifModal(null))
  }

  render() {
    const { dataNotifModal, statusButton } = this.props
    if (!dataNotifModal){ return <div/> }

    return (
      <Modal
        isOpen={this.state.modalIsOpen}
        onRequestClose={this.closeModal}
        style={customStyles}
        contentLabel='viewProfile'
      >
        <ViewProfile data={{profile:dataNotifModal.user}} closeModal={this.closeModal} status={false} />
      </Modal>
    )
  }
}

const mapStateToProps = state => {
  const session =  state.session.toJS()
  if (session.dataNotifModal){
    const dataNotifModal = session.dataNotifModal
    return {
      session,
      dataNotifModal,
    }
  }
  return {
    session,
  }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

NotifModal = connect(mapStateToProps, mapDispatchToProps)(NotifModal)

export default NotifModal
