import * as React from 'react'
import { connect } from 'react-redux'
import Note from './Note'

const mapStateToProps = (state: any) => {
    return { notes: state.notes }
}

const ConnectedNoteList = ({ notes }) => {
    <ul>
        {notes.map((el: any) => {
            return <li><Note content={el}/></li>
        })}
    </ul>
}

const NoteList = connect(mapStateToProps) (ConnectedNoteList)

export default NoteList