import * as Constants from './constants'

export function getNotes(notes) {
    return { type: Constants.GET_ALL_NOTES, notes }
}

export function addNote(newNote) {
    return { type: Constants.CREATE_NOTE, newNote }
}

export function getTags(tags) {
    return { type: Constants.GET_ALL_TAGS, tags }
}

export function addTag(tag) {
    return { type: Constants.ADD_TAG, tag }
}

export function createTag(tag) {
    return { type: Constants.CREATE_TAG, tag }
}

export function removeTag(tag) {
    return { type: Constants.TAG_REMOVE, tag }
}

export function deleteTag(note, tag) {
    return { type: Constants.TAG_DELETE, note, tag }
}

export function deleteNote(note) {
    return { type: Constants.NOTE_DELETE, note }
}

export function saveNote(note) {
    return { type: Constants.SAVE_NOTE, note }
}

export function updateSettings(settings) {
    return { type: Constants.UPDATE_SETTINGS, settings }
}
