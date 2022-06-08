// Game class holds global data
#ifndef GAME_H
#define GAME_H

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>
#include <utility>
#include <string>

#include "TileMap.h"

class Game : public sf::Drawable {
public:
    Game();
    void update();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    TileMap tilemap;
    sf::RectangleShape shape1;
    sf::RectangleShape shape2;
    sf::Font font;
    std::string debugString;
    sf::Text debugText;
    sf::Clock fpsClock;
    std::unordered_map<sf::Keyboard::Key, std::pair<int, int>> keyToDir = {{sf::Keyboard::Up, {0, -5}},
                                                                           {sf::Keyboard::Down, {0, 5}},
                                                                           {sf::Keyboard::Left, {-5, 0}},
                                                                           {sf::Keyboard::Right, {5, 0}}};
};

#endif // Header guard
