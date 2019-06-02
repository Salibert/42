import React from 'react'
import { Input } from 'antd';

const Modify = ( props ) => {

    return (
      <div style={{display:'flex', flexDirection:'column', alignContent:'center', marginTop:'10px'}}>
       <span style={{marginBottom: '5px', fontSize:'1em'}}>{props.title}</span>
        <span>
          <Input
            type="text"
            defaultValue={props.defaultValue}
            value={props.tmp}
            onChange={props.modify}
            style={{ marginRight: '3%' }}
          />
        </span>
      </div>
    )
  }

export default Modify