const HTMLWebpackPlugin = require('html-webpack-plugin')
const path = require('path')

module.exports = {
    entry: './client/index.js',
    output: {
        path: path.resolve(__dirname, 'build'),
        filename: "bundle.js",
    },
    module: {
        rules: [
            {
                test: /\.js$/,
                use: {
                    loader: 'babel-loader'
                },
                exclude: /node_modules/
            },
            {
                test: /\.tsx$/,
                use: {
                    loader: 'ts-loader'
                }
            },
            {
                test: /\.css$/,
                loader: 'css-loader',
                query: {
                    modules: true,
                    localIdentName: "[name]_[local]_[hash:base64]"
                }
            },
            {
                test: /\.css$/,
                loader: 'style-loader'
            }
        ]
    },
    devServer: {
        port: 3000,
        open: true,
        proxy: {
            '/api': {
                target: "http://localhost:8080",
                secure: true
            }
        }
    },
    plugins: [
        new HTMLWebpackPlugin({
            filename: 'index.html',
            template: './client/public/index.html'
        })
    ]
}