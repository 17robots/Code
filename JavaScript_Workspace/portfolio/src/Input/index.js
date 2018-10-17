import React, { Component } from 'react'

export default class Input extends Component {
    constructor(props) {
        super(props)
        this.state = {
            test: "Hello World",
            result: []
        }
    }
    render() {
        return (
            <div>
                <h1> { this.state.test } </h1>
                <form onSubmit={this.update.bind(this)}>
                    <input type="text" id="changeMe" />
                </form>
            </div>
        )
    }
    
    update(e) {
        this.setState({
            test: document.getElementById('changeMe').value
        })
        
        document.getElementById('changeMe').value = ""
        
        e.preventDefault()
    }
}