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
    
    maze(rows, cols).printMaze();
    
    // all tests pass
    {
        std::cout << "Random Element\n";
        assert(maze(rows, cols).neighbors(7,8) == true);
        assert(maze(rows, cols).neighbors(7,12) == true);
        assert(maze(rows, cols).neighbors(7,2) == true);
        assert(maze(rows, cols).neighbors(7,6) == true);
        assert(maze(rows, cols).neighbors(6,8) == false);
    }
    
    {
        std::cout << "Right Side\n";
        assert(maze(rows, cols).neighbors(9,8) == true);
        assert(maze(rows, cols).neighbors(9,4) == true);
        assert(maze(rows, cols).neighbors(9,14) == true);
        assert(maze(rows, cols).neighbors(9,10) == false);
    }
    {
        std::cout << "Left Side\n";
        assert(maze(rows, cols).neighbors(5,6) == true);
        assert(maze(rows, cols).neighbors(5,0) == true);
        assert(maze(rows, cols).neighbors(5,10) == true);
        assert(maze(rows, cols).neighbors(5,4) == false);
    }
    {
        std::cout << "Top Row\n";
        assert(maze(rows, cols).neighbors(3,4) == true);
        assert(maze(rows, cols).neighbors(3,2) == true);
        assert(maze(rows, cols).neighbors(3,8) == true);
        assert(maze(rows, cols).neighbors(3,1) == false);
    }
    {
        std::cout << "Top Left Corner\n";
        assert(maze(rows, cols).neighbors(0,1) == true);
        assert(maze(rows, cols).neighbors(0,5) == true);
    }
    {
        std::cout << "Top Right Corner\n";
        assert(maze(rows, cols).neighbors(4,3) == true);
        assert(maze(rows, cols).neighbors(4,9) == true);
        assert(maze(rows, cols).neighbors(4,5) == false);
    }
    {
        std::cout << "Bottom Row\n";
        assert(maze(rows, cols).neighbors(22,23) == true);
        assert(maze(rows, cols).neighbors(22,21) == true);
        assert(maze(rows, cols).neighbors(22,17) == true);
    }
    {
        std::cout << "Bottom Left\n";
        assert(maze(rows, cols).neighbors(20,21) == true);
        assert(maze(rows, cols).neighbors(20,15) == true);
        assert(maze(rows, cols).neighbors(20,19) == false);
    }
    
    return 0;
}
