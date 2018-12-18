/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import Input from './Input';
import Result from './Result';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      results: [],
      searched: false
    };
  }

  search = (searchString) => {
    fetch(`/api/getMessage?search=${searchString}`)
      .then(res => res.json())
      .then(args => this.setState({
        searched: true,
        results: args.message
      }));
  }

  render() {
    const { searched } = this.state;
    if (!searched) {
      return <Input searchFunc={this.search} />;
    }
    const { results } = this.state;
    return results.map((obj) => {
      console.log('Object Name');
      console.log(obj.name);
      return <Result name={obj.name} number={obj.number} link={obj.link} />});
  }
}

export default App;
