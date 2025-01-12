#include <SFML/Graphics.hpp>

class Game {
public:
    Game(){
        window.create(sf::VideoMode(800, 600), "2D Game Engine");
        circle.setRadius(50);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(375, 275);
    }
void run(){
    while(window.isOpen()){
        handleEvents();
        update();
        render();
}
}
private:
sf::RenderWindow window;
sf::CircleShape circle;

void handleEvents(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed)
            window.close();
}
}
void update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        circle.move(-5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        circle.move(5,0);
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    circle.move(0, -5);
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    circle.move(0,5);
}
void render(){
    window.clear();
    window.draw(circle);
    window.display();
    
}
};

int main(){
    Game game;
    game.run();
    return 0;
}