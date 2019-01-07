const express = require('express')
const bodyParser = require('body-parser')
const savedData = require('./savedData.json')

const app = express()

let API_PORT = 8080

console.log(savedData)

app.get('/init', (req, res) => {
    res.send("Hello World")
})

app.post('/newNote', (req, res) => {

})

app.post('/newTag', (req, res) => {

})

app.post('/newFolder', (req, res) => {

})

app.post('/addTag', (req, res) => {

})

app.post('/deleteTag', (req, res) => {

})

app.post('/addTag', (req, res) => {

})

app.post('/removeTag', (req, res) => {

})

app.post('/deleteNote', (req, res) => {

})

app.post('/deleteFolder', (req, res) => {

})

app.post('/saveNote', (req, res) => {

})

app.post('/saveSettings', (req, res) => {

})

app.use(bodyParser.urlencoded({extended: false}))
app.use(bodyParser.json())
app.listen(API_PORT, () => console.log(`Listening on ${API_PORT}`))

