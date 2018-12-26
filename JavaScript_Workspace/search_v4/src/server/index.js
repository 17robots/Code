const express = require('express')

const app = express()
const API_PORT = 3001

app.get('/api/search', (req, res) => {
    let message = ["hello", "world"]
    res.send({
        message
    })
})

app.get('/api/message', (req, res) => {
    res.send('hello world')
})

app.listen(API_PORT, () => console.log(`listening on port ${API_PORT}`))