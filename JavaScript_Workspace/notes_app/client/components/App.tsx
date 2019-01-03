import * as React from 'react'
import { connect } from 'react-redux'

export interface Note {
  name: string,
  body: string,
  tags: []
}

export interface Folder {
  name: string,
  location: string,
  notes: Note[]
}

export interface Tag {
  name: string,
  color: string
}

const mapStateToProps = (state: any) => {
  return {
    folders: state.folders,
    tags: state.tags,
    activeFolder: state.activeFolder,
    activeNote: state.activeNote,
    sidebarVisible: state.sidebarVisible,
    newNoteVisible: state.newNoteVisible,
    newTagVisible: state.newTagVisible,
    newFolderVisible: state.newFolderVisible
  }
}

interface Props {
  folders: Folder[],
  tags: Tag[],
  activeFolder: Folder,
  activeNote: Note,
  sidebarVisible: boolean,
  newNoteVisible: boolean,
  newTagVisible: boolean,
  newFolderVisible: boolean
}

class App extends React.Component<Props, {}> {
  constructor(props: any) {
    super(props)
  }

  public render() {
    return (
      <div>
        <h1>{this.props.sidebarVisible}</h1>
      </div>
    )
  }
}

export default connect(mapStateToProps)(App)
