import * as React from 'react'
import Input from './Input'

export default class App extends React.Component<{}> {
  constructor(props) {
    super(props)
    this.state = {
      searched: false,
      searchData: ''
    }
    this.search = this.search.bind(this)
  }

  search(string) {
    this.setState({ searched: true, searchData: string })
  }

  render() {
    if (true) {
      return (
        <div>
          We searched
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
