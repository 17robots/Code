/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';

export default class Result extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      name: this.props,
      number: this.props,
      link: this.props
    };
  }

  render() {
    const { name, number, link } = this.state;
    return (
      <div>
        <h1>
          <a href={link}>
            <span>{name}</span>
            <span>{number}</span>
          </a>
        </h1>
        <hr />
      </div>
    );
  }
}
