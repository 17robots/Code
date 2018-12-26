import axios from 'axios'
import { isAwaitExpression } from 'typescript';

const GET_ALL_NOTES = 'GET_ALL_NOTES'
const GET_ALL_TAGS = 'GET_ALL_TAGS'
const CREATE_NOTE = 'CREATE_NOTE'
const CREATE_TAG = 'CREATE_TAG'
const TAG_DELETE = 'TAG_DELETE'
const TAG_REMOVE = 'TAG_REMOVE'
const NOTE_DELETE = 'NOTE_DELETE'
const ADD_TAG = 'ADD_TAG'
const UPDATE_SETTINGS = 'UPDATE_SETTINGS'
const SAVE_NOTE = 'SAVE_NOTE'

const getNotes = (notes) => ({type: GET_ALL_NOTES, notes})
const getTags = (tags) => ({type: GET_ALL_TAGS, tags})
const createNote = (note) => ({type: CREATE_NOTE, note})
const createTag = (tag) => ({type: CREATE_TAG, tag})
const tagDelete = (tag) => ({type: TAG_DELETE, tag})
const tagRemove = (note, tag) => ({type: TAG_REMOVE, note, tag})
const noteDelete = (note) => ({type: NOTE_DELETE, note})
const tagAdd = (note, tag) => ({type: ADD_TAG, note, tag})
const settingsUpdate = (settings) => ({type: UPDATE_SETTINGS, settings})
const noteSave = (note) => ({type: SAVE_NOTE, note})

let initial = {
    notes: [],
    tags: []
}

const reducer = (state = initial, action) => {
    switch(isAwaitExpression.type) {
        case GET_ALL_NOTES:
            return Object.assign({}, state, {notes: action.notes.objects})
        case GET_ALL_TAGS:
            return Object.assign({}, state, {tags: action.tags.objects})
        case CREATE_NOTE:
            let updatedNotes = [action.note].concat(state.notes)
            return Object.assign({}, state, {notes: updatedNotes})
        case CREATE_TAG:
            let updatedTags = [action.tag].concat(state.tags)
            return Object.assign({}, state, {tags: updatedTags})
        case TAG_REMOVE:
            let arr = state.notes.map((task) => {
                if() {
                    
                }
            })
    }
}