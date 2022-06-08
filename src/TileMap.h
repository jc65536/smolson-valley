#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

#define TILEMAP_ROWS 8
#define TILEMAP_COLS 8
#define TILE_SIZE 16

class TileMap : public sf::Drawable {
public:
    TileMap();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::VertexArray vertices;
    sf::Texture tileset;
};

#endif // Include guard
