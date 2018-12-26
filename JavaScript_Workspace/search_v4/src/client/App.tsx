import * as React from 'react'
import { createHistory, useBasename } from 'history'
import { BrowserHistory } from 'react-router-dom'
import Input from './Input'

type Props = {}

type State = {
  searched: boolean,
  searchData: string,
  results: []
}

export default class App extends React.Component<Props, State> {
  constructor(props: any) {
    super(props)
    this.state = {
      searched: false,
      searchData: '',
      results: []
    }
    this.search = this.search.bind(this)
  }

  componentDidMount() {
    const { searched, searchData } = this.state
    window.onpopstate = () => {
      this.setState({ searched, searchData })
    }
  }

  search(string: string) {
    const url = `/api/search?search=${string}`
    fetch(url)
    .then(res => res.json())
    .then(args => { // clean the state
      this.setState({
        searched: false,
        searchData: '',
        results: []
      })
      this.setState({ // actually fill it in
        searched: true,
        searchData: string,
        results: args.message
      })
    })

    history.pushState({ searched: true, searchData: string }, '', url)
    this.setState({ searched: true, searchData: string })
  }

  public render() {
    const { searched, searchData } = this.state
    if (searched) {
      return (
        <div>
          We searched {searchData}
        </div>
      )
    } else {
      return (
        <div>
          <Input searchFunc={this.search} />
        </div>
      )
    }
  }
}
