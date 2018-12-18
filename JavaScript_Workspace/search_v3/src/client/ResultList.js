/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import Result from './Result';

export default class ResultList extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      result: this.props
    };
  }

  render() {
    const { result } = this.state;
    return result.map(obj => <Result name={obj.name} number={obj.number} link={obj.link} />);
  }
}
