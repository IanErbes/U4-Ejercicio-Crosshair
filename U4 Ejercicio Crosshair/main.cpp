#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_crosshair;
Sprite sprite_crosshair;

int main() {
    texture_crosshair.loadFromFile("crosshair.png");
    sprite_crosshair.setTexture(texture_crosshair);

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Ejercicio 1 Crosshair");

    while (App.isOpen()) {
        Event evt;
        while (App.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                App.close();
                break;
            }
        }

        App.clear();

        sf::Vector2u windowSize = App.getSize();
        sf::Vector2u spriteSize = texture_crosshair.getSize();

        float x = (windowSize.x - sprite_crosshair.getGlobalBounds().width) / 2;
        float y = (windowSize.y - sprite_crosshair.getGlobalBounds().height) / 2;

        sprite_crosshair.setPosition(x, y);

        App.draw(sprite_crosshair);
        App.display();
    }

    return 0; 
}
