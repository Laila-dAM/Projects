const express = require('express');
const markdown = require('markdown-it')();
const bodyParser = require('body-parser');
const app = express();

app.use(bodyParser.json());
app.use(express.static(__dirname));

app.post('/render', (req, res) => {
    const mdContent = req.body.markdown || '';
    const htmlContent = markdown.render(mdContent);
    res.send(htmlContent);
});

app.listen(3000, () => {
    console.log('Markdown live preview running at http://localhost:3000');
});
