import CSVReader from 'react-csv-reader'
import React from 'react';
import { Icon } from 'antd'

const loadCsv = (dataCSV, props) => {
    const dataSet = [[],[]]
    let key, element
    dataCSV.map(data =>
        { return Object.entries(data).slice(0).map( entry => {
            if (entry[0] !== "" && entry[1] !== "") {
                key = Number(entry[0])
                element = Number(entry[1])
                if (!isNaN(key) && !isNaN(element)) {
                    dataSet[key].push(element)
                }
            }
        })
        }
    )
    if (Object.keys(dataSet[0]).length !== Object.keys(dataSet[1]).length) {
        throw new Error('The parameters dataSetX and dataSetY need to have same size!');
    } else if (Object.keys(dataSet[0]).length === 0) {
        return [ [], [] ];
    }
    props.updateDataSet(dataSet)
  }

const CsvReader = ({ ...props }) => {
    return (
        <div>
            <CSVReader
                cssClass="csv-reader-input"
                label={<div style={{ padding: '5px 0', width: '256px' ,displaty: 'flex', alignItems: 'center', justifyContent: 'center', border: 'solid 1px black', borderRadius: '10px', background: 'white' }}>
                <p style={{ margin: '0', textAlign: 'center', zIndex: '-1000', color: 'black' }}><Icon type="cloud-upload" style={{marginRight: '10px'}}/>Upload Data CSV</p>
                </div>}
                onFileLoaded={(data) => loadCsv(data, props)}
                onError={(e) =>{ console.log(e) }}
                inputId="csv2"
                inputStyle={{display: 'none'}}
            />
      </div>
    )
}

export default CsvReader;