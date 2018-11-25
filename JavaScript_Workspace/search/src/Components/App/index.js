import React, { Component } from 'react'
import { Router, Route } from 'react-router-dom'
import styles from './index.css'
import Input from '../Input'
import View from '../View'

export default class App extends Component {
    constructor(props) {
        super(props)
        this.state = {
            searchData: ""
        }
    }
    render() {
        if(this.state.searchData == "") {
            return (
                <div>
                    <Input sendData={this.search.bind(this)} />
                </div>
            )
        } else {
            return (
                <div>
                    <View searchString={this.state.searchData} />
                </div>
            )
        }
        
    }
    
    search(dataFromChild) {
        alert(dataFromChild)
        this.setState({searchData: dataFromChild})
    }
}