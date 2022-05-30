#include "Game.h"

Game::Game() : shape(20.f) {
    font.loadFromFile("res/consola.ttf");
    debugText.setFont(font);
    debugText.setCharacterSize(16);
    shape.setFillColor(sf::Color::Green);
}

void Game::update() {
    for (auto &entry : keyToDir) {
        if (sf::Keyboard::isKeyPressed(entry.first)) {
            shape.move(sf::Vector2f(entry.second.first, entry.second.second));
        }
    }

    float fps = 1 / fpsClock.restart().asSeconds();
    debugText.setString(std::to_string(fps) + " fps");
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(shape);
    target.draw(debugText);
}
