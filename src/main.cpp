#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <unordered_map>
#include <utility>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::Green);

    std::unordered_map<sf::Keyboard::Key, std::pair<int, int>> keyToDir = {{sf::Keyboard::Up, {0, -1}}, {sf::Keyboard::Down, {0, 1}}, {sf::Keyboard::Left, {-1, 0}}, {sf::Keyboard::Right, {1, 0}}};

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto &entry : keyToDir) {
            if (sf::Keyboard::isKeyPressed(entry.first)) {
                shape.move(sf::Vector2f(entry.second.first / 10.0, entry.second.second / 10.0));
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
