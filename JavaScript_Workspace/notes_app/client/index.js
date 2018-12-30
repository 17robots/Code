import React from 'react'
import ReactDOM from 'react-dom'
import { Provider } from 'react-redux'
import { App } from './components'
import store from '../redux/store'
import * as Actions from '../redux/actions'

ReactDOM.render(
    <Provider store={store}>
        <App />
    </Provider>,
    document.getElementById('root'))
