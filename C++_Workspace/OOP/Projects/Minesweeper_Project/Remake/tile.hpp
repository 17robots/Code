#pragma once

class Tile {
    private:
    int spriteValue;
    
    public:
    Tile();
    Tile(int spriteValue);
    void setTile(int newTile);
    int getSpriteValue() { return spriteValue; }
};
