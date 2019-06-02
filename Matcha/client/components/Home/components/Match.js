import React, { Component } from 'react'
import { connect } from 'react-redux'
import CardProfil from '../../CardProfil'
import { Field, reduxForm } from 'redux-form'
import { GridList, GridTile } from 'material-ui/GridList'
import { Paper } from 'material-ui'
import { toJS } from 'immutable'
import { pullUser } from '../../../actions/User'
class MatchForm extends Component {

  constructor (props) {
    super(props)
    this.state = {
      height: props.height,
      width: props.width,
    }
  }

  componentWillMount () {
    this.setState({ height: window.innerHeight * 0.88 })
    let array = []
    array = _.union(this.props.session.data_user.matchs, this.props.session.data_user.blocked)
    this.props.dispatch(pullUser({
      age: 18,
      male: !!((this.props.session.data_user.targetsexe === 1 || this.props.session.data_user.targetsexe === 3)),
      female: !!((this.props.session.data_user.targetsexe === 2 || this.props.session.data_user.targetsexe === 3)),
      longitude: this.props.session.data_user.longitude,
      latitude: this.props.session.data_user.latitude,
      tagValue: 0,
      km: 150,
      blocked: array
    }, this.props.session.data_user.id))
  }

  render () {
    const { other_User } = this.props
    if (!other_User) { return null }
    return (
      <div style={{ width: '70%', height: this.state.height, overflow: 'auto', overflowX: 'hidden', padding: '0.5% 1%' }}>
        <GridList style={{ display: 'flex', flexWrap: 'wrap', justyfyContent: 'space-around' }}
          cols={5}
          cellHeight={this.state.height * 0.25}
          padding={15}
        >
          {other_User.data.map((value, key) => <CardProfil data={{ profile: value, key }} key={key} />)}
        </GridList>
      </div>
    )
  }
}

const mapStateToProps = (state) => {
  const session = state.session.toJS()
  let other_User = null
  if (session.other_User) {
    other_User = session.other_User
  }
  return {
    other_User,
    session,
  }
}

const mapDispatchToProps = (dispatch) => {
  return { dispatch }
}

const MatchContainer = connect(
  mapStateToProps,
  mapDispatchToProps
)(MatchForm)

export default MatchContainer
