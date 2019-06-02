import React, { Component } from 'react'
import PropTypes from 'prop-types'
import { connect } from 'react-redux'
import { TextField, RaisedButton } from 'material-ui'
import Paper from 'material-ui/Paper'
import { Field, reduxForm } from 'redux-form'
import { callApi } from '../../service/apiCaller'
import { closeToster, addToster } from '../../actions/Toaster/index.js'
import './style.scss'

class HelpUser extends Component {

  state = {
    user: {
      email: ''
    },
    errorMessage: '',
    send: false,
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
    const query = this.props.location.query
    callApi(`usr/actionUser/${query.action}/${event.email}`, 'get').then(res => {
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
          <Field name='email' component={this.renderTextField} label='email' />
          <RaisedButton label='Submit' primary={true} type='submit' />
        </form>
      </Paper>
    )
  }
}

HelpUser.propTypes = {
  state: PropTypes.object,
  updatemessageSystem: PropTypes.func,
}

HelpUser.contextTypes = {
  router: PropTypes.object,
}
const validate = values => {

  const errors = {}
  const requiredFields = ['email']

  requiredFields.forEach(field => {
    if (!values[field]) {
      errors[field] = 'Required'
    }
  })
  if (!values.email || !values.email.match(/^[\w\-\+]+(\.[\w\-]+)*@[\w\-]+(\.[\w\-]+)*\.[\w\-]{2,}$/)) {
    errors.email = 'Your email is not valid'
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

HelpUser = reduxForm({
  form: 'signup',
  validate,
  enableReinitialize: true,
})(HelpUser)

export default connect(mapStateToProps, mapDispatchToProps)(HelpUser)
