import * as React from 'react'
import { connect } from 'react-redux'

export type Note = {
  name: string,
  body: string,
  tags: []
}

export type Folder = {
  name: string,
  location: string,
  notes: []
}

export type Tag = {
  name: string,
  color: string
}

const mapStateToProps = (state: any) => {
  return {
    folders: state.folders,
    tags: state.tags
  }
}

interface State {
  currentFolder: Folder,
  currentNote: Note,
  sidebarVisible: boolean,

}

class App extends React.Component<{}, State> {
  constructor(props: any) {
    super(props)
    this.state = {

    }
  }

  public render() {
    return (
      <div>
      </div>
    )
  }
}

export default connect(mapStateToProps)(App)