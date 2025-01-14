#include "markdown_parser.hpp"

std::string parseMarkdown(const std::string &markdown) {
    std::string html;
    size_t pos = 0;
    std::string line;

    while ((pos = markdown.find('\n')) != std::string::npos) {
        line = markdown.substr(0, pos);
        if (line.rfind("# ", 0) == 0) {
            html += "<h1>" + line.substr(2) + "</h1>\n";
        } else if (line.rfind("## ", 0) == 0) {
            html += "<h2>" + line.substr(3) + "</h2>\n";
        } else {
            html += "<p>" + line + "</p>\n";
        }
        markdown.erase(0, pos + 1);
    }
    return html;
}
