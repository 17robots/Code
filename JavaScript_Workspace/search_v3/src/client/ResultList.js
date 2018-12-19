/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import PropTypes from 'prop-types';
import Result from './Result';
import style from './styles.css';

class ResultList extends React.Component {
  constructor(props) {
    super(props);
    const { result } = this.props;
    this.state = {
      result
    };
    this.search = this.search.bind(this);
  }

  search(e) {
    e.preventDefault();
    const { searchFunc } = this.props;
    searchFunc(document.getElementById('searchBar').value);
  }

  render() {
    const { result } = this.state;
    return (
      <div>
        <div className={style.miniInput}>
          <form onSubmit={this.search}>
            <input type="text" autoComplete="off" id="searchBar" autoCapitalize="off" autoCorrect="off" />
            <input type="submit" value="S" />
          </form>
        </div>
        <div>
          {result.map(obj => <Result name={obj.name} number={obj.number} link={obj.link} />)}
        </div>
      </div>
    );
  }
}

ResultList.propTypes = {
  result: PropTypes.arrayOf(PropTypes.object).isRequired,
  searchFunc: PropTypes.func.isRequired
};

export default ResultList;
