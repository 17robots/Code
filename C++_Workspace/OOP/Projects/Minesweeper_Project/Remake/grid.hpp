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
    Tile (*getShown())[12] { return shownTiles; }
    Tile (*getTiles())[12] { return tiles; }
    sf::Sprite getSprite() { return s; }
    void mineLay();
    void generateNumbers();
};
