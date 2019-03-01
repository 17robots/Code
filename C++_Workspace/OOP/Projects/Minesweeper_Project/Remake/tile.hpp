#ifndef TILE_HPP
#define TILE_HPP

class Tile {
    private:
    sf::Sprite s;
    int spriteValue;
    
    public:
    Tile();
    Tile(int spriteValue);
    setTile();
    redrawSprite();
};

#endif