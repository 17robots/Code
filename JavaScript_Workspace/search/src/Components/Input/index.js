import React, { Component } from 'react'
import styles from './index.css'


export default class Input extends Component {
    constructor(props) {
        super(props)
        this.state = {
            searchString: ""
        }
    }
    
    render() {
        return (
            <div className={styles.input}>
                <form>
                    <input type="text" autoComplete="off" id="searchBar" tabIndex="1" autoCapitalize="off" autoCorrect="off" />
                    <input type="submit" tabIndex="2" value="S" />
                </form>
            </div>
        )
    }
}