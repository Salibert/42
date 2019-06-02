import React, { Component } from 'react'
import { connect } from 'react-redux'
import Slider from 'material-ui/Slider'
import TextField from 'material-ui/TextField'
import { toJS } from 'immutable'
import RaisedButton from 'material-ui/RaisedButton'
import Avatar from 'material-ui/Avatar'
import Footer from './footer.js'
import NotificationsIcon from 'material-ui/svg-icons/social/notifications'
import Snackbar from 'material-ui/Snackbar'
import { Cookies } from 'react-cookie'
import { closeToster } from '../../actions/Toaster'
import { userDisconnet } from '../../actions/User'
import Notifications from '../Notification'
import NotifModal from './NotifModal'
import PropTypes from 'prop-types'
import Chat from '../Home/components/chat.js'

import { checkState, updateSocket, updateMatch, pullMatchs, updateUser, cleanUser } from '../../actions/User/index'

import {
  AppBar,
  IconButton,
  IconMenu,
  MenuItem,
  FlatButton,
  Badge,
  Paper,
} from 'material-ui'
import style from './styles.scss'

class Header extends Component {

  state = {
    notifications: false,
  }

  componentDidMount () {
    if(this.props.location.pathname === '/') {
      this.props.router.push('/home')
    }
  }

  componentWillReceiveProps (nextProps) {
    if (this.props.session && nextProps.session && nextProps.session.data_user && (!nextProps.session.data_user.socketId || nextProps.session.socketId != nextProps.session.data_user.socketId)) { this.props.dispatch(updateSocket(nextProps.session.data_user.login, nextProps.session.socketId, nextProps.session.matchs))  } else if (Array.isArray(nextProps.session.matchs) && nextProps.session.shouldUpdate && nextProps.session.data_user) {
      this.props.dispatch(updateMatch(nextProps.session.data_user.login, nextProps.session.socketId, nextProps.session.matchs))
    }

  }


  renderSingIn = () => {
    let url = window.location.href.split('/'),
      new_url = '',
      target_url = ''
    if (url[3] === 'signup') {
      target_url = 'signin'
      new_url = `http://${url[2]}/${target_url}`
    }
    if (url[3] === 'signin') {
      target_url = 'signup'
      new_url = `http://${url[2]}/${target_url}`
    }
    if (!target_url || !new_url) { return (<div />) }
    return (
      <div>
        <FlatButton
          label={target_url}
          href={new_url} />
      </div>
    )
  }

  HeaderRight = () => {
    const { session } = this.props
    let nbrNotif = 0
    if (session.data_user && session.data_user.notif) { session.data_user.notif.forEach(n => { if (n.vue === false) { nbrNotif++ } }) }
    return (
      <div style={{ display: 'flex', flexDirection: 'row', justifyContent: 'center', alignItems: 'center' }}>
        <div>
          <FlatButton
            label={'sign out'}
            onClick={() => {
              const cookies = new Cookies()
              cookies.remove('you')
              window.location.reload()
              this.props.dispatch(userDisconnet())
            }}
          />
        </div>
        <Badge
          badgeContent={nbrNotif}
          secondary={true}
          badgeStyle={{ top: 20, right: 20 }}
          onClick={() => {
            if (nbrNotif != 0) { this.setState({ notifications: !this.state.notifications }) }
          }}
        >
          <IconButton tooltip='Notifications'>
            <NotificationsIcon />
          </IconButton>
        </Badge>
      </div>
    )
  }
  logo = () => {
    return (
      <Avatar
        src={'http://blog.francetvinfo.fr/bureau-bresil/files/2017/03/tinder-.png'}
        size={40}
      />
    )
  }
   handleCloseToster = () => {
     this.props.dispatch(closeToster())
   }
   render () {
     const { session } = this.props
     const { notifications } = this.state
     const dataNotifModal = this.props.session.dataNotifModal

     return (
       <div style={{ display: 'flex', flexDirection: 'column', justifyContent: 'center', alignItems: 'center', backgroundColor: '#ddd2d2', height: '100%' }}>
         <AppBar
           zDepth={3}
           style={{ display: 'flex', justifyContent: 'center', alignItems: 'center', cursor: 'pointer' }}
           title='DateMe'
           onClick={() => { this.props.router.push('/home') }}
           iconElementLeft={<this.logo />}
           iconElementRight={session.data_user ? <this.HeaderRight/> : <this.renderSingIn />}
         />
         { notifications && (
           <Notifications open={notifications} onClose={() => { this.setState({ notifications: !notifications }) }} />
         )}
         { dataNotifModal && (<NotifModal />)}
         <div style={{ height: '100%', width: '100%' }}>
           {this.props.children}
         </div>
         <div style={{alignSelf: 'flex-start'}}>
          <Chat />
         </div>
         <Snackbar
           open={Boolean(session.toasterMessage)}
           message={session.toasterMessage || 'internal serveu error'}
           autoHideDuration={3000}
           onRequestClose={this.handleCloseToster}
         />
         <Footer/>
       </div>
     )
   }
}

const mapStateToProps = state => {
  const session = state.session.toJS()
  return {
    message_system: state.session.getIn(['message_system']),
    data_user: state.session.getIn(['data_user']),
    session,
  }
}

const mapDispatchToProps = dispatch => {
  return {
    resetState: (data) => dispatch(resetState(data)),
    signOut: () => dispatch(signOut()),
    dispatch }
}

export default connect(mapStateToProps, mapDispatchToProps)(Header)
