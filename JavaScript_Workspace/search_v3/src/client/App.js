/* eslint linebreak-style: ["error", "windows"] */

import React, { Component } from 'react';
import Input from './Input';
import View from './View';
import { throws } from 'assert';


class App extends Component {
  state = {
    searchData: [],
    view: "text",
    searched: false
  };

  search(searchString) {
    fetch('/api/search').then(res => res.json()).then(user => this.setState({
      searchData: user.searchResults,
      searched: true
    }));
  }

  switchView(newView) {
    this.setState({ view: newView });
  }

  render() {
    if (this.state.searched) {
      return (
        <div>
          <Input sendData={this.search()} />
        </div>
      );
    } else {
      return (
        <div>
          <View searchData={this.state.searchData} switchView={this.switchView.bind(this)} />
        </div>
      );
    }
  }
}

export default App;
