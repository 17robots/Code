import * as React from 'react'
import { InputProps } from './interface'
import './styles/input.css'

export default class Input extends React.Component<InputProps, any> {
  constructor(props: InputProps) {
    super(props);
    this.search = this.search.bind(this)
  }

  search(e) {
    const { searchFunc } = this.props;
    e.preventDefault();
    searchFunc((document.getElementById("searchBar") as HTMLInputElement).value);
  }

  public render() {
    return (
      <div>
        <form onSubmit={this.search}>
          <input type="text" id="searchBar" autoComplete="off" autoCapitalize="off" />
          <input type="submit" />
        </form>
      </div>
    )
  }
}