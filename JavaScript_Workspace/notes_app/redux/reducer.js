import savedData from './savedData.json'
import * as Constants from './constants'

let initial = {
  folders: savedData.folders,
  tags: savedData.tags,
  activeFolder: savedData.activeFolder,
  activeNote: savedData.activeNote,
  sidebarVisible: savedData.sidebarVisible,
  newNoteVisble: savedData.newNoteVisble,
  newTagVisible: savedData.newTagVisible,
  newFolderVisible: savedData.newFolderVisible
}

const reducer = (state = initial, action) => {
  switch (action.type) {
    default:
      return state
  }
}

export default reducer