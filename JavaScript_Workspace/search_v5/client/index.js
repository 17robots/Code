const React = require('react')
const ReactDOM = require('react-dom')
const { Provider } = require('react-redux')
import store from '../redux/store'
import App from './components/App.tsx'

ReactDOM.render(
    <Provider store={store}>
        <App />
    </Provider>,
    document.getElementById('root')
)