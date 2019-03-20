# Minesweeper

## Approach

It looks like there are a couple of stages to the program

- Create the Grid
- Lay the mines
- Calculate the numbers
- Game Loop

## Create The Grid
- [ ] Tile Class
- [ ] Grid Class - Contains Tile Class

## Lay The Mines
- [ ] Change value to update Tile Texture (Use tile.setTile)
- [ ] Update texture (Use tile.redrawSprite())

## Calculate The Numbers
- [ ] Interface for generating numbers (Use grid.calculateNumbers)
- [ ] Interface between board states (Use setTile and redrawSprite in the game loop)

## Game Loop
- [ ] Game Class (runs the program to clean up main)
- [ ] Update all textures (setTile and redrawSprites)

## Files
- [x] **main.cpp:** Driver for the game
- [ ] **grid.cpp, grid.hpp:** Class that holds the grid information
- [ ] **tile.cpp, tile.hpp:** Holds the mine, standard, and tile classes
- [ ] **game.cpp, game.hpp:** Holds game running data

