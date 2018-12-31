import savedData from './savedData.json'
import * as Constants from './constants'

let initial = {
  folders: savedData.folders,
  tags: savedData.tags
}

const reducer = (state = initial, action) => {
  return state
}

export default reducer