#include "tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>

#pragma once

class Grid {
    private:
    Tile tiles[12][12];
    Tile shownTiles[12][12];
    sf::Texture t;
    sf::Sprite* s;
    int hints;
    int remainingBombs;
    std::string hintStatus;
    
    public:
    Grid();
    Grid(std::string imgLoc);
    Tile* getShown(int i, int j) { return &shownTiles[i][j]; }
    Tile* getTiles(int i, int j) { return &tiles[i][j]; }
    int getRemainingBombs() { return remainingBombs; }
    std::string getHintStatus() { return hintStatus; }
    sf::Sprite* getSprite() { return s; }
    void decreaseBombs() { if(remainingBombs > 0) remainingBombs--; }
    void mineLay();
    void generateNumbers();
    void useHint(); // will decrease hints when done
};
