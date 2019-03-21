#include "grid.hpp"
#pragma once

class Game {
    private:
    sf::RenderWindow* window;
    Grid grid;
    int w; // width of the tiles
    public:
    Game();
    Game(int blockWidth, Grid grid);
    Grid getGrid() { return grid; }
    int getWidth() { return w; }
    sf::RenderWindow& getWindow() { return *window; }
    void run();
};
