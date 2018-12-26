import * as Constants from './constants'

export function getNotes(notes) {
    return { type: Constants.GET_ALL_NOTES, notes}
}

