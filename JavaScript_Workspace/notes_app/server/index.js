const express = require('express')
const savedData = require('./savedData.json')

const app = express()

const API_PORT = 8080

app.get('/init', (req, res) => {
    res.send(savedData)
})

app.listen(API_PORT => console.log(`Listening on ${API_PORT}`))

