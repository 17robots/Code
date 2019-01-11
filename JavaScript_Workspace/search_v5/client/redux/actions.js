import * as Constants from './constants'

module.exports = {
    toggleSearched: () => {
        return {
            type: Constants.TOGGLE_SEARCHED
        }
    },
    updateSearchText: (newSearch) => {
        return {
            type: Constants.UPDATE_SEARCH_TEXT,
            newSearch
        }
    },
    refreshResults: (newResults) => {
        return {
            type: Constants.REFRESH_RESULTS,
            newResults
        }
    },
    research: (newSearch) => {
        return {
            type: Constants.RE_SEARCH,
            newSearch
        }
    },
    changeResultType: (resultType) => {
        return {
            type: Constants.CHANGE_RESULT_TYPE,
            resultType
        }
    }
}