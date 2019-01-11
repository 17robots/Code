const path = require('path')
const HTMLWebpackPlugin = require('html-webpack-plugin')

module.exports = {
    entry: ['babel-polyfill', path.join(__dirname, '/client/index.js')],
    output: {
        filename: 'bundle.js',
        path: path.join(__dirname, '/dist')
    },
    resolve: {
        extensions: ['.tsx', '.js', '.ts']
    },
    module: {
        rules: [
            {
                test: /\.tsx?$/,
                loader: 'ts-loader',
                exclude: /node_modules/
            },
            {
                test: /\.css$/,
                loader: 'css-loader',
                query: {
                    modules: true,
                    localIdentName: '[name]_[local]_[hash:base64:5]'
                }
            },
            {
                test: /\.css$/,
                loader: 'style-loader'
            },
            {
                test: /\.js$/,
                loader: 'babel-loader',
                exclude: /node_modules/
            }
        ],
    },
    plugins: [
        new HTMLWebpackPlugin({
            template: path.join(__dirname, '/client/public/index.html'),
            filename: 'index.html'
        })
    ],
    devServer: {
        port: 3000,
        open: true,
        proxy: {
            '/api': {
                target: 'https://localhost:8080',
                secure: true
        }
    }
}