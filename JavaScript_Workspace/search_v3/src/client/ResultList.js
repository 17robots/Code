/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import PropTypes from 'prop-types';
import Result from './Result';
import style from './styles.css';

class ResultList extends React.Component {
  constructor(props) {
    super(props);
    const { result } = this.props;
    const { searchData } = this.props;
    this.state = {
      result,
      searchData
    };
    this.search = this.search.bind(this);
  }

  search(e) {
    e.preventDefault();
    const { searchFunc } = this.props;
    searchFunc(document.getElementById('searchBar').value);
  }

  render() {
    let results;
    const { result } = this.state;
    const { searchData } = this.state;
    if(result.length === 0) {
      results = <h3>No Results Found. Please refine your search and try again.</h3>
    } else {
      results = result.map(obj => <Result name={obj.name} number={obj.number} link={obj.link} />)
    }
    return (
      <div>
        <div>
          <div>
            <div>
              <div className={style.miniInput}>
                <form onSubmit={this.search}>
                  <input type="text" defaultValue={searchData} contentEditable="true" autoComplete="off" id="searchBar" autoCapitalize="off" autoCorrect="off" />
                  <input type="submit" value="S" />
                </form>
              </div>
            </div>
            <div>
              <h1>Placeholder</h1>
            </div>
          </div>
        </div>
        <div className={style.resultList}>
          {results}
        </div>
      </div>
    );
  }
}

ResultList.propTypes = {
  result: PropTypes.arrayOf(PropTypes.object).isRequired,
  searchFunc: PropTypes.func.isRequired,
  searchData: PropTypes.string.isRequired
};

export default ResultList;
