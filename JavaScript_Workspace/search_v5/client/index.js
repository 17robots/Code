const React = require('react')
const ReactDOM = require('react-dom')
const { Provider } = require('react-redux')
import store from '../redux/store'
import App from './components/App.tsx'


// window definitions
window.store = store


// final render
ReactDOM.render(
    <Provider store={store}>
        <App />
    </Provider>,
    document.getElementById('root')
)