import React, { Component } from 'react'
import { connect } from 'react-redux'
import Slider from 'material-ui/Slider'
import TextField from 'material-ui/TextField'
import Paper from 'material-ui/Paper'
import { toJS } from 'immutable'
import RaisedButton from 'material-ui/RaisedButton'
import { RadioButton, RadioButtonGroup } from 'material-ui/RadioButton'
import Checkbox from 'material-ui/Checkbox'
import Avatar from 'material-ui/Avatar'
import DatePicker from 'material-ui/DatePicker'
import ChipInput from 'material-ui-chip-input'
import { pullUser } from '../../../actions/User'
import Card from './cards.js'
import {
  radioButtonStyle,
  radioButtonStyleError,
  radioButtonStyleNormal,
} from './style'
import Divider from 'material-ui/Divider'

import { pullMatchs } from '../../../actions/User'
class find extends Component {

  
  constructor (props) {
    super(props)
    this.state = { height: props.height }
  }
  componentWillMount () {
    this.setState({ height: window.innerHeight })
    this.props.dispatch(pullMatchs(this.props.session.data_user.id,this.props.session.data_user.matchs))
  }

  render () {

    const { session, matchs } = this.props
    return (
      <Paper style={{ display: 'flex', flexDirection: 'column', padding: '10px', height: 'auto', justifyContent: 'flex-start', flexGrow: '1', maxHeight: this.state.height, marginLeft: '15px' }}>
        <h2 style={{ marginBottom: '10px', textAlign: 'center', fontSize: '1.7em' }}>Your matchs</h2>
        <Divider style={{ width: 'auto', marginBottom: '20px' }}/>
        {matchs && Array.isArray(matchs) && session.data_user && (
          matchs.map((e, key) =>
            <div key={key}>
              <Card me={session.data_user} info={e}/>
              {key < matchs.length - 1 && (<Divider style={{ width: 'auto' }}/>)}
            </div>
          )
        )}
      </Paper>
    )
  }
}

const mapStateToProps = state => {
  let matchs = null
  const session = state.session.toJS()
  if (session.matchs) { matchs = session.matchs }
  return {
    session,
    matchs,
  }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

find = connect(mapStateToProps, mapDispatchToProps)(find)

export default find
