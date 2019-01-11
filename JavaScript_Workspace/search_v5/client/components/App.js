const React = require('react')
const { connect } = require('react-redux')

const mapStateToProps = (state) = {
}

class App extends React.Component {
    constructor(props) {
        super(props)
    }
    render() {
        return (
            <div>
                Hello World
            </div>
        )
    }
}

export default connect(mapStateToProps)(App)