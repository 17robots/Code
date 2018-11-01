import React, { Component } from 'react'
import styles from './index.css'

let helpString = 
<div>
    clear - clears the screen<br />
    help - displays the help menu
</div>

let counter = 0
let userString = navigator.platform;

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
            <div className={styles.input}>
                <h1> { this.state.result.map(item => {
                    return (
                        <div key={item.id}>
                            <div>{ userString } > { item.command }</div>
                            <div>{ item.result }</div><br />
                        </div>
                    )
                }) } </h1>
                <h1>
                <form onSubmit={this.update.bind(this)}>
                    <label>{ userString } > </label><input type="text" id="changeMe" autoComplete="off" />
                </form>
                </h1>
            </div>
        )
    }
    
    update(e) {
        let test = document.getElementById('changeMe')
        // deal with the command parsing here before any output is determined
        switch(test.value.toLowerCase()) {
            case "help":
                this.setState({
                    result: this.state.result.concat({command: document.getElementById('changeMe').value.toLowerCase(), result: helpString, id: counter})
                })
                counter++
                break;
            case "":
                this.setState({
                    result: this.state.result.concat({command: " ", result: " ", id: counter})
                })
                counter++
                break;
            case "clear":
                this.setState({
                    result: []
                })
                counter++
                break;
            default:
                let resultString = "that is not a valid command please try again"
                this.setState({
                    result: this.state.result.concat({command: document.getElementById('changeMe').value.toLowerCase(), result: resultString, id: counter})
                })
                counter++
                break;
        }
        
        test.value = ""
        test.scrollIntoView({behavior: "instant", block: "center", inline: "center"})
        console.log('scrolling')
        
        e.preventDefault()
        // e.stopPropogation()
        return false
    }
}