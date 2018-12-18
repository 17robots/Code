/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';

const Input = (props) => {
  return (
    <div>
      <form onSubmit={(e) => { e.preventDefault(); console.log(document.getElementById('searchBar').value); }}>
        <input type="text" autoComplete="off" id="searchBar" autoCapitalize="off" autoCorrect="off" />
        <input type="submit" value="S" />
      </form>
    </div>
  );
};

export default Input;
