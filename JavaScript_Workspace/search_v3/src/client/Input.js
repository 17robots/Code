/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';

export default class Input extends React.Component {
  search(e) {
    console.log('searched');
    e.preventDefault();
    this.props.searchFunc(document.getElementById('searchBar').value);
  }

  render() {
    return (
      <div>
        <form onSubmit={(e) => {
            e.preventDefault();
            this.props.searchFunc
        }}>
          <input type="text" autoComplete="off" id="searchBar" autoCapitalize="off" autoCorrect="off" />
          <input type="submit" value="S" />
        </form>
      </div>
    );
  }
}
