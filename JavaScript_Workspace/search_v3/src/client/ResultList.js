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
    const { view } = this.props;
    this.state = {
      result,
      searchData,
      view
    };
    this.search = this.search.bind(this);
    this.switchToText = this.switchToText.bind(this);
    this.switchToPic = this.switchToPic.bind(this);
  }

  search(e) {
    e.preventDefault();
    const { searchFunc } = this.props;
    searchFunc(document.getElementById('searchBar').value);
  }

  switchToText() {
    const { switchView } = this.props;
    switchView('text');
  }

  switchToPic() {
    const { switchView } = this.props;
    switchView('picture');
  }

  render() {
    let results;
    const { result } = this.state;
    const { searchData } = this.state;
    const { view } = this.state;
    console.log(view);
    if (result.length === 0) {
      results = <h3>No Results Found. Please refine your search and try again.</h3>;
    } else {
      results = result.map(obj => <Result name={obj.name} number={obj.number} link={obj.link} />);
    }

    let activeView;
    if (view === 'text') {
      activeView = (
        <ul className={style.filterList}>
          <li className={style.filterItem}>
            <button onClick={this.switchToText} className={style.active} type="button">Text</button>
          </li>
          <li className={style.filterItem}>
            <button onClick={this.switchToPic} type="button">Images</button>
          </li>
        </ul>
      );
    } else {
      activeView = (
        <ul className={style.filterList}>
          <li className={style.filterItem}>
            <button onClick={this.switchToText} type="button">Text</button>
          </li>
          <li className={style.filterItem}>
            <button onClick={this.switchToPic} className={style.active} type="button">Images</button>
          </li>
        </ul>
      );
    }
    return (
      <div>
        <div className={style.headWrapper}>
          <div className={style.head}>
            <div className={style.searchWrap}>
              <div className={style.miniInput}>
                <form onSubmit={this.search}>
                  <input type="text" defaultValue={searchData} contentEditable="true" autoComplete="off" id="searchBar" autoCapitalize="off" autoCorrect="off" />
                  <input type="submit" value="S" />
                </form>
              </div>
            </div>
            <div className={style.filterBar}>
              <div className={style.filterMenu}>
                {activeView}
              </div>
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
  searchData: PropTypes.string.isRequired,
  view: PropTypes.string.isRequired,
  switchView: PropTypes.func.isRequired
};

export default ResultList;
