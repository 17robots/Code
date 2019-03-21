#include "game.hpp"
#include "grid.hpp"
#include <time.h>

int main() {
    // initial setup
    srand(time(0));
    
    Grid gameGrid("images/tiles.jpg");
    Game game(32, gameGrid);
    game.run();
    
    return 0;
}
