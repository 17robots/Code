import React, { Component } from 'react'
import PictureView from './PictureView.js'
import TextView from './TextView.js'


class View extends Component {
    constructor(props) {
        super(props)
        this.state = {
            currentView: "text",
            searchString: this.props.searchData
        }
    }
    
    render() {
        let View
        if(this.state.currentView.toLowerCase() === "text") {
            View = <TextView results={this.props.searchString} />
        } else {
            View = <PictureView results={this.state.searchString} />
        }
        
        return (
            <div>
                <div>
                    <input type="text" autoComplete="off" tabIndex="1" autoCapitalize="off" defaultValue={this.state.searchString} autoCorrect="off" />
                    <input type="submit" tabindex="2" value="S" />
                    <div>
                        <h3 onClick={this.switchView("text")}>Text</h3>
                        <h3 onClick={this.switchView("picture")}>Images</h3>
                    </div>
                </div>
                <div>
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