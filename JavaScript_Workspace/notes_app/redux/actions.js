import * as Constants from './constants'

export function getNotes(notes) {
    return { type: Constants.GET_ALL_NOTES, notes }
}

export function addNote(newNote) {
    return { type: Constants.CREATE_NOTE, newNote }
}

