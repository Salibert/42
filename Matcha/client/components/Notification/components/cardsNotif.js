import React, { Component } from 'react'
import { connect } from 'react-redux'
import { updateNotife } from '../../../actions/notifications'
import { toJS } from 'immutable'
import Avatar from 'material-ui/Avatar'

class cardsNotif extends Component {

  handleNotif = (n, status) => {
    const session = this.props.session
    const { onClose } = this.props

    if (session.data_user) {
      this.props.dispatch(updateNotife(session.data_user.login, n, status))
      if (status === true) {
        onClose()
      }
    }
  }

  render() {
    const { n } = this.props

    return (
      <div>
        <div style={{ margin: '5px', marginTop: '20px', marginBottom: '20px', display: 'flex', flexDirection: 'row', alignItems: 'center' }}>
          <div style={{ marginLeft: '5px', display: 'flex', flexDirection: 'row', justifyContent: 'center' }} >
            <Avatar
              src={n.user.image1|| 'https://www.workidol.com/assets/images/common/profile.png'}
              size={65}
              onClick={() => {this.handleNotif(n, true)}}
            />
          </div>
          <div style={{ marginLeft: '20px' }} onClick={() => {this.handleNotif(n, false)}}>
            <p>{n.message}</p>
          </div>
        </div>
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

cardsNotif = connect(mapStateToProps, mapDispatchToProps)(cardsNotif)

export default cardsNotif
