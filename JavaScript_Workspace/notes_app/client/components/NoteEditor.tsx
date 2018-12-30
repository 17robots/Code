import React from 'react'

interface Props {
    note: any
}

class NoteEditor extends React.Component<Props> {
    render() {
        return (
            <div>
                <h1>{this.props.note}</h1>
            </div>
        )
    }
}

export default NoteEditor