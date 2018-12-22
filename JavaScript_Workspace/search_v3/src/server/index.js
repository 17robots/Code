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

function comb(searchText, valueToSearch) {
  return Object.keys(getIndicesOf(valueToSearch, searchText, true)).length;
}

function textSearch(searchString) {
  const results = [];
  Object.keys(nodes).forEach((key) => {
    for (let i = 0; i < nodes[key].length; i += 1) {
      const data = fs.readFileSync(nodes[key][i].link).toString();
      if (comb(data, searchString) > 0) {
        results.push(nodes[key][i]);
      }
    }
  });
  return results;
}

function picSearch(searchString) {
  console.log(searchString);
  return [{
    name: 'Test Image',
    number: '37',
    link: 'no link'
  }];
}

const app = express();

app.use(express.static('dist'));

app.get('/api/getMessage', (req, res) => {
  const results = [];
  results.push(textSearch(req.query.search));
  results.push(picSearch(req.query.search));
  res.send({
    message: results
  });
});
app.listen(8080, () => console.log('listening on port 8080'));
