import React, { Component } from 'react'
import PropTypes from 'prop-types'
import { connect } from 'react-redux'
import { Field, reduxForm } from 'redux-form'
import { TextField, RaisedButton } from 'material-ui'
import { callApi } from '../../service/apiCaller'
import { closeToster, addToster } from '../../actions/Toaster/index.js'
import SHA from 'sha1'
import Paper from 'material-ui/Paper'

import './style.scss'

class ForGetPassword extends Component {

  renderTextField = ({ input, label, meta: { touched, error }, ...custom }) => (
    <TextField
      style={{ width: '100%', marginBottom: '20px', height: '80px' }}
      inputStyle={{ fontWeight: 100, fontSize: '1.8em' }}
      floatingLabelStyle={{ color: '#3F51B5', fontWeight: 400 }}
      underlineFocusStyle={{ borderColor: '#ff3b7f' }}
      hintText={label}
      floatingLabelText={label}
      errorText={touched && error}
      {...input}
      {...custom}
    />
  )

  onSubmit = (event) => {
    const query = this.props.location.query
    let password = SHA(event.password)
    callApi(`usr/ForgetMyPassword/${query.id}/${query.token}`, 'post', {password}).then(data => {
      this.context.router.push('/signin')
    }).catch(e => {
      this.props.dispatch(addToster(e))
    })
  }

  render () {

    const { handleSubmit } = this.props

    return (
      <Paper style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', padding: '30px', marginBottom: '30px', overflow: 'auto' }}>
        <form onSubmit={handleSubmit(this.onSubmit)}>
          <Field name='password' component={this.renderTextField} label='Password' type='password'/>
          <Field name='password1' component={this.renderTextField} label='Confirm Password' type='password'/>
          <RaisedButton label='Submit' primary={true} type='submit' />
        </form>
      </Paper>
    )
  }
}

ForGetPassword.contextTypes = {
  router: PropTypes.object,
}

const validate = values => {

  const errors = {}
  const requiredFields = ['password1', 'password']

  requiredFields.forEach(field => {
    if (!values[field]) {
      errors[field] = 'Required'
    }
  })
  if (!values.password || values.password.match(/^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{7, 16}$/)) {
    errors.password = 'Your password must be minimum eight characters, at least one letter, one number and one special character'
  }
  if (values.password != values.password1) {
    errors.password = 'Your password confirmation must be the same as the password'
    errors.password1 = 'Your password confirmation must be the same as the password'
  }
  return errors
}

const mapStateToProps = state => {
  return { state }
}

const mapDispatchToProps = dispatch => {
  return {
    failLogin: () => dispatch(failLogin()),
    successLogin: (data) => dispatch(successLogin(data)),
    updatemessageSystem: (data) => dispatch(updatemessageSystem(data)),
    dispatch,
  }
}

ForGetPassword = reduxForm({
  form: 'login',
  validate,
  enableReinitialize: true,
})(ForGetPassword)

export default connect(mapStateToProps, mapDispatchToProps)(ForGetPassword)
