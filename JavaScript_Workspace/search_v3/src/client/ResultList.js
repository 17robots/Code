/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import PropTypes from 'prop-types';
import PictureResult from './PictureResult';
import TextResult from './TextResult';
import style from './styles.css';

class ResultList extends React.Component {
  constructor(props) {
    super(props);
    const { result } = this.props;
    const { searchData } = this.props;
    this.state = {
      result,
      searchData,
      view: 'text'
    };

    this.search = this.search.bind(this);
    this.switchToText = this.switchToText.bind(this);
    this.switchToPic = this.switchToPic.bind(this);
    this.switchView = this.switchView.bind(this);
  }

  search(e) {
    e.preventDefault();
    const { searchFunc } = this.props;
    searchFunc(document.getElementById('searchBar').value);
  }

  switchView(string) {
    this.setState({ view: string });
  }

  switchToText() {
    this.switchView('text');
  }

  switchToPic() {
    this.switchView('picture');
  }

  render() {
    let results;
    const { result } = this.state;
    const { searchData } = this.state;
    const { view } = this.state;

    switch (view) {
      case 'text':
        if (result[0].length === 0) {
          results = <h3>No Text Results Found</h3>;
        } else {
          results = result[0].map((obj) => {
            return (
              <TextResult
                name={obj.name}
                number={obj.number}
                link={obj.link}
                key={obj.number}
              />
            );
          });
        }
        break;
      default:
        if (result[0].length === 0) {
          results = <h3>No Picture Results Found</h3>;
        } else {
          results = result[1].map((obj) => {
            return (
              <PictureResult
                name={obj.name}
                number={obj.number}
                link={obj.link}
                key={obj.number}
              />
            );
          });
        }
        break;
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
  result: PropTypes.arrayOf(PropTypes.array).isRequired,
  searchFunc: PropTypes.func.isRequired,
  searchData: PropTypes.string.isRequired,
};

export default ResultList;
