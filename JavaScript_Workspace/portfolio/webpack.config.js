const HtmlWebPackPlugin = require('html-webpack-plugin');
const path = require('path')

const htmlPlugin = new HtmlWebPackPlugin({
    template: './src/index.html',
    filename: './index.html'
})

module.exports = {
	entry: './src/index.js',
	output: {
	  path: __dirname + '/17robots.github.io/',
	  filename: 'main.js'
	},
    module: 
    {
        rules: 
        [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                use: 
                {
                    loader: 'babel-loader',
					options: {
					  presets: ['@babel/preset-react']
					}
                }
            },
            {
                test: /\.css$/,
                use: 
                [
                    {
                        loader: 'style-loader'
                    },
                
                    {
                        loader: "css-loader",
                        options: 
                        {
                            modules: true,
                            importLoaders: 1,
                            localIdentName: "[name]_[local]_[hash:base64]",
                            sourceMap: true,
                            minimize: true
                        }
                    }
                ]
            },
        ]
    },
    plugins: [htmlPlugin] 
}
