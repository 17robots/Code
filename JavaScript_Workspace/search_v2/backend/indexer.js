import Spiderer from './spider.js'
const nodes = require('./nodes.json')

export default {
    textSearch: function(searchString) {
        var results = []
        Object.keys(nodes).forEach(function(key) {
            Object.keys(nodes[key]).forEach(function(obj) {
                // fileReader.readFile(obj.link, 'utf8', (err, data) => {
                //     if(err) {
                //         console.log(err)
                //     }
                //     if(Spiderer.comb(data, searchString) > 0) {
                //         results.push(obj)
                //     }  
                // })
                console.log("Hello World")
            })
        });
        
        return results;
    },
    
    picSearch: function(searchString) {
        
    }
}