const path = require('path')

module.exports = {
    entry: './client/index.js',
    output: {
        filename: 'bundle.js',
        path: path.resolve(__dirname, 'client/dist')
    },
    context: __dirname,
    resolve: {
        extensions: ['js', '.jsx', '.json', '*']
    },
    modules: {
        rules: [
            {
                test: /\.jsx?$/,
                exclude: /(node_modules|bower_components)/,
                loader: 'babel-loader',
                options: {
                    "presets": ['react', 'env']
                }
            },
            {
                test: /\.scss$/,
                use: [
                    'css-loader',
                    'style-loader',
                    'sass-loader'
                ]
            }
        ]
    },
    plugins: [
        new webpack.DefinePlugin({
            'process.env.COSMIC_BUCKET': JSON.stringify(process.env.COSMIC_BUCKET),
            'process.env.COSMIC_READ_KEY': JSON.stringify(process.env.COSMIC_READ_KEY),
            'process.env.COSMIC_WRITE_KEY': JSON.stringify(process.env.COSMIC_WRITE_KEY)
        })
    ]
}