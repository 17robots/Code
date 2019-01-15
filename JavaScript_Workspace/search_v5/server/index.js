const express = require('express')
const settings = require('./settings.json')

// go through all folders and add them to the different arrays

// need to rework all the document system most likely

const app = express()

const API_PORT = 8080



app.listen(API_PORT, () => console.log(`listening on port ${API_PORT}`))