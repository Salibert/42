import React, { Component } from 'react'
import { connect } from 'react-redux'
import { Field, reduxForm } from 'redux-form'
import Slider from 'material-ui/Slider'
import TextField from 'material-ui/TextField'
import Paper from 'material-ui/Paper'
import { toJS } from 'immutable'
import { updateUser, pullMatchs } from '../../actions/User'
import RaisedButton from 'material-ui/RaisedButton'
import { RadioButton, RadioButtonGroup } from 'material-ui/RadioButton'
import Checkbox from 'material-ui/Checkbox'
import Avatar from 'material-ui/Avatar'
import DatePicker from 'material-ui/DatePicker'
import ChipInput from 'material-ui-chip-input'
import { checkState } from '../../actions/User/index'
import UploadPictures from './components/UploadPictures.js'
import { getCookie } from '../../service/cookies.service.js'
import request from 'superagent'
import _ from 'lodash'


import {
  radioButtonStyle,
  radioButtonStyleError,
  radioButtonStyleNormal,
} from './style'

import { Map, InfoWindow, Marker, GoogleApiWrapper } from 'google-maps-react'

class GeneralTab extends Component {
  ;

  state = {
    slider: 1,
    lat: 0,
    lng: 0,
  };

  componentDidMount () {
    let url = window.location.href.split('/'),
      string = url[3]
    if (!this.props.data_user && (string !== 'signin' && string !== 'signup')) {
      getCookie().then(dataUser => {
        this.props.dispatch(checkState(dataUser))
    })
    }

  }
  componentWillReceiveProps (nextProps) {
    if (nextProps.session && nextProps.session.data_user && (!nextProps.session.data_user.latitude || !nextProps.session.data_user.longitude)) {
        request.get('https://freegeoip.net/json/')
          .set('Access-Control-Allow-Origin')
          .then((res) => {
            this.props.dispatch(updateUser(this.props.session.data_user.login, {}, { lat: res.body.latitude, lng: res.body.longitude }))
          })
    }
    if(!this.props.session.data_user && nextProps.session && nextProps.session.data_user) {
      this.props.dispatch(pullMatchs(nextProps.session.data_user.id,nextProps.session.data_user.matchs))

    }
  }

  renderRadioButton = ({ input, meta: { touched, error } }) => {
    const arrayOfName = ['Male', 'Female']
    return (
      <RadioButtonGroup
        style={{ width: '49%', display: 'flex', flexDirection: 'column', justifyContent: 'flex-start', alignItems: 'flex-start', marginRight: '20px', flexShrink: 0, flexWrap: 'wrap', height: '90px' }}
        name='categories'
        defaultSelected={Number(input.value)}
        onChange={(a, b) => { input.onChange(a, b) }}
      >
        {arrayOfName.map((value, key) => {
          return (
            <RadioButton
              key={key}
              value={key + 1}
              label={value}
              iconStyle={(touched && error) ? radioButtonStyleError : radioButtonStyleNormal}
            />
          )
        })}
      </RadioButtonGroup>
    )
  }
  renderDate = ({ meta: { touched, error }, input, label }) => {
    const maxDate = new Date()
    let defaultDate1 = null
    if (input.value) { defaultDate1 = new Date(input.value) }
    maxDate.setFullYear(maxDate.getFullYear() - 18)
    maxDate.setHours(0, 0, 0, 0)

    return (
      <DatePicker
        maxDate={maxDate}
        floatingLabelText='Birth Date'
        onChange={(e, a) => { input.onChange(a) }}
        defaultDate={defaultDate1 || maxDate }
      />
    )
  }
  renderTextField = ({ input, label, meta: { touched, error }, ...custom }) => (
    <TextField
      style={{ width: '100%', marginBottom: '10px', height: '65px' }}
      inputStyle={{ fontWeight: 100, fontSize: '1.2em' }}
      floatingLabelStyle={{ color: '#3F51B5', fontWeight: 400 }}
      underlineFocusStyle={{ borderColor: '#ff3b7f' }}
      hintText={label}
      floatingLabelText={label}
      errorText={touched && error}
      {...input}
      {...custom}
    />
  )
  renderCheckBox = ({ meta: { touched, error }, input, label }) => {
    return (
      <div onClick={() => { input.onChange(!input.value) }} >
        <Checkbox
          label={label}
          checked={Boolean(input.value)}
          iconStyle={(touched && error) ? radioButtonStyleError : radioButtonStyleNormal}
        />
      </div>
    )
  }
  renderSlider = ({ meta: { touched, error }, input, label }) => {
    return (
      <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'flex-center' }}>
        <p>{`${input.value || 1} KM`}</p>
        <Slider
          style={{ width: '100%' }}
          min={1}
          max={150}
          step={150 / 100}
          value={Number(input)}
          onChange={(e, inp) => { input.onChange(inp) }}
        />
      </div>
    )
  }
  renderTags = ({ input, meta: { touched, error } }) => {
    return (
      <div>
        <ChipInput
          style={{ width: '100%', height: '80px' }}
          values={input.value || []}
          onChange={e => { input.onChange(e) }}
          defaultValue={input.value || []}
          errorText={touched && error}
        />
      </div>
    )
  }

  onSubmit = (event) => {
    const { data_user } = this.props.session
    const { lat, lng } = this.state

    if (lat === 0 || lng === 0) { this.props.dispatch(updateUser(data_user.login, event, {lat: null, lng: null}))
    } else {
      this.props.dispatch(updateUser(data_user.login, event, { lat, lng }))
    }
  }

  render () {
    const { handleSubmit, initialValues, session } = this.props
    const { lat, lng } = this.state
    return (
      <div>
    {session && session.data_user && (

        <Paper style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', padding: '20px', marginBottom: '30px', overflow: 'auto' }}>
          <UploadPictures />
          <form onSubmit={handleSubmit(this.onSubmit)}>
            <Field name='firstname' component={this.renderTextField} label='Firstname' />
            <Field name='lastname' component={this.renderTextField} label='Lastname' />
            <Field name='birthdate' component={this.renderDate} label='Birth Date' />
            <Field name='email' component={this.renderTextField} label='Email' />
            <Field name='password' component={this.renderTextField} label='Password' type='password' />
            <Field name='biographie' component={this.renderTextField} label='Biographie' />
            <p>Chose your position</p>
            <div style={{ height: '250px', marginBottom: '10px', marginBottom: '10px', width: '75%', position: 'relative' }}>
              <Map google={this.props.google}  clickableIcons={false} zoom={9} style={{ height: 'auto', width: 'auto' }} initialCenter={{ lat: session.data_user.latitude || 47, lng: session.data_user.longitude || 2 }} onClick={(e, a, c) => { this.setState({ lat: c.latLng.lat(), lng: c.latLng.lng() }) }}>
                <Marker
                  position={{ lat: lat || session.data_user.latitude, lng: lng || session.data_user.longitude }}
                  name={'Current location'} />
              </Map>
            </div>
            <p>Tags / Interests</p>
            <Field name='tags' component={this.renderTags} type='text' />
            <Field name='gender' component={this.renderRadioButton} />
            <RaisedButton label='Submit' primary={true} type='submit' style={{ marginRight: '10px' }} />
            <RaisedButton label='back' primary={true} onClick={() => { this.props.router.push('/home') }} />
          </form>
        </Paper>
      )}
      </div>
    )
  }
}

const mapStateToProps = state => {
  const session = state.session.toJS()

  const maxDate = new Date()
  maxDate.setFullYear(maxDate.getFullYear() - 18)
  maxDate.setHours(0, 0, 0, 0)

  if (session.data_user) {
    let tags = session.data_user.tags
    if (!Array.isArray(session.data_user.tags)) {
      tags = result.tags = _.pull(_.split(result.tags , "/"), "")
    }
    return {
      initialValues: {
        firstname: session.data_user.firstname,
        lastname: session.data_user.lastname,
        birthdate: session.data_user.birthdate ? session.data_user.birthdate : maxDate,
        email: session.data_user.email,
        biographie: session.data_user.bio,
        tags: session.data_user.tags,
        gender: session.data_user.gender,
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
const validate = values => {

  const errors = {}
  const requiredFields = ['firstname', 'lastname', 'email', 'biographie', 'gender', 'birthdate']

  requiredFields.forEach(field => {
    if (!values[field] && field != 'lookMale' && field != 'lookFemale') {
      errors[field] = 'Required'
    }
  })
  if (!values.lookMale && !values.lookMale) {
    errors.lookMale = true
    errors.lookFemale = true
  }
  if (values.email && !(/^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}$/i).test(values.email)) {
    errors.email = 'Invalid email address'
  }
  return errors
}

GeneralTab = reduxForm({
  form: 'generalTab',
  validate,
  enableReinitialize: true,
})(GeneralTab)

GeneralTab = connect(mapStateToProps, mapDispatchToProps)(GeneralTab)

export default GoogleApiWrapper({
  apiKey: ('AIzaSyB8Y5W7e7F2fKakCNCUxdG_wYw_MYDQpL0'),
})(GeneralTab)
