import React, { Component } from 'react'
import { connect } from 'react-redux'

class NotFound extends Component  {
  componentDidMount () {
    this.props.router.push('/home')
  }
render() {

   return (
  <div>
  </div>
)}
}

export default NotFound
