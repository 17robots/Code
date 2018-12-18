/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import Input from './Input';
import ResultList from './ResultList';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      results: [],
      // searched: false
    };
  }

  search = () => {
    fetch('/api/getMessage')
      .then(res => res.json())
      .then(args => this.setState({
        // searched: true,
        results: args.message
      }));
  }

  render() {
    const { searched } = this.state;
    if (!searched) {
      return <Input searchFunc={this.search} />;
    }
    const { results } = this.state;
    return <ResultList result={results} />;
  }
}

export default App;
