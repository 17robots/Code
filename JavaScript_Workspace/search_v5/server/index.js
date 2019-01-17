const express = require('express')
const fs = require('fs')
const settings = require('./settings.json')

// go through all folders and add them to the different arrays

// need to rework all the document system most likely

// repull the db and output to file
const countDirs = (dirPath, contents) => {
    let counter = 0
    contents.forEach((file) => {
        if (fs.statSync("" + dirPath + "/" + file).isDirectory()) {
            ++counter
        }
    })
    return counter
}

const getFiles = (rootDir, contents) => {
    let files = []
    contents.forEach((file) => {
        if (fs.statSync("" + dirPath + "/" + file).isDirectory()) {
            ++counter
        }
    })
}

const mapDir = (rootDir) => {
    let dirPaths = []
    let contents = fs.readdirSync(rootDir)
    if(countDirs(rootDir, contents) === 0) {
        contents.forEach((file) => {
            dirPaths.push("" + rootDir + "/" + file)
        })
    } else {
        // add in what files we know
        getFiles(rootDir).forEach((file) => {
            dirPaths.push("" + rootDir + "/" + file)
        })

        // index through other folders to add to the final path

    }
}

const app = express()

const API_PORT = 8080

app.get('/api/init', (req, res) => {
    
})

app.listen(API_PORT, () => console.log(`listening on port ${API_PORT}`))