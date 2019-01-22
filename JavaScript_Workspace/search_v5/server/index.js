const express = require('express')
const fs = require('fs')
const nodes = require('./nodes.json')

const app = express()

const API_PORT = 8080

function parseMessage(query) {
    let phrases = []
    query.split('"').filter((string) => {
        return string !== "" || string !== " "
    }).forEach((item) => {
        
    })

    return phrases
}

function getIndicesOf(searchStr, str, caseSensitive) {
    const searchStrLen = searchStr.length;
    if (searchStrLen === 0) {
        return [];
    }
    const indices = [];
    let startIndex = 0;
    let lowerStr = str;
    let lowerSearch = searchStr;
    if (!caseSensitive) {
        lowerStr = str.toLowerCase();
        lowerSearch = searchStr.toLowerCase();
    }
    let index = lowerStr.indexOf(lowerSearch, startIndex);
    while (index > -1) {
        indices.push(index);
        startIndex = index + searchStrLen;
        index = lowerStr.indexOf(lowerSearch, startIndex);
    }
    return indices;
}

function comb(searchText, valueToSearch) {
    return Object.keys(getIndicesOf(valueToSearch, searchText, true)).length;
}

function textSearch(searchString) {
    const results = [];
    Object.keys(nodes).forEach((key) => {
        let data = fs.readFileSync(nodes[key].link)
        if(comb(data, searchString) > 0) {
            results.push(nodes[key])
        }
    });
    return results;
}


// to be implemented later
function picSearch(results) { // pull the images from the results
    Object.keys(results).forEach((key) => {

    })
}

app.get('/api/search', (req, res) => {
    // res.send({ body: textSearch(req.query.search) })
    res.send({ body: parseMessage(req.query.search) })
    // res.send({ body: 'hello World' })
})

app.listen(API_PORT, () => console.log(`listening on port ${API_PORT}`))