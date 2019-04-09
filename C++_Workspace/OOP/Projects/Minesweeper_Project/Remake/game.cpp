#include "game.hpp"

Game::Game() : w(32), grid(Grid("")) {
    window = new sf::RenderWindow(sf::VideoMode(400, 400), "Blank Window");    
}

Game::Game(int blockWidth, Grid grid) : w(blockWidth), grid(grid) {
    window = new sf::RenderWindow(sf::VideoMode(400,400), "Minesweeper");
    sf::RenderWindow newWindow(sf::VideoMode(400, 400), "Minesweeper!");
    this->getGrid().mineLay();
    this->getGrid().generateNumbers();
}

void Game::run() {
    // the grid will be created when the game is initialized (or be included in
    // the constructor), so we can just jump into laying the mines, creating the
    // numbers and running the game loop, unless we wanted to do that all in the
    // constructor of the game, which we can do
    // for now just write the code here and then do it later
    
    // game loop
    Grid grid = this->getGrid();
    sf::RenderWindow* window = this->getWindow();
    int width = this->getWidth();
    
    while(window->isOpen()) {
        sf::Vector2i pos = sf::Mouse::getPosition(*window);

        int x = pos.x / width;
        int y = pos.y / width;
        
        sf::Event e;
        while(window->pollEvent(e)) {
            if(e.type == sf::Event::MouseButtonPressed) {
                if(e.mouseButton.button == sf::Mouse::Left)
                    grid.getShown()[x][y] = grid.getTiles()[x][y];
                else if(e.mouseButton.button == sf::Mouse::Right)
                    grid.getShown()[x][y].setTile(11);
            }
        }
        
        window->clear(sf::Color::White);
        for(int i = 1; i <= 10; ++i) {
            for(int j = 1; j <= 10; j++) {
                if(grid.getShown()[x][y].getSpriteValue() == 9) {
                    grid.getShown()[x][y].setTile(grid.getTiles()[x][y].getSpriteValue());
                }
                grid.getSprite().setTextureRect(sf::IntRect(grid.getShown()[i][j].getSpriteValue() * width, 0, width, width));
                grid.getSprite().setPosition(i * width, j * width);
                window->draw(this->getGrid().getSprite());
            }
        }
        window->display();
    }
}
