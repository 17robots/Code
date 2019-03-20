#pragma once

class Tile {
    private:
    int spriteValue;
    
    public:
    Tile();
    Tile(int spriteValue);
    setTile(int newTile);
    int getSpriteValue() { return spriteValue; }
};
