import React, { Component } from 'react'
import { connect } from 'react-redux'
import Slider from 'material-ui/Slider'
import TextField from 'material-ui/TextField'
import Paper from 'material-ui/Paper'
import { toJS } from 'immutable'
import { findMatchs } from '../../../actions/User'
import RaisedButton from 'material-ui/RaisedButton'
import { RadioButton, RadioButtonGroup } from 'material-ui/RadioButton'
import Checkbox from 'material-ui/Checkbox'
import Avatar from 'material-ui/Avatar'
import DatePicker from 'material-ui/DatePicker'
import ChipInput from 'material-ui-chip-input'
import { pullUser, cleanUser, filterByTags, filterByAge, filterByDistance, filterByPopularity } from '../../../actions/User'
import Divider from 'material-ui/Divider'
import { withRouter } from 'react-router'
import { push } from 'react-router-redux'
import MenuItem from 'material-ui/MenuItem'
import DropDownMenu from 'material-ui/DropDownMenu'
import moment from 'moment'
import _ from 'lodash'

import {
  radioButtonStyle,
  radioButtonStyleError,
  radioButtonStyleNormal,
} from './style'

class find extends Component {

  constructor (props) {
    super(props)
    this.state = {
      height: props.height,
      width: props.width,
      age: 18,
      km: 150,
      male: !!((this.props.session.data_user.targetsexe === 1 || this.props.session.data_user.targetsexe === 3)),
      female: !!((this.props.session.data_user.targetsexe === 2 || this.props.session.data_user.targetsexe === 3)),
      popularity: 1,
      tags: 1,
      ageFind: 1,
      distance: 1,
      poValue: 0,
      tagValue: 0,
    }
  }
  componentWillMount () {
    this.setState({ height: window.innerHeight * 0.88 })
  }

  findMatch = (gender) => {
    const { age, km, poValue, tagValue } = this.state
    const { coords } = this.props
    const data_user = this.props.session.data_user
    let array = []
    array = _.union(data_user.matchs, data_user.blocked)

    const toSend = {
      myGender: data_user.gender,
      age,
      km,
      male: gender.male,
      female: gender.female,
      latitude: coords.latitude,
      longitude: coords.longitude,
      popularity: poValue,
      tagValue,
      blocked: array,
      myTags: data_user.tags
    }
    if ((gender.male || gender.female) && data_user.id) {
      this.props.dispatch(pullUser(toSend, data_user.id))
    } 
  }

  handleChangePopularity = (event, index, value) => {
    this.setState({ popularity: value })
    this.props.dispatch(filterByPopularity(value))
  }

  handleChangeTags = (event, index, value) => {
    this.setState({ tags: value })
    this.props.dispatch(filterByTags(value))
  }

  handleAge = (event, index, value) => {
    this.setState({ ageFind: value })
    this.props.dispatch(filterByAge(value))
  }

  handleDistance = (event, index, value) => {
    this.setState({ distance: value })
    this.props.dispatch(filterByDistance(value))
  }

  render () {

    const { handleSubmit, coords, session } = this.props
    const statusButton = this.props.session.statusButton
    const { age, km, male, female, popularity, tags, poValue, tagValue, ageFind, distance } = this.state

    return (
      <Paper style={{ display: 'flex', flexDirection: 'column', width: '15%', padding: '30px', height: this.state.height, marginRight: '15px' }}>
        {session && session.data_user && session.data_user.longitude && (
          <div style={{ alignSelf: 'center', display: 'flex', flexDirection: 'column', alignItems: 'center' }}>
            <Avatar
              src={session.data_user.image1 || 'https://www.workidol.com/assets/images/common/profile.png'}
              style={{height: '75%', width: '75%'}}
            />
            <p style={{ margin: '10px' }}>{session.data_user.firstname}</p>
            <p style={{ marginBottom: '10px' }}>Popularity: {session.data_user.popularity}</p>
            <RaisedButton
              label={'Edit'}
              disabled={statusButton}
              onClick={() => { this.props.router.push('/profile') }}
            />
            <Divider style={{ width: '100%', marginBottom: '50px', marginTop: '50px' }}/>
          </div>
        )}
          {session && session.data_user && session.data_user.longitude && (
        <div style={{ alignSelf: 'flex-start', padding: '19px' }}>

          <p style={{ marginBottom: '20px' }}>Loocking for:</p>
          <div onClick={() => { if (statusButton === false) { this.setState({ male: !male }); this.findMatch({ male: !male, female }) } }} >
            <Checkbox
              label={'Male'}
              checked={male}
            />
          </div>
          <div onClick={() => { if (statusButton === false) { this.setState({ female: !female }); this.findMatch({ male, female: !female }) } }} >
            <Checkbox
              label={'Female'}
              checked={female}
            />
          </div>
        </div>
      )}
        {session && session.data_user && session.data_user.longitude && (
        <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'flex-center', height: '5%'}}>
          <p style={{height: '1%'}}>{`${age || 18} age`}</p>
          <Slider
            disabled={statusButton}
            style={{ width: '100%'}}
            min={18}
            max={80}
            step={1}
            value={Number(age)}
            onChange={(e, inp) => { if (statusButton === false) { this.setState({ age: inp }); this.findMatch({ male, female }) } }}
          />
        </div>
      )}
      {session && session.data_user && session.data_user.longitude && (
        <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'flex-center', height: '5%' }}>
          <p style={{height: '1%'}}>{`${km || 150} KM`}</p>
          <Slider
            disabled={statusButton}
            style={{ width: '100%' }}
            min={1}
            max={150}
            step={150 / 100}
            value={Number(km)}
            onChange={(e, inp) => { if (statusButton === false) { this.setState({ km: inp }); this.findMatch({male, female}) } }}
          />
        </div>
      )}
          {session && session.data_user && session.data_user.longitude && (
        <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'flex-center', height: '5%' }}>
          <p style={{height: '1%'}}>{`${poValue || 0} Popularity`}</p>
          <Slider
            disabled={statusButton}
            style={{ width: '100%' }}
            min={0}
            max={100}
            step={1}
            value={Number(poValue)}
            onChange={(e, inp) => { if (statusButton === false) { this.setState({ poValue: inp }); this.findMatch({ male, female }) } }}
          />
        </div>
      )}
          {session && session.data_user && session.data_user.longitude && (
        <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'flex-center', height: '5%' }}>
          <p style={{height: '1%'}}>{`${tagValue || 0} Tags`}</p>
          <Slider
            disabled={statusButton}
            style={{ width: '100%' }}
            min={0}
            max={5}
            step={1}
            value={Number(tagValue)}
            onChange={(e, inp) => { if (statusButton === false) { this.setState({ tagValue: inp }); this.findMatch({ male, female }) } }}
          />
        </div>
      )}
        <Divider style={{ width: '100%', marginBottom: '30px', marginTop: '30px' }}/>
          {session && session.data_user && session.data_user.longitude && (
        <div style={{height: 'auto', width: '100%'}}>
          <p style={{marginTop: '15px'}}>{'Sort by '}</p>
          <DropDownMenu
            value={popularity}
            onChange={this.handleChangePopularity}
            disabled={statusButton}
            style={{height: '100%', width: '100%'}}
          >
            <MenuItem value={1} onClick={() => { this.setState({ popularity: 1 }) }} primaryText='Popularity Growing order' />
            <MenuItem value={2} onClick={() => { this.setState({ popularity: 2 }) }} primaryText='Popularity Desending order' />
          </DropDownMenu>
          <DropDownMenu
            value={tags}
            onChange={this.handleChangeTags}
            disabled={statusButton}
            style={{height: '100%', width: '100%'}}

          >
            <MenuItem value={1} onClick={() => { this.setState({ tags: 1 }) }} primaryText='Communs Tags Growing order' />
            <MenuItem value={2} onClick={() => { this.setState({ tags: 2 }) }} primaryText='Communs Tags Desending order' />
          </DropDownMenu>
          <DropDownMenu
            value={ageFind}
            onChange={this.handleAge}
            disabled={statusButton}
            style={{height: '100%', width: '100%'}}

          >
            <MenuItem value={1} onClick={() => { this.setState({ tags: 1 }) }} primaryText='Age Growing order' />
            <MenuItem value={2} onClick={() => { this.setState({ tags: 2 }) }} primaryText='Age Desending order' />
          </DropDownMenu>
          <DropDownMenu
            value={distance}
            onChange={this.handleDistance}
            disabled={statusButton}
            style={{height: '100%', width: '100%'}}

          >
            <MenuItem value={1} onClick={() => { this.setState({ tags: 1 }) }} primaryText='Distance Growing order' />
            <MenuItem value={2} onClick={() => { this.setState({ tags: 2 }) }} primaryText='Distance Desending order' />
          </DropDownMenu>
        </div>
      )}
      </Paper>
    )
  }
}

const mapStateToProps = state => {
  const session = state.session.toJS()
  if (session && session.data_user && session.data_user.longitude && session.data_user.latitude){
    const coords = {
      latitude: session.data_user.latitude,
      longitude: session.data_user.longitude
    }
    return {
      session: state.session.toJS(),
      coords,
    }
  }
  return {
    session: state.session.toJS()
  }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

find = connect(mapStateToProps, mapDispatchToProps)(find)

export default withRouter(find)
