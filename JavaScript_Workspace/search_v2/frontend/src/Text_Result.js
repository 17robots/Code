// text result
import React, { Component } from 'react'

export default class Text_Result extends Component {
    constructor(props) {
        super(props)
        this.state = {
            name: this.props.name,
            link: this.props.link,
            number: this.props.number
        }
    }
    
    render() {
        return (
            <div>
                <a href={this.state.link}>{this.state.name}    {this.state.number}</a>
            </div>
        )
    }
}