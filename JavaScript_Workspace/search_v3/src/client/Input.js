/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import PropTypes from 'prop-types';

class Input extends React.Component {
  constructor(props) {
    super(props);
    this.search = this.search.bind(this);
  }

  search(e) {
    e.preventDefault();
    const { searchFunc } = this.props;
    searchFunc(document.getElementById('searchBar').value);
    console.log('searched');
  }

  render() {
    return (
      <div>
        <form onSubmit={this.search}>
          <input type="text" autoComplete="off" id="searchBar" autoCapitalize="off" autoCorrect="off" />
          <input type="submit" value="S" />
        </form>
      </div>
    );
  }
}

Input.propTypes = {
  searchFunc: PropTypes.func.isRequired
};

export default Input;
