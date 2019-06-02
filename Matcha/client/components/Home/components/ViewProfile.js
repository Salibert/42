import React, { Component } from 'react'
import { connect } from 'react-redux'
import { GridList, GridTile } from 'material-ui/GridList'
import { Card, CardActions, CardHeader, CardMedia, CardTitle, CardText } from 'material-ui/Card'
import { socketLike, socketBlock, socketReport } from '../../../actions/Modal'
import ActionFavorite from '../../MyIcon/ActionFavorite.js'
import ActionFavoriteBorder from '../../MyIcon/ActionFavoriteBorder.js'
import ActionLockOpen from '../../MyIcon/ActionLockOpen.js'
import ActionLock from '../../MyIcon/ActionLock.js'
import ActionGrade from '../../MyIcon/ActionGrade.js'
import ActionRoom from '../../MyIcon/ActionRoom.js'
import SocialMood from '../../MyIcon/SocialMood.js'
import NotificationWc from '../../MyIcon/NotificationWc.js'
import SocialMoodBad from '../../MyIcon/SocialMoodBad.js'
import ActionFace from '../../MyIcon/ActionFace.js'
import { IconButton, RaisedButton } from 'material-ui'
import NavigationCancel from '../../MyIcon/NavigationCancel.js'
import { statusModal } from '../../../actions/Modal'
import Chip from 'material-ui/Chip'
import Paper from 'material-ui/Paper'
import moment from 'moment'

const styles = {
  root: {
    display: 'flex',
    flexWrap: 'wrap',
    justifyContent: 'space-around',
  },
  gridList: {
    width: 200,
    height:'100%',
    overflowY: 'auto',
  },
}

class ViewProfile extends Component {

  userBlock = () => {
    const { data, status } = this.props
    const id = this.props.session.data_user.id
    this.props.dispatch(socketBlock(id, data.profile.id, data.key, status ))
  }

  userReport = () => {
    const { data, status } = this.props
    const { id } = this.props.session.data_user
    this.props.dispatch(socketReport(id, data.profile.id, data.key, status ))
  }

  userLike = () => {
    const { data, status } = this.props
    const { id } = this.props.session.data_user
    this.props.dispatch(socketLike(id, data.profile.id, data.key, status ))
  }

  render () {
    const { data, closeModal } = this.props
    const profile = data.profile
    const { data_user } = this.props.session
    const imageProfile = [profile.image1, profile.image2, profile.image3, profile.image4, profile.image5]
    let targetsexe = "Bisexual"
    if (profile.targetsexe === 1){
      targetsexe = "Homme"
    } else if (profile.targetsexe === 2){
      targetsexe = "Femme"
    }

    profile.bio = 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
    const sexe = profile.gender === 1 ? 'Homme' : 'Femme'
    const Tags = profile.tags.map((value, key) => <Chip key={key} style={{ margin: '8px' }}> {value} </Chip>)
    return (
      <div style={{display: 'flex', flexDirection: 'column', padding: '20px', backgroundColor:'#fff7f7'}}>
      <div style={{display: 'flex', flexDirection: 'row', alignSelf: 'flex-end',flexDirection: 'center', alignItems:'center'}}>
        <IconButton tooltip='Exit profile' style={{textAlign: 'right'}} touch={true} tooltipPosition='bottom-left' onClick={closeModal} ><NavigationCancel color='black' /></IconButton>
      </div>
      <p style={{marginBottom: '5px', marginTop: '10px' ,fontSize: '1.6rem'}}>{`${profile.login}`}</p>
      <div style={{display: 'flex', flexDirection: 'row'}}>
      <div style={{display: 'flex', flexDirection: 'row'}}><IconButton tooltip='location' tooltipPosition='top-left'><ActionRoom color='black' /></IconButton><p style={{marginTop: '17px', fontSize: '0.9rem'}}>{`${profile.localisation || 1}km`}</p></div>
      <div style={{display: 'flex', flexDirection: 'row', marginLeft: '17px'}}><IconButton tooltip='sexe' tooltipPosition='top-left'><NotificationWc color='black' /></IconButton><p style={{marginTop: '17px', fontSize: '0.9rem'}}>{`${sexe}`}</p></div>
      <div style={{display: 'flex', flexDirection: 'row', marginLeft: '17px'}}><IconButton tooltip='age' tooltipPosition='top-left'><ActionFace color='black' /></IconButton><p style={{marginTop: '17px', fontSize: '0.9rem'}}>{ moment(profile.birthdate).isValid() ? moment(profile.birthdate).fromNow(true) : '18 years' }</p></div>
      <div style={{display: 'flex', flexDirection: 'row', marginLeft: '17px'}}><IconButton tooltip='sexy attraction' tooltipPosition='top-left'><ActionFavorite color='black' /></IconButton><p style={{marginTop: '17px', fontSize: '0.9rem'}}>{`${targetsexe}`}</p></div>
      <div style={{display: 'flex', flexDirection: 'row', marginLeft: '17px',}}><IconButton tooltip='popularity' tooltipPosition='top-left' style={{padding: '0px'}}><ActionGrade color='black' /></IconButton><p style={{marginTop: '17px', fontSize: '0.9rem'}}>{`${profile.popularity || 0}`}</p></div>
      </div>
      <div style={{display: 'flex', flexDirection: 'row', height: '250px', width: '100%' ,overflow: 'scroll', overflowY: 'hidden', overflowX: 'auto', marginTop: '1%'}}>
      {imageProfile.map((image, key) => (
        <img style={{marginLeft: '10px', height: '100%', width: 'auto'}} key={key} src={image || 'https://www.workidol.com/assets/images/common/profile.png'} />
      ))}
      </div>
      <Paper style={{marginTop: '20px', marginLeft: '10px', marginBottom: '20px', padding: '20px', height: '250px'}} zDepth={2}>
      <p style={{marginBottom: '10px', fontSize:'1.5rem'}}>{`${profile.firstname} ${profile.lastname}`}</p>
      <p style={{marginBottom: '10px', fontSize:'1rem'}}>{'Biographie:'}</p>
      <p style={{marginBottom: '10px', fontSize:'0.7rem'}}>{profile.bio}</p>
      <h2>{'Tags:'}</h2>
      <div style={{display: 'flex', flexDirection: 'row'}}>
      { Tags ? Tags : <div/>}
      </div>
      </Paper>
      <div style={{display: 'flex', flexDirection: 'row'}}>
      {  profile.usr_report.indexOf(data_user.id) === -1 ? (
        <Paper style={{padding: '10px', margin: '10px'}}>
        <IconButton tooltip='Report a user' onClick={this.userReport} touch={true} tooltipPosition='top-left'><SocialMoodBad color='black' /></IconButton>
        </Paper>
      ) : (
        <Paper style={{padding: '10px', margin: '10px'}}>
        <IconButton tooltip='Report a user' onClick={this.userReport} touch={true} tooltipPosition='top-left'><SocialMood color='black' /></IconButton>
        </Paper>
      )}
      { data_user.myblock.indexOf(profile.id) === -1 ? (
        <Paper style={{padding: '10px', margin: '10px'}}>
        <IconButton tooltip='Block a user' touch={true} onClick={this.userBlock} tooltipPosition='top-left'><ActionLock color='black' /></IconButton>
        </Paper>
      ) : (
        <Paper style={{padding: '10px', margin: '10px'}}>
        <IconButton  tooltip='Disblock a user' touch={true} onClick={this.userBlock} tooltipPosition='top-left'><ActionLockOpen color='black' /></IconButton>
        </Paper>
      )}
      { data_user.myblock.indexOf(profile.id) === -1 && (
        <div>
          { data_user.mylike.indexOf(profile.id) === -1 ? (
            <Paper style={{padding: '10px', margin: '10px'}}>
            <IconButton tooltip='Like a user' touch={true} onClick={this.userLike} tooltipPosition='top-left' ><ActionFavoriteBorder color='pink' /></IconButton>
            </Paper>
          ) : (
            <Paper style={{padding: '10px', margin: '10px'}}>
            <IconButton tooltip='Dislike a user' touch={true} onClick={this.userLike} tooltipPosition='top-left'>{
              data_user.matchs.indexOf(profile.id) != -1 ? <ActionGrade color='red' /> : <ActionFavorite color='red' /> }
              </IconButton>
            </Paper>
          )}
        </div>
      )}
    </div>
    </div>
  )
}
}

const mapStateToProps = state => {
  return {
    session: state.session.toJS(),
  }
}

const mapDispatchToProps = dispatch => {
  return { dispatch }
}

ViewProfile = connect(mapStateToProps, mapDispatchToProps)(ViewProfile)

export default ViewProfile
