import React from 'react'
import { XAxis, YAxis, Tooltip, ComposedChart ,CartesianGrid, Scatter ,Line } from 'recharts'

const updateChart = (dataSet) => {
  const data = []
  for(let i=0; i < dataSet[0].length; i++) {
    data.push({km:dataSet[0][i], price: dataSet[1][i]})
  }
  return data
}

const Chart = ({ ...props }) => {
    return (
      <ComposedChart width={900} height={650}
        margin={{ top: 50, right: 20, left: 50 }}>
        <CartesianGrid />
        <XAxis type="number" dataKey={'km'} name='mileage' unit='km'/>
        <YAxis type="number" dataKey={'price'} name='price' unit='$'/>
        <Tooltip cursor={{strokeDasharray: '1 1'}}/>
        { props.lineXY && props.lineXY.length !== 0 && <Line dataKey='price' data={props.lineXY} /> }
        { props.data && props.data.length !== 0 && <Scatter shape="cross" data={updateChart(props.data)} fill="#FFFFFF" />}
      </ComposedChart>
    )
}

export default Chart