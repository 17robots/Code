const HTMLWebpackPlugin = require('html-webpack-plugin')
const path = require('path')

const htmlPlugin = new HTMLWebpackPlugin({
    template: './src/index.html',
    filename: './index.html'
})

module.exports = {
    entry: './src/index.js',
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ['@babel/preset-react']
                    }
                }
            },
            {
                test: /\.css$/,
                use: [
                    {
                        loader: 'style-loader'
                    },
                    {
                        loader: 'css-loader',
                        options: {
                            modules: true,
                            importLoaders: 1,
                            localIdentName: "[name]_[local]_[hash:base64]",
                            sourceMap: true,
                            minimize: true
                        }
                    }
                ]
            }
        ]
    },
    plugins:[htmlPlugin],
    devServer: {
        disableHostCheck: true,
        host: '0.0.0.0'
    },
    devtool: 'source-map'
}