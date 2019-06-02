import React, { Component } from 'react'
import PropTypes from 'prop-types'
import { connect } from 'react-redux'
import { Field, reduxForm } from 'redux-form'
import { MuiThemeProvider, getMuiTheme } from 'material-ui/styles'
import { failLogin, successLogin } from '../../actions/login'
import { requestSignIn } from '../../actions/User'
import { TextField, RaisedButton } from 'material-ui'
import SHA from 'sha1'
import Paper from 'material-ui/Paper'

import './style.scss'

const muiTheme = getMuiTheme({ userAgent: false })

class LoginComponent extends Component {

  componentDidUpdate () {
    if (this.props.data_user) {
      this.context.router.push('/home')
    }
  }

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
    this.props.dispatch(requestSignIn(event.login, SHA(event.password)))

  }
  render () {

    const { handleSubmit } = this.props

    return (
      <Paper style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', padding: '30px', marginBottom: '30px', overflow: 'auto' }}>
        <form onSubmit={handleSubmit(this.onSubmit)}>
          <Field name='login' component={this.renderTextField} label='Login' />
          <Field name='password' component={this.renderTextField} label='Password' type='password'/>
          <RaisedButton label='Submit' primary={true} type='submit'/>
          <div style={{display: 'flex', flexDirection: 'column', alignItems: 'center'}}>
          <a style={{ padding: '5px', marginTop: '20px', fontSize: '0.8em' }} target='_blank' href='http://localhost:5001/HelpUser?action=ForgetMyPassword' alt='ForgetPassword' >
            {'Forgot your password'}
          </a>
          <a style={{ padding: '5px', fontSize: '0.8em' }} target='_blank' href='http://localhost:5001/HelpUser?action=ValideAccount' alt='Resend'>
            {'Send a email validtion'}
          </a>
          </div>
        </form>
      </Paper>
    )
  }
}

LoginComponent.propTypes = {
  children: PropTypes.object,
  state: PropTypes.object,
  messageSystem: PropTypes.func,
  successLogin: PropTypes.func,
  failLogin: PropTypes.func,
}

LoginComponent.contextTypes = {
  router: PropTypes.object,
}

const validate = values => {

  const errors = {}
  const requiredFields = ['login', 'password']

  requiredFields.forEach(field => {
    if (!values[field]) {
      errors[field] = 'Required'
    }
  })
  return errors
}

const mapStateToProps = state => {
  return {
    session: state.session.toJS(),
    data_user: state.session.getIn(['data_user']),
    message_system: state.session.getIn(['message_system']),
  }
}

const mapDispatchToProps = dispatch => {
  return {
    failLogin: () => dispatch(failLogin()),
    successLogin: (data) => dispatch(successLogin(data)),
    updatemessageSystem: (data) => dispatch(updatemessageSystem(data)),
    dispatch,
  }
}

LoginComponent = reduxForm({
  form: 'login',
  validate,
  enableReinitialize: true,
})(LoginComponent)

export default connect(mapStateToProps, mapDispatchToProps)(LoginComponent)
