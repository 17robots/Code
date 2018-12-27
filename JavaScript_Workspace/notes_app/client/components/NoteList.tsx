import * as React from 'react'
import { connect } from 'react-redux' 
import Note from './Note'

class ConnectedNoteList extends React.Component<{notes: []}, {}> {
    constructor(props: any) {
        super(props)
    }

    public render() {
        return (
            <ul>
                {this.props.notes.map((el: any) => {
                    return <li><Note content={el}/></li>
                })}
            </ul>
        )
    }
}

const mapStateToProps = (state: any) => {
    return { notes: this.state.notes }
}

const NoteList = connect(mapStateToProps) (ConnectedNoteList)


export default NoteList