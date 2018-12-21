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

  changeView(newView) {
    const { results } = this.state;
    const { searchData } = this.state;
    // console.log(newView);
    this.setState({
      searched: false,
      results,
      searchData,
      view: ''
    });

    console.log('set to null');

    this.setState({
      searched: true,
      results,
      searchData,
      view: newView
    });

    console.log('set to actual value');
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
        switchView={this.changeView}
        searchData={searchData}
        searchFunc={this.search}
        result={results}
      />
    );
  }
}

export default App;
