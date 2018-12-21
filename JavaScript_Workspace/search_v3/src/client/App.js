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
    fetch(`/api/getMessage?search=${searchString}&view=${view}`)
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

    this.setState({
      searched: false,
      results,
      searchData,
      view: ''
    }, () => {
      this.setState({
        searched: true,
        results,
        searchData,
        view: newView
      });
    });

    this.search(searchData); // research the text for the opposite view
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
        result={results}
        searchFunc={this.search}
        searchData={searchData}
        view={view}
        toggleView={this.changeView}
      />
    );
  }
}

export default App;
