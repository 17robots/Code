import React, { Component } from 'react'
import Input from './Input.js'
import View from './View.js'

class App extends Component {
  state = {
    searchData: [],
    view: "text",
    searched: false
  }

  search = search_data => {
    fetch(`/api/search?searchstring=${search_data}&view=${this.state.view}`)
    .then(data => data.json())
    .then(res => this.setState({ searchData: res.data, searched: true }))
  }

  switchView = newView => {
    this.setState({ view: newView})
  }

  render() {
    if(!this.state.searched) {
        return (
            <div>
                <Input sendData={this.search.bind(this)} />
            </div>
        )
    } else {
        return (
            <div>
                <View searchDatas={this.state.results} view={this.switchView.bind(this)} />
            </div>
        )
    }
  }
}

export default App;
