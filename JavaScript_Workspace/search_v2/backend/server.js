const fs = require('fs')
const express = require('express')
const nodes = require('./nodes.json')

function getIndicesOf(searchStr, str, caseSensitive) {
    var searchStrLen = searchStr.length;
    if (searchStrLen == 0) {
        return [];
    }
    var startIndex = 0, index, indices = [];
    if (!caseSensitive) {
        str = str.toLowerCase();
        searchStr = searchStr.toLowerCase();
    }
    while ((index = str.indexOf(searchStr, startIndex)) > -1) {
        indices.push(index);
        startIndex = index + searchStrLen;
    }
    return indices;
}

function spider(filepath) {
    fs.readFile(filepath, 'utf8', (err, data) => {
        if (err) throw err
        return data;
    });
}

 function comb(searchText, valueToSearch) {
    return Object.keys(getIndicesOf(valueToSearch, searchText, true)).length
}

function textSearch(searchString) {
    var results = []
    Object.keys(nodes).forEach(function(key) {
        Object.keys(nodes[key]).forEach(function(obj) {
            if(comb(spider(obj.link, searchString) > 0)) {
                results.push(obj)
                console.log(obj)
            }
        })
    });
    
    return results;
}

function picSearch(searchString) {

}

const app = express()
const API_PORT = 3001
const router = express.Router()

app.get('/search', (req, res) => {
    let searchString = req.query.searchstring
    let view = req.query.view

    alert("search string: " + searchString)
    if(view === "text") {
        // res.json({success: true, data: textSearch(searchString)})
        // return res.json({ data: "Hello World"})
        res.send("Hello World")
    } else {
        // return res.json({ data: "Other Hello World"})
        res.send("Hello World")
    }
})

app.use(router)

app.listen(API_PORT, () => console.log(`Listening on port ${API_PORT}`))