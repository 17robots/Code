import React, { Component } from 'react'
import styles from './index.css'
import Picture_View from '../Picture_View'
import Text_View from '../Text_View'
import Indexer from '../../indexer.js'

export default class View extends Component {
    constructor(props) {
        this.state = {
            currentView: "text",
            searchString: ""
        }    
    }
    
    render() {
        let View
        if(this.state.currentView.toLowerCase() == "text") {
            View = <Text_View results={Indexer.search(this.state.searchString)} />
        } else {
            View = <Picture_View results={Indexer.search(this.state.searchString)} />
        }
        
        return (
            <div className={styles.view}>
                <div className={styles.heading}>
                    <input type="text" autocomplete="off" tabindex="1" autocapitalize="off" autocorrect="off" />
                    <input type="submit" tabindex="2" value="S" />
                    <div className={styles.switchView}>
                        <h3 onClick={this.switchView("text")}>Text</h3>
                        <h3 onClick={this.switchView("picture")}>Images</h3>
                    </div>
                </div>
                <div className={styles.results}>
                    {View}
                </div>
            </div>
        )
    }
    
    switchView(value) {
        this.setState({currentView: value})
    }
}