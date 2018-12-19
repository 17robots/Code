/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import Input from './Input';
import ResultList from './ResultList';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      results: [],
      searched: false
    };
    this.search = this.search.bind(this);
    // this.clear = this.clear.bind(this);
  }

  search = (searchString) => {
    fetch(`/api/getMessage?search=${searchString}`)
      .then(res => res.json())
      .then((args) => {
        this.setState({ searched: false, results: [] });
        this.setState({ searched: true, results: args.message });
      });
  }

  render() {
    console.log('rendered');
    const { searched } = this.state;
    if (!searched) {
      return <Input searchFunc={this.search} />;
    }
    const { results } = this.state;
    return <ResultList searchFunc={this.search} result={results} />;
  }
}

export default App;
