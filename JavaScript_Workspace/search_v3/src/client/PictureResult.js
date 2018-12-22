/* eslint linebreak-style: ["error", "windows"] */

import React from 'react';
import PropTypes from 'prop-types';
import style from './styles.css';

class PictureResult extends React.Component {
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
      <div className={style.picture}>
        <h1>{name}</h1>
        <h1>{number}</h1>
        <h1>{link}</h1>
      </div>
    );
  }
}

PictureResult.propTypes = {
  name: PropTypes.string.isRequired,
  number: PropTypes.string.isRequired,
  link: PropTypes.string.isRequired
};

export default PictureResult;
