import * as React from 'react'

interface Props {
  className: string
}

export default class TagList extends React.Component<Props> {
  public static defaultProps = {
    className: ''
  }

  render() {
    return (
      <div>
        Hello TagList
      </div>
    )
  }
}