import savedData from './savedData.json';
import * as Constants from './constants';
import * as axios from 'axios'

let initial = {
  folders: null,
  tags: null,
  activeFolder: null,
  activeNote: null,
  sidebarVisible: null,
  newNoteVisble: null,
  newTagVisible: null,
  newFolderVisible: null
}

// grab the initial state
fetch('/api/init').then(res => res.json).then((obj) => initial = obj)

console.log(initial)

const reducer = (state = initial, action) => {
  switch (action.type) {
    case Constants.TOGGLE_SIDEBAR:
      return Object.assign({}, state, {
        sidebarVisible: !state.sidebarVisible
      });
    case Constants.OPEN_NEW_FOLDER_MENU:
      return Object.assign({}, state, {
        newFolderVisible: true
      });
    case Constants.CLOSE_NEW_FOLDER_MENU:
      return Object.assign({}, state, {
        newFolderVisible: false
      });
    case Constants.OPEN_NEW_NOTE_MENU:
      return Object.assign({}, state, {
        newNoteVisble: true
      });
    case Constants.CLOSE_NEW_NOTE_MENU:
      return Object.assign({}, state, {
        newNoteVisble: false
      });
    case Constants.OPEN_NEW_TAG_MENU:
      return Object.assign({}, state, {
        newTagVisible: true
      });
    case Constants.CLOSE_NEW_TAG_MENU:
      return Object.assign({}, state, {
        newTagVisible: false
      });
    case Constants.CREATE_NEW_FOLDER:

    default:
      return state;
  }
}

export default reducer;