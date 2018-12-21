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
      view: 'text'
    };
    this.search = this.search.bind(this);
    this.changeView = this.changeView.bind(this);
  }

  search = (searchString) => {
    fetch(`/api/getMessage?search=${searchString}`)
      .then(res => res.json())
      .then((args) => {
        this.setState({ searched: false, results: [], searchData: searchString });
        this.setState({ searched: true, results: args.message, searchData: searchString });
      });
  }

  changeView(newView) {
    this.setState({ view: newView });
  }

  render() {
    const { searched } = this.state;
    if (!searched) {
      return <Input searchFunc={this.search} />;
    }
    const { results } = this.state;
    const { searchData } = this.state;
    const { view } = this.state;
    return (
      <ResultList
        view={view}
        changeView={this.changeView}
        searchData={searchData}
        searchFunc={this.search}
        result={results}
      />
    );
  }
}

export default App;
