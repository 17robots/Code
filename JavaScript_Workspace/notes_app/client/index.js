import React from 'react'
import ReactDOM from 'react-dom'
import { Provider } from 'react-redux'
import { App } from './components'
import store from '../redux/store'
import { addNote, getNotes } from '../redux/actions' 

window.store = store
window.getNotes = getNotes
window.addNote = addNote

ReactDOM.render(
    <Provider store={store}>
        <App />
    </Provider>,
    document.getElementById('root'))
