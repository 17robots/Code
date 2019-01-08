import * as React from 'react'

interface Props {
  className: string
}

export default class Editor extends React.Component<Props> {
  public static defaultProps = {
    className: ''
  }

  render() {
    return (
      <div>
        Hello Editor
      </div>
    )
  }
}