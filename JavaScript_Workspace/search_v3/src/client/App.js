/* eslint linebreak-style: ["error", "windows"] */

import React, { Component } from 'react';
import Input from './Input';
import View from './View';


class App extends Component {
  state = {
    searchData: null,
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
    const { searched } = this.state;
    if (!searched) {
      return (
        <div>
          <Input sendData={this.search()} />
        </div>
      );
    }

    const { searchData } = this.state;

    return (
      <div>
        <View searchData={searchData} view={this.switchView()} />
      </div>
    );
  }
}

export default App;
