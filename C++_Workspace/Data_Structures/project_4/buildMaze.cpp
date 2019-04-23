#include <iostream>
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
    
    maze(rows, cols).printMaze();
    
    return 0;
}
