#include "Game.h"

int main() {
    Game game1 = Game(); // create the game
    game1.run(); // run the game
    std::cout << game1 << std::endl;
    // game1.printResults();
    return 0;
}