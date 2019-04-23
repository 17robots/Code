#include "maze.h"

maze::maze(int r, int c) {
    row = r;
    col = c;
    theMaze = std::vector<mazeCell>(r * c);
    theMaze.at(0).setTop(false);
    theMaze.at(0).setLeft(false);
    theMaze.at(row * col - 1).setRight(false);
    theMaze.at(row * col - 1).setBot(false);
} // constructor

// returns true if neigh is cell's neighbor
//(i.e. in position left, right, top or bot
// with respect to cell)
bool maze::neighbors(int cell, int neigh) const {
    
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall (int cell, int neigh) {
    
}

//print the maze
void maze::printMaze() {
    // top row
    for(int j = 0; j < col; ++j) {
        if(theMaze.at(j).getTop()) {
            std::cout << "_ ";
        } else {
            std::cout << "  ";
        }
    }
    std::cout << '\n';
    
    for(int i = 0; i < theMaze.size(); ++i) {
        if(i % col == 0 && i != 0) {
            std::cout << "|\n";
        }
        
        if(theMaze.at(i).getLeft() && theMaze.at(i).getBot()) {
            std::cout << "|_";
        } else if(theMaze.at(i).getLeft()) {
            std::cout << "| ";
        } else if(theMaze.at(i).getBot()) {
            std::cout << " _";
        } else {
            std::cout << "  "; 
        }
    }
    
    std::cout << '\n';
}