// textt view
import React, { Component } from 'react'
import styles from './index.css'
import Text_Result from '../Text_Result'

export default class Text_View extends Component {
    constructor(props) {
        super(props)
        this.state = {
            resultList: this.props.resultList
        }
    }
    
    render() {
        this.state.resultList.map(function(obj) {
            return (
                <div className={styles.text_view}>
                    <Text_Result name={obj.name} link={obj.link} number={obj.number} />
                    <hr />
                </div>
            )
        })
    }
}