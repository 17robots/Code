import * as React from 'react'
import  connect from 'react-redux'

import ResultList from './ResultList'
import SearchBar from './SearchBar'

const mapStateToProps = state => {
  return {
    searched: state.searched,
    searchText: state.searchText,
    results: state.results,
    resultType: state.resultType
  }
}

interface Props {

}

class App extends React.Component<Props, {}> {
  constructor(props) {
    super(props)
  }
  render() {
    return (
      <div >
        { this.props.searched ? <ResultList /> : <SearchBar /> }
      </div>
    )
  }
}

export default connect(mapStateToProps)(App)