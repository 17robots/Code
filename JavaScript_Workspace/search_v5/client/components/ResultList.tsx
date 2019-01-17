import * as React from 'react'
import Result from './Result.tsx'

interface Props {
  results: Result[]
}

class ResultList extends React.Component<Props, {}> {
  constructor(props: Props) {
    super(props)
  }
  render() {
    return (
      <div>
        ResultList
          </div>
    )
  }
}

export default ResultList