import * as React from 'react'

interface Props {
    className: string
}

interface State {

}

export default class Sidebar extends React.Component<Props, State> {
    public static defaultProps = {
        className: ''
    }

    render() {
        return (
            <div className={this.props.className}>Hello Sidebar</div>
        );
    }
}
