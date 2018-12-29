import * as React from 'react'
import NoteList from './NoteList'
import { connect } from 'react-redux';

interface Props {}
interface State {}

class App extends React.Component<Props, State> {
    constructor(props: Props) {
        super(props)
    }

    public render() {
        return (
            <div>
                <NoteList />
            </div>
        )
    }
}

export default App