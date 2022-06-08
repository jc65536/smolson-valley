#include <SFML/System.hpp>

#include "Game.h"

Game::Game() : shape1(sf::Vector2f(20.f, 20.f)),
               shape2(sf::Vector2f(30.f, 10.f)) {
    font.loadFromFile("res/consola.ttf");
    debugText.setFont(font);
    debugText.setCharacterSize(16);
    shape1.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Yellow);
    shape2.setPosition(100, 150);
}

void Game::update() {
    for (auto &entry : keyToDir) {
        if (sf::Keyboard::isKeyPressed(entry.first)) {
            shape1.move(sf::Vector2f(entry.second.first, entry.second.second));
        }
    }

    debugString = "";
    float fps = 1 / fpsClock.restart().asSeconds();
    debugString += std::to_string(fps) + " fps\n";

    if (shape1.getGlobalBounds().intersects(shape2.getGlobalBounds()))
        debugString += "touching";
    else
        debugString += "...";

    debugText.setString(debugString);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(tilemap);
    target.draw(shape2);
    target.draw(shape1);
    target.draw(debugText);
}
