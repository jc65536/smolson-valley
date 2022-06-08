#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <unordered_map>
#include <utility>

#include "config.h"
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(256, 256), "smolson-valley dev");
    Game game;

    sf::Clock clock;
    sf::Int64 elapsedTimeUs = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        elapsedTimeUs += clock.restart().asMicroseconds();
        while (elapsedTimeUs > US_PER_FRAME) {
            window.clear();
            game.update();
            window.draw(game);
            elapsedTimeUs -= US_PER_FRAME;
            window.display();
        }
    }
}
