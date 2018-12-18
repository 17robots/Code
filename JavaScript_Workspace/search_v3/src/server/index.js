/* eslint linebreak-style: ["error", "windows"] */

const fs = require('fs');
const express = require('express');
const nodes = require('./nodes2.json');

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

function spider(filepath) {
  fs.readFile(filepath, 'utf8', (err, data) => {
    if (err) throw err;
    return data;
  });
}

function comb(searchText, valueToSearch) {
  return Object.keys(getIndicesOf(valueToSearch, searchText, true)).length;
}

function textSearch(searchString) {
  const results = [];
  // Object.keys(nodes).forEach((key) => {
  //   console.log('Key');
  //   console.log(key);
  //   Object.keys(nodes.test).forEach((obj) => {
  //   //   if (comb(spider(obj.link, searchString) > 0)) {
  //   //     results.push(obj);
  //   //     console.log(obj);
  //   //   }
      
  //   // });
  // });

  return results;
}

// function picSearch(searchString) {

// }

const app = express();

app.use(express.static('dist'));
console.log(nodes.test2);
// console.log(textSearch('cats'));
app.get('/api/getMessage', (req, res) => res.send({
  message: textSearch(req.query.search)
}));
app.listen(8080, () => console.log('listening on port 8080'));
