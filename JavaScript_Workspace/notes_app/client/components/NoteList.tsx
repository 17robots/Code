import * as React from 'react'
import { connect } from 'react-redux' 
import Note from './Note'

export interface Props {
    notes: []
}

const mapStateToProps = (state: any) => {
    return { notes: state.notes }
}

class NoteList extends React.PureComponent<Props, {}> {
    constructor(props: Props) {
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

export default connect(mapStateToProps)(NoteList)
