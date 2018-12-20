/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import Input from './Input';
import ResultList from './ResultList';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      results: [],
      searched: false,
      searchData: ''
    };
    this.search = this.search.bind(this);
  }

  search = (searchString) => {
    fetch(`/api/getMessage?search=${searchString}`)
      .then(res => res.json())
      .then((args) => {
        this.setState({ searched: false, results: [], searchData: searchString });
        this.setState({ searched: true, results: args.message, searchData: searchString });
      });
  }

  render() {
    const { searched } = this.state;
    if (!searched) {
      return <Input searchFunc={this.search} />;
    }
    const { results } = this.state;
    const { searchData } = this.state;
    return <ResultList searchData={searchData} searchFunc={this.search} result={results} />;
  }
}

export default App;
