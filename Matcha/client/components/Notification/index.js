import React, { Component } from 'react'
import { connect } from 'react-redux'
import Drawer from 'material-ui/Drawer'
import { toJS } from 'immutable'
import Avatar from 'material-ui/Avatar'
import Divider from 'material-ui/Divider'
import CardsNotif from './components/cardsNotif.js'

class Notifications extends Component {

  // componentDidMount () {
  // }
  //
  // componentWillReceiveProps (nextProps) {
  // }

  render () {
    const { session, open, onClose } = this.props
    const goodNotif = session.data_user.notif.filter(e => !e.vue)
    return (
      <Drawer
        openSecondary={true}
        docked={false}
        width={400}
        open={open}
        onRequestChange={onClose}
      >
        <div>
          {goodNotif && (
            goodNotif.map((n, key) =>
              <div key={key}>
                <CardsNotif n={n} onClose={onClose} />
                {key < goodNotif.length - 1 && (<Divider style={{ width: '400px' }}/>)}
                </div>
              )
            )}
        </div>
      </Drawer>
    )
  }
}

const mapStateToProps = state => {
  const session = state.session.toJS()
  return {
    session,
  }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

Notifications = connect(mapStateToProps, mapDispatchToProps)(Notifications)

export default Notifications
