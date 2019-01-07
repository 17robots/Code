import * as React from 'react'
import { connect } from 'react-redux'
import { Note, Folder, Tag } from './Types'
import Sidebar from './Sidebar'
import NoteList from './NoteList'
import TagList from './TagList'
import Editor from './Editor'

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

const mapDispatchToProps = (dispatch: any) => {
  return ({
    // switchMode: () => {dispatch(switchMode())},

  })
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
      <div className="container">
        <div className="row">
          {this.props.sidebarVisible ? <div></div> : <Sidebar className="col-md-3" />}
          <div className="col-md-3">
            {this.props.textView ? <NoteList /> : <TagList />}
          </div>
          <div className={this.props.sidebarVisible ? "col-md-6" : "col-md-9"}>
            <Editor />
          </div>
        </div>
      </div>
    )
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(App)
