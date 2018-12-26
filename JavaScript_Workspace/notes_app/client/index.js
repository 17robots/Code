import React from 'react'
import ReactDOM from 'react-dom'
import { Provider } from 'react-redux'
import { App } from './components'
import store from '../redux/store'

window.store = store
window.addNote = addNote

ReactDOM.render(
    <Provider>
        <App />
    </Provider>,
    document.getElementById('root'))
