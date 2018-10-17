import React, { Component }  from 'react'

export default class Input extends Component {
  constructor(props) {
	super(props);
	this.state = {
	  post: this.props.data,
	  command: "",
	  result: "",
	  commandHistory: [],
	  user: "test > "
	}
  }

  render() { 
	return (
	<div>
		<form onSubmit={ reload() }>
			<input type="text" placeholder="Hello World" />
			
		</form>
	</div>
	)
  }
  
  reload(e) {
  	alert("reload was called")
  }

}

