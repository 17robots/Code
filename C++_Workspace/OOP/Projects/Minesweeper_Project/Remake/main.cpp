#include "game.hpp"
#include "grid.hpp"
#include <time.h>

int main() {
    // initial setup
    srand(time(0));
    
    Grid gameGrid("images/tiles.jpg");
    Grid* ref = &gameGrid;
    Game game(32, ref);
    game.run();
    
    return 0;
}
