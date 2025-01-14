#include <iostream>
#include <fstream>
#include <string>
#include "markdown_parser.hpp"

std::string loadFile(const std::string &fileName){
    std::ifstream file(fileName);
    if(!file.is_open()){
        std::cerr<< "Error: Unable to open file " << fileName << "\n";
        exit(EXIT_FAILURE);
    }
return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}
void saveFile(const std::string &fileName, const std::string &content) {
    std::ofstream file(fileName);
    if(!file.is_open()){
    std::cerr << "Error: Unable to save file " << fileName << "\n";
        exit(EXIT_FAILURE);
}
    file << content;
}
int main(){
    std::string inputFile = "example.md";
    std::string outputFile = "output.html";

    std::string markdownContent = loadFile(inputFile);
    std::string htmlContent = parseMarkdown(markdownContent);

    saveFile(outputFile, htmlContent);
    std::cout << "Markdown converted to HTML: " << outputFile << "\n";
return 0;

}