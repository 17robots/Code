import axios from 'axios'

import * as Constants from './constants'

const initial = {
    notes: [],
    tags: []
}

const reducer = (state = initial, action) => {
    if(action.type === Constants.GET_ALL_NOTES) {
        return state.notes.objects
    } else if (action.type === Constants.CREATE_NOTE) {
        return Object.assign({}, state, { state: state.notes.concat(action.newNote)})
    }
}

export default reducer