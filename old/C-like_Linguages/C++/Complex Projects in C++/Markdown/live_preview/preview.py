from flask import Flask, render_template_string, request
import markdown

app = Flask(__name__)

TEMPLATE = """
<!DOCTYPE html>
<html>
<head>
    <title>Markdown Live Preview</title>
</head>
<body>
    <textarea id="editor" rows="20" cols="80"></textarea>
    <div id="preview"></div>
    <script>
        const editor = document.getElementById('editor');
        const preview = document.getElementById('preview');
        editor.addEventListener('input', () => {
            fetch('/render', {
                method: 'POST',
                headers: {'Content-Type': 'application/json'},
                body: JSON.stringify({ markdown: editor.value })
            }).then(response => response.text())
              .then(html => preview.innerHTML = html);
        });
    </script>
</body>
</html>
"""

@app.route('/')
def index():
    return render_template_string(TEMPLATE)

@app.route('/render', methods=['POST'])
def render_markdown():
    content = request.get_json().get('markdown', '')
    return markdown.markdown(content)

if __name__ == '__main__':
    app.run(debug=True)
