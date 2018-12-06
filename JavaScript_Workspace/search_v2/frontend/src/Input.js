import React, { Component } from 'react'


export default class Input extends Component {
    constructor(props) {
        super(props)
        this.state = {
            searchString: ""
        }
    }
    
    render() {
        return (
            <div>
                <form onSubmit={this.searchBar.bind(this)}>
                    <input type="text" autoComplete="off" id="searchBar" tabIndex="1" autoCapitalize="off" autoCorrect="off" />
                    <input type="submit" tabIndex="2" value="S" />
                </form>
            </div>
        )
    }
    
    searchBar(e) {
        e.preventDefault()
        this.props.sendData(document.getElementById('searchBar').value)
    }
}