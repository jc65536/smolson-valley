#include "TileMap.h"

static int tiles[TILEMAP_ROWS][TILEMAP_COLS] = {{0, 2, 0, 0, 0, 0, 3, 0},
                                          {0, 2, 0, 0, 1, 1, 0, 0},
                                          {0, 2, 0, 1, 1, 1, 1, 0},
                                          {3, 2, 0, 0, 1, 1, 0, 0},
                                          {0, 2, 2, 2, 2, 2, 2, 0},
                                          {0, 0, 0, 0, 0, 0, 2, 0},
                                          {0, 0, 3, 0, 3, 0, 2, 0},
                                          {0, 0, 0, 0, 0, 0, 2, 0}};

static int corners[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

TileMap::TileMap() {
    tileset.loadFromFile("res/tiles.png");
    int tilesetCols = tileset.getSize().x / TILE_SIZE;

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(TILEMAP_ROWS * TILEMAP_COLS * 4);
    for (int i = 0; i < TILEMAP_ROWS; i++) {
        for (int j = 0; j < TILEMAP_COLS; j++) {
            int tileNumber = tiles[i][j];
            int ti = tileNumber / tilesetCols;
            int tj = tileNumber % tilesetCols;
            sf::Vertex *quad = &vertices[(i * TILEMAP_ROWS + j) * 4];
            for (int k = 0; k < 4; k++) {
                quad[k].position = sf::Vector2f((j + corners[k][0]) * TILE_SIZE * 2,
                                                (i + corners[k][1]) * TILE_SIZE * 2);
                quad[k].texCoords = sf::Vector2f((tj + corners[k][0]) * TILE_SIZE,
                                                 (ti + corners[k][1]) * TILE_SIZE);
            }
        }
    }
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.texture = &tileset;
    target.draw(vertices, states);
}
