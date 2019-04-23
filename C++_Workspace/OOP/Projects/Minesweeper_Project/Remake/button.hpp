#pragma once
#include <SFML/Graphics.hpp>

class Button {
    private:
        std::string text;
        sf::IntRect rect;
    public:
        Button();
        Button(int x, int y, int width, int height, std::string btnText);
        bool isClicked(int x, int y);
};