#include "tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>

#ifndef GRID_HPP
#define GRID_HPP

class Grid {
    private:
    Tile tiles[12][12];
    Tile shownTiles[12][12];
    sf::Texture t;
    
    public:
    Grid();
    Grid(std::string imgLoc);
    mineLay();
    generateNumbers();
};

#endif