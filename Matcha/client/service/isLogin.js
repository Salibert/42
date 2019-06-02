import React, { Component } from 'react'
import { connect } from 'react-redux'
import { Cookies } from 'react-cookie'

class EnsureLoggedInContainer extends Component {
  componentDidMount () {
    if (!this.props.isLoggedIn) { this.props.router.push('/signin') }
  }

  render () {
    if (this.props.isLoggedIn) {
      return this.props.children
    }
    return null

  }
}
function mapStateToProps (state, ownProps) {
  const cookies = new Cookies()
  return {
    isLoggedIn: cookies.get('you') || '',
  }
}

export default connect(mapStateToProps)(EnsureLoggedInContainer)
