import * as React from 'react'
import Input from './Input'

type Props = {}

type State = {
  searched: boolean,
  searchData: string
}

export default class App extends React.Component<Props, State> {
  constructor(props: any) {
    super(props)
    this.state = {
      searched: false,
      searchData: ''
    }
    this.search = this.search.bind(this)
  }

  search(string: string) {
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
