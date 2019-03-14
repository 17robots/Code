#include "card.hpp"

int main() {
    Deck d {
        new Club(Ace),
        new Diamond(Ace),
        new Heart(Ace),
        new Spade(Ace),
        new Joker(Red),
    };
    
    std::cout << d << '\n';
    
    return 0;
}