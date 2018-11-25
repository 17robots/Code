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

export default {
    
    // return the html gathered by the http request to the filename
    spider: function(filepath) {
        // fs.readFile(filepath, 'utf8', (err, data) => {
        //     if (err) throw err
        //     return data;  
        // });
    },
    
    // return the number of times the valueToSearch is found in the searchText
    comb: function(searchText, valueToSearch) {
        return Object.keys(getIndicesOf(valueToSearch, searchText, true)).length
    },
    
    
}