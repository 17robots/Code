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
      searchData: '',
    };
    this.search = this.search.bind(this);
    this.changeView = this.changeView.bind(this);
  }

  search = (searchString) => {
    const { view } = this.state;
    fetch(`/api/getMessage?search=${searchString}`)
      .then(res => res.json())
      .then((args) => {
        this.setState({
          searched: false,
          results: [],
          searchData: searchString,
          view
        });
        this.setState({
          searched: true,
          results: args.message,
          searchData: searchString,
          view
        });
      });
  }

  render() {
    const { searched } = this.state;
    if (!searched) {
      return <Input searchFunc={this.search} />;
    }
    const { results } = this.state;
    const { searchData } = this.state;
    return (
      <ResultList
        result={results}
        searchFunc={this.search}
        searchData={searchData}
        toggleView={this.changeView}
      />
    );
  }
}

export default App;
