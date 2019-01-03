import * as React from 'react'
import { connect } from 'react-redux'
import { Note, Folder, Tag } from './Types'
import Sidebar from './Sidebar'

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
  newFolderVisible: boolean,
  textView: boolean
}

class App extends React.Component<Props, {}> {
  constructor(props: any) {
    super(props)
  }

  public render() {
    return (
      <div>
        {this.props.sidebarVisible ? '' : <Sidebar />}
        {this.props.textView ? <NoteList /> : <TagList />}
        <Editor />
      </div>
    )
  }
}

export default connect(mapStateToProps)(App)
