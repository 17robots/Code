import * as Constants from './constants';

module.exports = {
  toggleSidebar: () => {
    return {
      type: Constants.TOGGLE_SIDEBAR
    };
  },

  openNewNoteMenu: () => {
    return {
      type: Constants.OPEN_NEW_NOTE_MENU
    };
  },

  closeNewNoteMenu: () => {
    return {
      type: Constants.CLOSE_NEW_NOTE_MENU
    };
  },

  openNewTagMenu: () => {
    return {
      type: Constants.OPEN_NEW_TAG_MENU
    };
  },

  closeNewTagMenu: () => {
    return {
      type: Constants.CLOSE_NEW_TAG_MENU
    };
  },

  openNewFolderMenu: () => {
    return {
      type: Constants.OPEN_NEW_FOLDER_MENU
    };
  },

  closeNewFolderMenu: () => {
    return {
      type: Constants.CLOSE_NEW_FOLDER_MENU
    };
  },

  createNewNote: (note) => {
    return {
      type: Constants.CREATE_NEW_NOTE,
      note
    };
  },

  createNewTag: (tag) => {
    return {
      type: Constants.CREATE_NEW_TAG,
      tag
    };
  },

  createNewFolder: (folder) => {
    return {
      type: Constants.CREATE_NEW_FOLDER,
      folder
    };
  },

  deleteTag: (tag) => {
    return {
      type: Constants.DELETE_TAG,
      tag
    };
  },

  deleteFolder: (folder) => {
    return {
      type: Constants.DELETE_FOLDER,
      folder
    };
  },

  deleteNote: (note) => {
    return {
      type: Constants.DELETE_NOTE,
      note
    };
  },

  switchActiveNote: (note) => {
    return {
      type: Constants.CHANGE_ACTIVE_NOTE,
      note
    };
  },

  switchActiveFolder: () => {
    return {
      type: Constants.CHANGE_ACTIVE_FOLDER,
      folder
    };
  },
  saveNote: (note) => {
    return {
      type: Constants.SAVE_NOTE,
      note
    };
  },
  saveAndCloseSettings: () => {
    return {
      type: Constants.CLOSE_AND_SAVE_SETTINGS_MENU
    };
  }
}