import * as React from 'react'

interface Props {
  searchFunc: (text: string) => void
}

class SearchBar extends React.Component<Props, {}> {
    constructor(props: Props) {
      super(props)
      this.search = this.search.bind(this)
    }

    static defaultprops = {
      searchFunc: () => console.log('no search function attached')
    }

    search(e: React.FormEvent) {
      e.preventDefault()
      this.props.searchFunc((document.getElementById('searchbar') as HTMLInputElement).value)
    }

    render() {
        return (
          <div>
            <form onSubmit={this.search}>
            <input type="text" id="searchbar"/>
            </form>
          </div>
        )
    }
}

export default SearchBar