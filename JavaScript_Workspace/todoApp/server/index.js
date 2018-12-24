const express = require('express')
const path = require('path')
const volleyball = require('volleyball')
const app = express()

app.use(volleyball)

app.use(express.static(path.resolve(__dirname, '..', 'client')))
app.use(express.static(path.resolve(__dirname, '..', 'node_modules')))

app.use(function (err, req, res, next) {
    console.log(err)
    console.log(err.stack)
    res.status(err.status || 500).send(err.message || 'Internal Server Error')
})

app.get('*', (req, res ) => {
    res.sendFile(path.resolve(__dirname, '..', 'client', 'index.html'))
})

app.listen(process.env.PORT || 3000, () => console.log(`Listening on port ${process.env.PORT || 3000}`))
