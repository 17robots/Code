#include "grid.hpp"
#include <iostream>

Grid::Grid() = default;

Grid::Grid(std::string imgLoc) {
    t.loadFromFile(imgLoc);
    s = sf::Sprite(t);
}

void Grid::mineLay() {
    for(int i = 1; i <= 10; ++i) {
        for(int j = 1; j <= 10; ++j) {
            shownTiles[i][j] = Tile(10);
            std::cout << shownTiles[i][j].getSpriteValue() << '\n';
            if(rand() % 5 == 0) {
                tiles[i][j] = Tile(9);
            } else {
                tiles[i][j] = Tile(0);
            }
        }
    }
}

void Grid::generateNumbers() {
    for(int i = 1; i <= 10; ++i) {
        for(int j = 1; j <= 10; ++j) {
            int n = 0;
            if(tiles[i][j].getSpriteValue() == 9) {
                continue;
            }
            if(tiles[i + 1][j].getSpriteValue() == 9) {
                n++;
            }
            if(tiles[i][j + 1].getSpriteValue() == 9) {
                n++;
            }
            if(tiles[i - 1][j].getSpriteValue() == 9) {
                n++;
            }
            if(tiles[i][j - 1].getSpriteValue() == 9) {
                n++;
            }
            if(tiles[i + 1][j + 1].getSpriteValue() == 9) {
                n++;
            }
            if(tiles[i - 1][j - 1].getSpriteValue() == 9) {
                n++;
            }
            if(tiles[i - 1][j + 1].getSpriteValue() == 9) {
                n++;
            }
            if(tiles[i + 1][j - 1].getSpriteValue() == 9) {
                n++;
            }
            tiles[i][j] = Tile(n);
        }
    }
}

void Grid::useHint() {
    if(hints > 0) {
        // set the status of the hint string
        if(--hints == 0) {
            hintStatus = "Hint Used. You have used up all your hints.";
        } else {
            hintStatus = "Hint Used. You have " + std::to_string(hints) + " remaining.";
        }

        // pick a random number from the remaining bombs to reveal
        int bombNum = rand() % remainingBombs + 1;
        int currBomb = 0;

        // go through the grid and find that bomb
        for(int i = 1; i <= 10; ++i) {
            for(int j = 1; j <= 10; ++j) {
                if(currBomb == bombNum && tiles[i][j].getSpriteValue() == 9) {
                    shownTiles[i][j].setTile(11);
                } else {
                    if(tiles[i][j].getSpriteValue() == 9) {
                        currBomb++;
                    }
                }
            }
        }

    } else {
        hintStatus = "No more hints remaining";
    }
}
