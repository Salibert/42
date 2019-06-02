import React, { Component } from 'react'
import { connect } from 'react-redux'
import { Field, reduxForm } from 'redux-form'
import Paper from 'material-ui/Paper'
import Finder from './components/finder.js'
import Favorit from './components/favorit.js'
import Match from './components/Match.js'
import { toJS } from 'immutable'
import { checkState, updateSocket, updateMatch, pullMatchs, updateUser, cleanUser } from '../../actions/User/index'
import { geolocated } from 'react-geolocated'
import request from 'superagent'
import { getCookie } from '../../service/cookies.service.js'



class HomePage extends Component {


  componentDidMount () {
    let url = window.location.href.split('/'),
      string = url[3]
    if (!this.props.data_user && (string !== 'signin' && string !== 'signup')) {
        getCookie().then(dataUser => {
          this.props.dispatch(checkState(dataUser))
      })
    }
  if (this.props.session && this.props.session.data_user && !this.props.session.data_user.image1) { this.props.router.push('/profile') }
  }


  // componentWillReceiveProps (nextProps) {
  //   if (this.props.session && nextProps.session && nextProps.session.data_user && (!nextProps.session.data_user.socketId || nextProps.session.socketId != nextProps.session.data_user.socketId)) { this.props.dispatch(updateSocket(nextProps.session.data_user.login, nextProps.session.socketId, nextProps.session.matchs))  } else if (Array.isArray(nextProps.session.matchs) && nextProps.session.shouldUpdate && nextProps.session.data_user) {
  //     this.props.dispatch(updateMatch(nextProps.session.data_user.login, nextProps.session.socketId, nextProps.session.matchs))
  //   }
  //   if (nextProps.session && nextProps.session.data_user && (!nextProps.session.data_user.latitude || !nextProps.session.data_user.longitude)) {
  //       request.get('https://freegeoip.net/json/')
  //         .set('Access-Control-Allow-Origin')
  //         .then((res) => {
  //           this.props.dispatch(updateUser(this.props.session.data_user.login, {}, { lat: res.body.latitude, lng: res.body.longitude }))
  //         })
  //   }
  //    this.props.dispatch({type: 'super/connect'})
  // }
  render () {
    const { session } = this.props

    return (
      <div>
    {session.data_user && (
      <div>
        <div style={{ display: 'flex', flexDirection: 'row', height: 'auto', justifyContent: 'space-between', margin: '10px' }}>
          <Finder />
          <Match />
          <div style={{ display: 'flex', flexDirection: 'column', width: '15%', alignItems: 'space-between' }}>
            <Favorit />
          </div>
        </div>
        </div>
      )}
      </div>
    )
  }
}

const mapStateToProps = state => {
  const session = state.session.toJS()
  if (session.data_user) {
    const data_user = session.data_user
    return {
      initialValues: {
        sizezone: data_user.sizezone,
        targetsexe: data_user.targetsexe,
      },
      session,

    }
  }
  return {
    session,
  }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}
HomePage = connect(mapStateToProps, mapDispatchToProps)(HomePage)

export default HomePage
