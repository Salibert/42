import React, { Component } from 'react'
import PropTypes from 'prop-types'
import { connect } from 'react-redux'
import { MuiThemeProvider, getMuiTheme } from 'material-ui/styles'
import { TextField, RaisedButton } from 'material-ui'
import { requestSignUp } from '../../service/user.service.js'
import Paper from 'material-ui/Paper'
import { Field, reduxForm } from 'redux-form'
import { closeToster, addToster } from '../../actions/Toaster/index.js'
import './style.scss'

const muiTheme = getMuiTheme({ userAgent: false })

class SignupForm extends Component {

  state = {
    user: {
      login: '',
      email: '',
      firstname: '',
      lastname: '',
      password: '',
      password_confirm: '',
    },
    errorMessage: '',
    loader: false
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
    this.setState({ loader: true })
      requestSignUp(event, (statut, message) => {
        if (statut == true) {
          this.context.router.push('/signin')
        } else {
          this.setState({ loader: false })
          this.props.dispatch(addToster(message))
        }
      })
  }
  render () {
    const { handleSubmit } = this.props
    const loader = this.state.loader

    return (
      <Paper style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', padding: '30px', marginBottom: '30px', overflow: 'auto' }}>
        <form onSubmit={handleSubmit(this.onSubmit)}>
          <Field name='firstname' component={this.renderTextField} label='firstname' />
          <Field name='lastname' component={this.renderTextField} label='lastname' />
          <Field name='login' component={this.renderTextField} label='Login' />
          <Field name='email' component={this.renderTextField} label='email' />
          <Field name='password' component={this.renderTextField} label='Password' type='password' />
          <Field name='password1' component={this.renderTextField} label='Confirm Password' type='password' />
          <RaisedButton disabled={loader} label='Submit' primary={true} type='submit' />
        </form>
      </Paper>
    )
  }
}

SignupForm.propTypes = {
  state: PropTypes.object,
  updatemessageSystem: PropTypes.func,
}

SignupForm.contextTypes = {
  router: PropTypes.object,
}
const validate = values => {

  const errors = {}
  const requiredFields = ['firstname', 'lastname', 'login', 'email', 'password', 'password1']

  requiredFields.forEach(field => {
    if (!values[field]) {
      errors[field] = 'Required'
    }
  })
  if (!values.login || (values.login.length < 3 || values.login.length > 240 || !values.login.match(/[0-9]/g))) {
    errors.login = 'Your pseudo must contains at least 4 characters, one number'
  }
  if (!values.email || !values.email.match(/^[\w\-\+]+(\.[\w\-]+)*@[\w\-]+(\.[\w\-]+)*\.[\w\-]{2,}$/)) {
    errors.email = 'Your email is not valid'
  }
  if (!values.firstname || (values.firstname.length < 2 || values.firstname.match(/^[A-Z]'?[- a-zA-Z]( [a-zA-Z])*$/gi))) {
    errors.firstname = 'Your firstname is not valid'
  }
  if (!values.lastname || (values.lastname.length < 2 || values.lastname.match(/^[A-Z]'?[- a-zA-Z]( [a-zA-Z])*$/gi))) {
    errors.lastname = 'Your lastname is not valid'
  }
  if (!values.password || values.password.match(/^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{7, 16}$/)) {
    errors.password = 'Your password must be minimum eight characters, at least one letter, one number and one special character'
  }
  if (values.password != values.password1) {
    errors.password = 'Your password confirmation must be the same as the password'
    errors.password1 = 'Your password confirmation must be the same as the password'
  }
  return errors
}

const mapDispatchToProps = (dispatch) => {
  return {
    updatemessageSystem: (data) => dispatch(updatemessageSystem(data)),
  }
}

const mapStateToProps = (state) => {
  return {
    message_system: state.session.getIn(['message_system']),
  }
}

SignupForm = reduxForm({
  form: 'signup',
  validate,
  enableReinitialize: true,
})(SignupForm)

export default connect(mapStateToProps, mapDispatchToProps)(SignupForm)
