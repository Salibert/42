import React, { Component } from 'react'

class Footer extends Component {

  constructor (props) {
    super(props)
    this.state = { height: props.height, width: props.width }
  }
  componentWillMount () {
    this.setState({ height: window.innerHeight * 0.96 })
  }

  render () {
    return (
      <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', fontSize: '0.8em', marginBottom: '10px' }}>
        <div style={{ display: 'flex', flexDirection: 'row' }}>
          <a style={{ padding: '5px' }} target='_blank' href='mailto:salibert@student.42.fr' alt='Contact' >
            {'Contact'}
          </a>

          <a style={{ padding: '5px' }} target='_blank' href='https://github.com/salibert' alt='Github'>
            {'Github'}
          </a>

          <a style={{ padding: '5px' }} target='_blank' href='https://profile.intra.42.fr/users/salibert' alt='Intra42'>
            {'Intra42'}
          </a>
          <div style={{ padding: '5px' }} dangerouslySetInnerHTML={{ __html: '&copy;&nbsp;DateMe' }} />
        </div>
        <div>
          {'Salibert'}
        </div>
      </div>
    )
  }

}

export default Footer
