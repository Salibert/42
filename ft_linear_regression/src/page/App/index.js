import React, { Component } from 'react';
import 'antd/dist/antd.css'
import './index.css';
import Chart from '../../component/Chart'
import EstimationPrice from '../../component/EstimationPrice'
import Theta from '../../component/Theta'
import Modify from '../../component/Modify'
import { iter, hypothesis } from '../../utils/linearRegression';
import { Button } from 'antd'
import CsvReader from '../../component/Csv/CSVDataSet'
import CsvTheta from '../../component/Csv/CSVTheta'

global.data = { theta: [0, 0], cost: 0 }

class App extends Component {

  state = {
    dataSet: [[],[]],
    cvsIsUpload: false,
    errorDataSet: false,
    theta: [0,0],
    maxKm:0,
    lineXY: [],
    cost: 0,
    learningRate: 0.1,
    tmplearningRate: 0.1,
    iter: 10000,
    tmpIter: 10000,
    precision: 0.0000000001,
    tmpPrecision: 0.0000000001
  }

  updateDataSet = (dataSet) => {
    if (Object.keys(dataSet[0]).length === 0 || Object.keys(dataSet[0]).length === 0) {
      this.setState({errorDataSet: true})
      throw new Error("dataSet bad lenght")
    }
    this.setState({dataSet})
    if (Object.keys(dataSet[0]).length >= 2 && Object.keys(dataSet[0]).length >= 2) {
      global.data = { theta: [0, 0], cost: 0 }
      iter(dataSet, this.state.learningRate, this.state.iter, this.state.precision)
      const lineXY = []
      let max = 0
      dataSet[0].forEach(element => { if (element > max) {  max = element } })
      lineXY.push({ km: 0 , price: hypothesis(0) })
      lineXY.push({ km: max , price: hypothesis(max) })
      this.setState({ lineXY, maxKm: max, cvsIsUpload: true, theta: global.data.theta, cost: global.data.cost })
    }
  }

  updateTheta = (theta) => {
    let t0 = parseFloat(theta[0])
    let t1 = parseFloat(theta[1])
    if (isNaN(t0) || isNaN(t1)) {
      return
    }
    this.setState({ theta: [t0, t1] })
    global.data.theta = [t0, t1]
  }

  modifyLearningRate = (e) => { this.setState({ tmplearningRate: e.target.value }) }

  modifyIter = (e) => { this.setState({ tmpIter: e.target.value }) }

  modifyPrecision = (e) => { this.setState({ tmpPrecision: e.target.value }) }

  check = () => {
    let nbIter = parseInt(this.state.tmpIter)
    let learningRate = parseFloat(this.state.tmplearningRate)
    let precision = parseFloat(this.state.tmpPrecision)
    if (isNaN(nbIter) || isNaN(learningRate) || isNaN(precision)) {
      this.setState({ tmpIter: this.state.iter, tmplearningRate: this.state.learningRate, tmpPrecision: this.state.precision}) 
      return 
    }

    if (nbIter < 0) { nbIter = 0 }
    else if (nbIter > 1e+300) { nbIter = 1e+300 }

    if (learningRate < 1e-20) { learningRate = 1e-20 }
    else if (learningRate > 1) { learningRate = 1 }
    
    if (precision < 1e-300) { precision = 1e-300 }
    else if (precision > 1) { precision = 1 }

    this.setState({iter: nbIter, learningRate, tmpIter: nbIter, tmplearningRate: learningRate})
    if (this.state.cvsIsUpload === true || this.state.cvsIsUpload === true) {
      const lineXY = []
      global.data = { theta: [0, 0], cost: 0 }
      iter(this.state.dataSet, learningRate, nbIter, precision)
      lineXY.push({ km: 0 , price: hypothesis(0) })
      lineXY.push({ km: this.state.maxKm , price: hypothesis(this.state.maxKm) })
      this.setState({ lineXY, theta: global.data.theta, cost: global.data.cost })
    }
  }
  render() {
    return (
      <div className="App-header">
          <Chart data={this.state.dataSet} lineXY={this.state.lineXY}/>
        <div style={{display:'flex', flexDirection:'column', marginTop: '50px'}}>
          <CsvReader updateDataSet={this.updateDataSet}/>
          <CsvTheta  updateTheta={this.updateTheta} />
          <div>
            <Theta  theta={this.state.theta} cost={this.state.cost}/>
            <EstimationPrice max={this.state.maxKm}/>
            <div style={{width:'50%'}}>
            <Modify 
              defaultValue={this.state.learningRate}
              tmp={this.state.tmplearningRate}
              title='Learning Rate'
              modify={this.modifyLearningRate}
              />
            <Modify 
              defaultValue={this.state.iter}
              tmp={this.state.tmpIter}
              title='Iter'
              modify={this.modifyIter}
              />
            <Modify 
              defaultValue={this.state.precision}
              tmp={this.state.tmpPrecision}
              title='Precision'
              modify={this.modifyPrecision}
              />
            <Button type='primary' onClick={this.check} style={{marginTop:'10px', width:'100%'}}>Recalculate</Button>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

export default App;
