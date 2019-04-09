#include "tile.hpp"

Tile::Tile() : spriteValue(0) { }

Tile::Tile(int spriteValue) : spriteValue(spriteValue) { }

void Tile::setTile(int newTile) {
    spriteValue = newTile;
}
