/* eslint linebreak-style: ["error", "windows"] */
import React, { Component } from 'react';
import PictureView from './PictureView';
import TextView from './TextView';


class View extends Component {
  constructor(props) {
    super(props);
    this.state = {
      currentView: "text",
      searchString: this.props.searchData
    }
  }

  switchView(value) {
    const { view } = this.props;
    view(value);
    this.setState({ currentView: value });
  }

  research(newSearch) {
    this.setState({ searchString: newSearch });
  }

  render() {
    let returnedView = null;
    if (this.state.currentView.toLowerCase() === 'text') {
      const searchString = this.props;
      returnedView = <TextView results={this.props.searchString} />;
    } else {
      returnedView = <PictureView results={this.state.searchString} />;
    }
        
    return (
      <div>
        <div>
          <input type="text" autoComplete="off" autoCapitalize="off" defaultValue={this.state.searchString} autoCorrect="off" />
          <input type="submit" value="S" />
          <div>
            <button type="button" onClick={this.switchView('text')}>
              <h3>Text</h3>
            </button>
            <button type="button" onClick={this.switchView('picture')}>
              <h3>Images</h3>
            </button>
          </div>
        </div>
        <div>
          { returnedView }
        </div>
      </div>
    );
  }
}

export default View;
