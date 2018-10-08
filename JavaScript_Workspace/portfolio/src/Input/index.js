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
	return <div>
	  <h1>{ this.state.commandHistory.map(function(d) {return (<li>{d.command}<br />{d.result}</li>) }) }</h1>
	  <form onSubmit={ this.preventReload.bind(this) }>
	  <input type="text" onChange={ this.handleChange.bind(this) } placeholder="Please write something..." /> 
	  </form>
	  </div>
  }

  handleChange(e) {
	this.setState({ command: e.target.value })
  }

  preventReload(e) {
	switch(this.state.command.toLowerCase()) {
	  case "help":
		this.state.commandHistory.push({
		  command: this.state.user + this.state.command,
		  result: `help table`
		})
		break
	  case "clear":
		this.setState({ commandHistory: []})
		break;
	  default:
		this.state.commandHistory.push({
		  command: this.state.user + this.state.command,
		  result: `That is not a valid command. Please type help for a list of available commands`
		})
		break
	}
	e.preventDefault()
  }

}

