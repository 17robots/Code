import React, { Component } from 'react'
import Input from '../Input'
import styles from './index.css'

export default class App extends Component {
  render() {
  // this.loadStyles()
	return (
	    <div className={styles.app}>
	        <Input/>
	    </div>
	)}
}
