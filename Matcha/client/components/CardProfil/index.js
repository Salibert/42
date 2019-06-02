import React, { Component } from 'react'
import { connect } from 'react-redux'
import { Field, reduxForm } from 'redux-form'
import { Avatar, Paper, FlatButton, FontIcon, GridTile, IconButton, Subheader } from 'material-ui'
import ActionAndroid from 'material-ui/svg-icons/action/android'
import SocialSentimentSatisfied from '../MyIcon/SocialSentimentSatisfied.js'
import SocialSentimentVerySatisfied from '../MyIcon/SocialSentimentVerySatisfied.js'
import ActionFavorite from '../MyIcon/ActionFavorite.js'
import Modal from 'react-modal'
import ViewProfile from '../Home/components/ViewProfile.js'
import './style.scss'
import { statusModal } from '../../actions/Modal'
import ActionLock from '../MyIcon/ActionLock.js'
import { seeProfile } from '../../actions/notifications'

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

class CardProfil extends Component {

  constructor (props) {
    super(props)
    this.state = {
      height: props.height,
      modalIsOpen: false,
    }
  }

  openModal = () => {

    this.state.modalIsOpen = true
    if (!this.props.session.statusButton) {
      this.props.dispatch(statusModal(true))
    }
  }

  closeModal = () => {
    this.state.modalIsOpen = false
    this.props.dispatch(statusModal(false))
  }

  IconOpenModal = () => {
    const { data, session } = this.props
    const profile = data.profile

    let text = ''
    let insideDiv = <div/>
    if (session && session.data_user && session.data_user.myblock && session.data_user.myblock.length && session.data_user.myblock.indexOf(profile.id) != -1) {
      text = 'User blocked'
      insideDiv = <ActionLock color='white'/>
    } else if (profile.mylike.indexOf(session.data_user.id) != -1) {
      text = 'This user you like'
      insideDiv = <SocialSentimentVerySatisfied color='red' />
    } else if (session.data_user.mylike.indexOf(profile.id) != -1) {
      text = 'You have like this user'
      insideDiv = <ActionFavorite color='red' />
    } else {
      text = 'See this user profile'
      insideDiv = <SocialSentimentSatisfied color='white' />
    }
    return (
      <div>
        <IconButton tooltip={text} touch={true} tooltipPosition='top-left' onClick={this.openModal} onMouseDown={() => {
          this.props.dispatch(seeProfile({target:data, me:session.data_user}))
        }}>
          {insideDiv}
        </IconButton>
      </div>
    )
  }

  render () {

    const { data } = this.props
    const profile = data.profile
    const statusButton = this.props.session.statusButton
    if (!profile) { return <div/> }
    return (
      <Paper zDepth={3} rounded={false} style={{ height: '80%', width: '80%'}}>
        <GridTile
          title={profile.login}
          subtitle={<p style={{margin:'5 5 5 0', fontSize: '0.8rem'}}>{`location: ${profile.localisation || -1}km`}</p>}
          actionIcon={ !statusButton ? <this.IconOpenModal /> : <div></div> }>
          <img style={{ height: '100%', width: '100%' }} src={profile.image1} />
          <Modal
            isOpen={this.state.modalIsOpen}
            onRequestClose={this.closeModal}
            style={customStyles}
            contentLabel='viewProfile'
          >
            <ViewProfile data={data} closeModal={this.closeModal} status={false}/>
          </Modal>
        </GridTile>
      </Paper>
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

CardProfil = connect(mapStateToProps, mapDispatchToProps)(CardProfil)

export default CardProfil
