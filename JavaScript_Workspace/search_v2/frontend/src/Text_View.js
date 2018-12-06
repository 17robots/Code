// text view
import React, { Component } from 'react'
import Text_Result from './Text_Result.js'

class Text_View extends Component {
    constructor(props) {
        super(props)
        this.state = {
            resultList: this.props.resultList
        }
    }
    
    render() {
        this.state.resultList.map(function(obj) {
            return (
                <div>
                    <Text_Result name={obj.name} link={obj.link} number={obj.number} />
                    <hr />
                </div>
            )
        })
    }
}

export default Text_View