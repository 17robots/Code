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
    tags: state.tags
  }
}

interface Props {
  folders: Folder[],
  tags: Tag[]
}

interface State {
  currentFolder: Folder,
  currentNote: Note,
  sidebarVisible: boolean,
  newNoteVisible: boolean,
  newTagVisible: boolean,
  newFolderVisible: boolean
}

class App extends React.Component<Props, State> {
  constructor(props: any) {
    super(props)
    this.state = {
      currentFolder: this.props.folders[0],
      currentNote: this.props.folders[0].notes[0],
      sidebarVisible: false,
      newNoteVisible: false,
      newTagVisible: false,
      newFolderVisible: false
    }
  }

  toggleSidebar() {
    this.setState({ sidebarVisible: !this.state.sidebarVisible})
  }

  openNewNoteMenu() {
    this.setState({ newNoteVisible: true })
  }

  closeNewNoteMenu() {
    this.setState({ newNoteVisible: false })
  }

  openNewTagMenu() {
    this.setState({ newTagVisible: true })
  }

  closeNewTagMenu() {
    this.setState({ newTagVisible: false })
  }

  openNewFolderMenu() {
    this.setState({ newFolderVisible: true })
  }

  closeNewFolderMenu() {
    this.setState({ newFolderVisible: false })
  }

  createNewNote() {

  }

  createNewTag() {

  }

  createNewFolder() {

  }

  deleteTag() {

  }

  deleteFolder() {

  }

  deleteNote() {

  }

  switchActiveNote(note: Note) {
    this.setState({ currentNote: note })
  }

  switchActiveFolder(folder: Folder) {
    this.setState({ })
  }

  public render() {
    return (
      <div>
        <h1>Hello World</h1>
      </div>
    )
  }
}

export default connect(mapStateToProps)(App)
