import * as React from 'react'
import { connect } from 'react-redux'

import ResultList from './ResultList.tsx'
import SearchBar from './SearchBar.tsx'

const mapStateToProps = (state: any) => {
  return {
    searched: state.searched,
    searchText: state.searchText,
    results: state.results,
    resultType: state.resultType
  }
}

interface Props {
  searched: boolean
}

class App extends React.Component<Props, {}> {
  constructor(props: Props) {
    super(props)
  }

  search(text: string) {
    fetch(`/api/search?search=${text}`).then(res => res.json()).then(res => console.log(res.body))
  }
  
  static defaultProps = {
    searched: false
  }

  render() {
    return (
      <div >
        {this.props.searched ? <ResultList /> : <SearchBar searchFunc={this.search.bind(this)} />}
      </div>
    )
  }
}

export default connect(mapStateToProps)(App)