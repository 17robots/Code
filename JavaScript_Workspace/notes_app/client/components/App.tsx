import * as React from 'react'
import NoteList from './NoteList'
import NoteEditor from './NoteEditor'
import Sidebar from './Sidebar'

interface Props {}
interface State {
    selectedNote: any,
    sidebarVisible: boolean
}

class App extends React.Component<Props, State> {
    constructor(props: Props) {
        super(props)
    }

    changeSelectedNote() {

    }

    toggleVisible() {
        this.setState({ sidebarVisible: !this.state.sidebarVisible })
    }

    public render() {
        return (
            <div>
                <div>
                    <Sidebar visible={this.state.sidebarVisible} />
                </div>
                <div>
                    <NoteList />
                    <NoteEditor note={this.state.selectedNote} />
                </div>
            </div>
        )
    }
}

export default App