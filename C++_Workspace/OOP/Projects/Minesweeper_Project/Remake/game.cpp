#include "game.hpp"

Game::Game(int blockWidth, Grid &grid) : w(blockWidth), grid(grid) {
    window = new sf::RenderWindow(sf::VideoMode(400,400), "Minesweeper");
    // sf::RenderWindow newWindow(sf::VideoMode(400, 400), "Minesweeper!");
}

void Game::run() {
    // the grid will be created when the game is initialized (or be included in
    // the constructor), so we can just jump into laying the mines, creating the
    // numbers and running the game loop, unless we wanted to do that all in the
    // constructor of the game, which we can do
    // for now just write the code here and then do it later
    
    // game loop
    this->getGrid().mineLay();
    this->getGrid().generateNumbers();

    int width = this->getWidth();
    
    while(this->getWindow()->isOpen()) {
        sf::Vector2i pos = sf::Mouse::getPosition(*this->getWindow());

        int x = pos.x / width;
        int y = pos.y / width;
        
        sf::Event e;
        while(this->getWindow()->pollEvent(e)) {
            if(e.type == sf::Event::MouseButtonPressed) {
                if(e.mouseButton.button == sf::Mouse::Left)
                    this->getGrid().getShown(x,y) = this->getGrid().getTiles(x,y);
                else if(e.mouseButton.button == sf::Mouse::Right)
                    this->getGrid().getShown(x,y).setTile(11);
            }
        }
        
        this->getWindow()->clear(sf::Color::White);
        for(int i = 1; i <= 10; ++i) {
            for(int j = 1; j <= 10; j++) {
                if(this->getGrid().getShown(x,y).getSpriteValue() == 9)
                    this->getGrid().getShown(x,y).setTile(this->getGrid().getTiles(x,y).getSpriteValue());
                
                std::cout << "i: " << i << " j: " << j << '\n';
                std::cout << this->getGrid().getShown(i,j).getSpriteValue() << '\n';
                this->getGrid().getSprite().setTextureRect(sf::IntRect(this->getGrid().getShown(i,j).getSpriteValue() * width, 0, width, width));
                this->getGrid().getSprite().setPosition(i * width, j * width);
                
                this->getWindow()->draw(this->getGrid().getSprite());
            }
        }
        this->getWindow()->display();
    }
}
