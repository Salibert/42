import React from 'react';
import { CSVLink } from 'react-csv'
import CSVReader from 'react-csv-reader'

  const loadCsvTheta = (dataCSV, props) => {
    const theta = []
    let key, element
    dataCSV.map(data =>
        { return Object.entries(data).slice(0).map( entry => {
            if (entry[0] !== "" && entry[1] !== "") {
                key = Number(entry[0])
                element = Number(entry[1])
                if (!isNaN(key) && !isNaN(element)) {
                    theta.push(element)
                }
            }
        })
        }
    )
    if (theta.length !== 2) {
        throw new Error('bad formate!');
    }
    props.updateTheta(theta)
  }

const CsvTheta = ({ ...props }) => {
    return (
    <div style={{display:'flex', flexDirection:'row', marginTop: '5px' }}>
        <CSVLink
            style={{marginRight: '5px' }}
            data={[['theta0', 'theta1'],[`${global.data.theta[0]}`, `${global.data.theta[1]}`]]}
            filename={"thetas.csv"}
            target="_blank"
        >
            <div style={{ padding: '5px 0', displaty: 'flex', alignItems: 'center', justifyContent: 'center', border: 'solid 1px black', borderRadius: '10px', background: 'white' }}>
                <p style={{ margin: '2px 20px 2px 20px', textAlign: 'center', zIndex: '-1000', color: 'black' }}>Export Theta</p>
            </div>
        </CSVLink>
        <CSVReader
            cssClass="csv-reader-input"
            label={<div style={{ padding: '5px 0', displaty: 'flex', alignItems: 'center', justifyContent: 'center', border: 'solid 1px black', borderRadius: '10px', background: 'white' }}>
            <p style={{ margin: '2px 20px 2px 20px', textAlign: 'center', zIndex: '-1000', color: 'black' }}>Import Theta</p>
            </div>}
            onFileLoaded={(data) => loadCsvTheta(data, props)}
            onError={(e) =>{ console.log(e) }}
            inputId="csv1"
            inputStyle={{display: 'none'}}
        />
    </div>
    )
}

export default CsvTheta;