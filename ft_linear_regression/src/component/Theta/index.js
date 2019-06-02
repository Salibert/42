
import React from 'react'

const Theta = (props) => {
    return (
        <div>
            <span style={{fontSize:'3em'}}>θ</span>
            <span style={{fontSize:'2em'}}>0 </span>
            <span style={{fontSize:'3em'}}>: {props.theta[0] === 0 ? 0 : props.theta[0].toFixed(6)}</span>
            <br/>
            <span style={{fontSize:'3em'}}>θ</span>
            <span style={{fontSize:'2em'}}>1 </span>
            <span style={{fontSize:'3em'}}>: {props.theta[1] === 0 ? 0 : props.theta[1].toFixed(6)}</span>
            <br/>
            <span style={{fontSize:'1.5em'}}>Loss</span>
            <span style={{fontSize:'1.5em'}}>: {props.cost === 0 ? 0 : props.cost.toFixed(10)}</span>
        </div>
    )
}

export default Theta