import { MenuItem, SelectField, IconButton, RaisedButton } from 'material-ui'
import { Card, CardText, CardHeader, CardMedia, CardTitle } from 'material-ui/Card'
import { GridList, GridTile } from 'material-ui/GridList'
import React, { Component } from 'react'
import { connect } from 'react-redux'
import Dropzone from 'react-dropzone'
import { toJS } from 'immutable'
import { uploadPicture } from '../../../actions/User'
import { Field, reduxForm } from 'redux-form'

const styles = {
  root: {
  },
  gridList: {
    display: 'flex',
    flexWrap: 'nowrap',
    overflowX: 'auto',
  },
  titleStyle: {
    color: 'rgb(0, 188, 212)',
  },
}

const validate = values => {
  const errors = {}
  // const requiredFields = ['imageProfile'];
  //
  // requiredFields.forEach(field => {
  //   if (!values[field]) {
  //     errors[field] = 'Required';
  //   }
  // });
}

const adaptFileEventToValue = delegate => e => delegate(e.target.files[0])

class UploadPictures extends Component {
  state = {
    nbrPicture: 1,
  }

  handleNumeroPicture = (e, index, value) => {
    this.setState({ nbrPicture: value })
  }

  onSubmit = (e) => {
    const data = new FormData()
    data.append('file', e.imageProfile)
    this.props.dispatch(uploadPicture(this.props.session.data_user.login, this.state.nbrPicture + 1, data))
  }

  fileInput = ({ input, input: { value: omitValue, onChange, onBlur, ...inputProps }, meta: omitMeta, ...props }) => {
    return (
      <div>
        <RaisedButton containerElement='label' label='Brows' primary={true}>
          <input
            style={{ display: 'none' }}
            onChange={adaptFileEventToValue(onChange)}
            onBlur={adaptFileEventToValue(onBlur)}
            type='file'
            {...inputProps}
            {...props}
          />
        </RaisedButton>
        {input.value && (
          <p>{input.value.name}</p>
        )}
      </div>
    )
  }

  render () {

    const { session, pictures, handleSubmit } = this.props
    const { data_user } = session
    let items = [],
      imageProfile = []
    if (data_user) {
      imageProfile = [
        { img: pictures.image1, title: 'Picture Profile' },
        { img: pictures.image2, title: 'Picture 2' },
        { img: pictures.image3, title: 'Picture 3' },
        { img: pictures.image4, title: 'Picture 4' },
        { img: pictures.image5, title: 'Picture 5' },
      ]
    }

    for (let i = 0; i < 5; i++) {
      items.push(<MenuItem value={i} key={i} primaryText={`modifier photo ${i + 1}`} />)
    }
    return (
      <div style={{ width: '30%', height: '30%', display: 'flex', flexDirection: 'row' }}>
        {imageProfile.map((picture, key) => (
          <img key={key} style={{ padding: '10px', height: '20%', width: '20%' }} src={picture.img || 'https://www.workidol.com/assets/images/common/profile.png'} />

        ))}
        <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'flex-start', justifyContent: 'center' }}>
          <form onSubmit={handleSubmit(this.onSubmit)}>
            <Field name='imageProfile' component={this.fileInput} />
            <RaisedButton label='Add the picture' primary={true} style={{ marginTop: '10px', marginBottom: '10px' }} type='submit' />
          </form>
          <SelectField
            value={this.state.nbrPicture}
            onChange={this.handleNumeroPicture}
            maxHeight={200}
          >
            {items}
          </SelectField>
        </div>
      </div>
    )
  }
}

const mapStateToProps = state => {
  const session = state.session.toJS()
  if (session.data_user) {
    return {
      pictures: {
        image1: session.data_user.image1,
        image2: session.data_user.image2,
        image3: session.data_user.image3,
        image4: session.data_user.image4,
        image5: session.data_user.image5,
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

UploadPictures = reduxForm({
  form: 'UploadPictures',
  validate,
  enableReinitialize: true,
})(UploadPictures)

UploadPictures = connect(mapStateToProps, mapDispatchToProps)(UploadPictures)

export default UploadPictures
