const express = require('express')

const app = express()

const API_PORT = 8080

app.listen(API_PORT, () => console.log(`listening on port ${API_PORT}`))