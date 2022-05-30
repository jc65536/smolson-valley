// Game class holds global data
#ifndef GAME_H
#define GAME_H

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>
#include <utility>

class Game : public sf::Drawable {
public:
    Game();
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::CircleShape shape;
    sf::Font font;
    sf::Text debugText;
    sf::Clock fpsClock;
    std::unordered_map<sf::Keyboard::Key, std::pair<int, int>> keyToDir = {{sf::Keyboard::Up, {0, -1}},
                                                                           {sf::Keyboard::Down, {0, 1}},
                                                                           {sf::Keyboard::Left, {-1, 0}},
                                                                           {sf::Keyboard::Right, {1, 0}}};
};

#endif // Header guard
