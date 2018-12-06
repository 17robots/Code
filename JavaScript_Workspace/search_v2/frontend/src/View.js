import React, { Component } from 'react'
import Picture_View from './Picture_View.js'
import Text_View from './Text_View.js'


class View extends Component {
    constructor(props) {
        super(props)
        this.state = {
            currentView: "text",
            searchString: this.props.searchString
        }
    }
    
    render() {
        let View
        if(this.state.currentView.toLowerCase() == "text") {
            View = <Text_View results={} />
        } else {
            View = <Picture_View results={} />
        }
        
        return (
            <div className={styles.view}>
                <div className={styles.heading}>
                    <input type="text" autoComplete="off" tabIndex="1" autoCapitalize="off" defaultValue={this.state.searchString} autoCorrect="off" />
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
        this.props.view(value)
        this.setState({currentView: value})
    }
    
    research(newSearch) {
        this.setState({searchString: newSearch})
    }
}

export default View