import React, { Component } from 'react'
import PropTypes from 'prop-types'
import { connect } from 'react-redux'
import { actifAccount } from '../../actions/User'

class ValideAccount extends Component {

  componentDidMount () {
    const query = this.props.location.query
    this.props.dispatch(actifAccount(query.id, query.token))
  }

  componentDidUpdate () {
     if (this.props.data_user) {
       this.context.router.push('/profile')
     } else {
       this.context.router.push('/signin')
     }
   }

  render () {
    return (
      <div/>
    )
  }
}

ValideAccount.contextTypes = {
  router: PropTypes.object,
}

const mapStateToProps = state => {
  return { state }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

export default connect(mapStateToProps, mapDispatchToProps)(ValideAccount)
