/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import PropTypes from 'prop-types';

class Result extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      name: '',
      number: '',
      link: ''
    };
  }

  componentDidMount() {
    const { name } = this.props;
    const { number } = this.props;
    const { link } = this.props;
    this.setState({
      name,
      number,
      link
    });
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

Result.propTypes = {
  name: PropTypes.string.isRequired,
  number: PropTypes.string.isRequired,
  link: PropTypes.string.isRequired
};

export default Result;
