#include "tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>

#pragma once

class Grid {
    private:
    Tile tiles[12][12];
    Tile shownTiles[12][12];
    sf::Texture t;
    sf::Sprite s;
    
    public:
    Grid();
    Grid(std::string imgLoc);
    int** getShown() { return shownTiles; }
    int** getTiles() { return tiles; }
    Sf::Sprite getSprite() { return s; }
    mineLay();
    generateNumbers();
};
