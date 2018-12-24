import React from 'react'
import { connect } from 'react-redux'
import { putChangeStatus, deleteTask } from '../redux/reducers/reducer'

const Task = (props) => {
    return (
        <div classNmae="row">
            <div className="btn-group" role="group" aria-label="Basic Buttons">
                <button type="button" className="btn" onClick={() => {
                    props.putChangeStatus(props.Obj, props.isComplete)
                }} >
                    {props.isComplete ? "Undo" : "Complete"}
                </button>
                <button type="button" className="btn" onClick={() => {
                    props.deleteTask(props.Obj.slug)
                }} >
                    Delete
                </button>
            </div>
            <h3 style={{textDecoration: props.isComplete ? "line-through" : "none"}}>{props.name}</h3>
        </div>
    )
}

const mapDispatch = {putChangeStatus, deleteTask}
export default connect(null, mapDispatch)(Task)
