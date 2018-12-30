import React from 'react'

interface Props {
    visible: boolean
}

export default class Sidebar extends React.Component<Props> {
    render() {
        if(this.props.visible) {
            return (
                <div className="visible">
                    Sidebar
                </div>
            )
        }
        return (
            <div className="hidden"></div>
        )
    }
}
