import * as React from 'react'
import NoteList from './NoteList'

type Props = {}
type State = {}

export default class App extends React.Component<State, Props> {
    constructor(props: any) {
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