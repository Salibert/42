import React from 'react'
import { Input, Button } from 'antd';
import { hypothesis } from '../../utils/linearRegression';
class EstimationPrice extends React.Component {
  state = {
    number: "",
    result: 0
  }

  handleChange = (e) => {
    this.setState({ number: e.target.number });
  }

  handleNumberChange = (e) => {
    const number = Number(e.target.value);
    if (Number.isNaN(number)) {
      return;
    }
    if (!('value' in this.props)) {
      this.setState({ number });
    }
  }

  check = () => {
    let result = hypothesis(this.state.number)
    if (isNaN(result) || result < 0) { result = 0 }
    this.setState({ result })
  }

  render(){
    return (
      <div style={{display:'flex', flexDirection:'column', alignContent:'center', marginTop:'15px'}}>
        <span>
          <Input
            type="text"
            placeholder="enter mileage"
            value={this.state.number}
            onChange={this.handleNumberChange}
            style={{ width: '60%', marginRight: '3%' }}
          />
          <Button type='primary' onClick={this.check}>Validate</Button>
        </span>
        <div style={{marginLeft: '10px'}}>
        {
          this.state.result !== 0 ? <div style={{alignText:'center'}}>
            <span style={{fontSize:'3em'}}>{this.state.result.toFixed(2)}</span>
            <span style={{fontSize:'1.5em'}}> $</span>
          </div> : <div >
            <span style={{fontSize:'3em'}} >0</span>
            <span style={{fontSize:'1.5em'}}> $</span>
          </div>
        }
        </div>
      </div>
    )
  }
}

export default EstimationPrice