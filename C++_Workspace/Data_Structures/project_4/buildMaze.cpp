#include <iostream>
#include <cassert>
#include "maze.h"
#include "DisjSets.h"


int main() {
    std::cout << "============= Maze Builder =============\n";
    std::cout << "Enter the number of rows in the maze (greater than 1): ";
    
    int rows;
    std::cin >> rows;
    
    while(std::cin.fail() || rows <= 1) {
        std::cout << "Please make sure your row is a number  greater than 1.\n";
        std::cout << "Enter the number of rows in the maze (greater than 1): ";
        std::cin >> rows;
    }
    
    std::cout << "Enter the number of columns in the maze (greater than 1): ";
    
    int cols;
    std::cin >> cols;
    
    while(std::cin.fail() || rows <= 1) {
        std::cout << "Please make sure your column is a number  greater than 1.\n";
        std::cout << "Enter the number of columns in the maze (greater than 1): ";
        std::cin >> cols;
    }
    
    DisjSets disj(rows * cols);
    maze mainMaze(rows, cols);
    
    mainMaze.printMaze();
    
    while(!disj.isConnected(0, rows * cols - 1)) {
        std::cout << "Enter 1 num: ";
        int x;
        std::cin >> x;
        std::cout << "Enter 2 num: ";
        int y;
        std::cin >> y;
        if(mainMaze.neighbors(x,y)) {
            mainMaze.smashWall(x,y);
            mainMaze.smashWall(y,x);
            mainMaze.printMaze();
            disj.unionSets(disj.find(x), disj.find(y));
        } else {
            std::cout << "They are not neighbors\n";
        }
    }
    
    std::cout << "Maze Built!\n";
    std::cout << "Final Maze:\n";
    
    mainMaze.printMaze();
    
    
    
    return 0;
}
