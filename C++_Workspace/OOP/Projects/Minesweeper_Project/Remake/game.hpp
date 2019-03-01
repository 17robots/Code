#include "grid.hpp"
#ifndef GAME_HPP
#define GAME_HPP

class Game {
    private:
    sf::RenderWindow window;
    Grid grid;
    int x;
    int y;
    int w;
    
    public:
    Game();
    Game(int blockWidth, Grid grid);
    run();
}

#endif