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
// tested
bool maze::neighbors(int cell, int neigh) const {
    if(cell < col) { // if it's in the top row
        if(cell == col - 1) { // if it's the right most one
            // std::cout << "right most top\n";
            return neigh == cell + col || neigh == cell - 1;
        } else if(cell == 0) { // if it's the leftmost one
            // std::cout << "left most top\n";
            return neigh == cell + col || neigh == cell + 1;
        } else { // any others on the top row
            // std::cout << "in top row\n";
            return neigh == cell + col || neigh == cell - 1 || neigh == cell + 1;
        }
    } else { // not in the top row
        if(cell >= theMaze.size() - cell - 1) { // if it's on the bottom
            if(cell == row * col - 2) { // if its the right most one
                // std::cout << "right most top\n";
                return neigh == cell - col || neigh == cell - 1;
            } else if(cell % col == 0) { // if it's the left most one
                // std::cout << "left most bot\n";
                return neigh == cell - col || neigh == cell + 1;
            } else {
                // std::cout << "in bot row\n";
                return neigh == cell - col || neigh == cell + 1 || neigh == cell - 1;
            }
        } else {
            if(cell % col == 0) { // if the cell is on the left edge
                // std::cout << "left edge\n";
                return neigh == cell - col || neigh == cell + col || neigh == cell + 1;
            } else if(cell % col == col - 1) { // if the cell is on the right edge
                // std::cout << "right edge\n";
                return neigh == cell - col || neigh == cell + col || neigh == cell - 1;
            } else {
                // std::cout << "random one\n";
                return neigh == cell - col || neigh == cell + col || neigh == cell - 1 || neigh == cell  + 1;
            }
        }
    }
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall (int cell, int neigh) {
    if(neigh > cell) { // either below or to the right of cell
        if(neigh - cell == col) { // if neigh is below cell
            theMaze.at(cell - 1).setBot(false);
        } else { // directly to the right of cell
            theMaze.at(cell - 1).setRight(false);
        }
    } else { // above or to the left
        if(cell - neigh == col) { // above cell
            theMaze.at(cell - 1).setTop(false);
        } else { // to the left of cell
            theMaze.at(cell - 1).setLeft(false);
        }
    }
}

//print the maze
// tested
void maze::printMaze() {
    // top row
    for(int j = 0; j < col; ++j) {
        if(theMaze.at(j).getTop()) {
            std::cout << " _";
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