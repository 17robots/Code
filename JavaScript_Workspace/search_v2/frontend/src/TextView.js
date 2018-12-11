// text view
import React, { Component } from 'react'
import TextResult from './TextResult.js'

class TextView extends Component {
    constructor(props) {
        super(props)
        this.state = {
            resultList: this.props.resultList
        }
    }
    
    render() {
        return (
            this.state.resultList.map(function(obj) {
                return (
                    <div>
                        <TextResult name={obj.name} link={obj.link} number={obj.number} />
                        <hr />
                    </div>
                )
            })
        )
    }
}

export default TextView