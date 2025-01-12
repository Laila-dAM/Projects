#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

enum class MapElement {
City,
River,
Mountain,
Forest
};

typedef struct {
MapElement type;
sf::Vector2f position;
} MapObject;

sf::Vector2f randomPosition(float width, float height) {
        return sf::Vector2f(static_cast<float>(rand() % static_cast<int>(width)),
        static_cast<float>(rand() % static_cast<int>(height)));
}
std::string mapElementToString(MapElement element) {
    switch (element) {
        case MapElement::City:
            return "City";
        case MapElement::River:
            return "River";
        case MapElement::Mountain:
            return "Mountain";
        case MapElement::Forest:
            return "Forest";
        
    }
    return "Unknown";
}
void exportToJson(const std::vector<MapObject>& mapObjects, const std:: string& filename) {
    std::ofstream file(filename);
    if(!file.is_open()){
        std::cerr <<"Error opening file for export!" << std::endl;
        return;
    }
    file << "{\n \"map\" [\n}";
    for(size_t i = 0; i < mapObjects.size(); ++i){
        file << " {\n";
        file << "      \"type\": \"" << mapElementToString(mapObjects[i].type) << "\",\n";
        file << "      \"position\": { \"x\": " << mapObjects[i].position.x << ", \"y\": " << mapObjects[i].position.y << " }\n";
        file <<" }";

        if(i < mapObjects.size() - 1) file << ",";
        file << "\n";
        
    }
    file << " ]\n";
    file.close();
    std::cout << "Map exported to " << filename << " successfully!" << std::endl;
}

int main(){
srand(static_cast<unsigned>(time(nullptr)));
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int numElements = 20;

        sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Fantasy Map Creator");
        std::vector<MapObject> mapObjects;
    for(int i = 0; i < numElements; i++){
        MapElement type = static_cast<MapElement>(rand() % 4);
        sf::Vector2f position = randomPosition(windowWidth, windowHeight);
        mapObjects.push_back({type, position});
    }
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        for(const auto& obj : mapObjects){
            sf::CircleShape shape(10.0f);
            shape.setPosition(obj.position);

    switch(obj.type){
        case MapElement::City:
        shape.setFillColor(sf::Color::Red);
        break;

        case MapElement::River:
        shape.setFillColor(sf::Color::Blue);
        break;

        case MapElement::Mountain:
        shape.setFillColor(sf::Color::Black);
        break;

        case MapElement::Forest:
        shape.setFillColor(sf::Color::Green);
        break;
}
    window.draw(shape);
}
    window.display();
}    
exportToJson(mapObjects, "fantasy_map.json");
    return 0;
}
