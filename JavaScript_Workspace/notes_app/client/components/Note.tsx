import * as React from 'react'

type Props = {
    content: any
}
type State = {}

export default class Note extends React.Component<Props, State> {
    render() {
        return (
            <div>
                <h1>{this.props.content.title}</h1>
            </div>
        )
    }
}