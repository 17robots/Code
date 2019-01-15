import * as Constants from './constants'

let initial = {
    searched: false,
    searchText: '',
    results: [],
    resultType: ''
}

export default reducer = (state = initial, action) => {
    switch(action.type) {
        // case Constants.TOGGLE_SEARCHED:
        //     return Object.assign({}, state, { searched: !state.searched })
        // case Constants.UPDATE_SEARCH_TEXT:
        //     return Object.assign({}, state, { searchText: action.searchText})
        default:
            return state
    }
}