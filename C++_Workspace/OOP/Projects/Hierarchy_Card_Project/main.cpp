#include "card2.hpp"

int main() {
    Deck d {
        new Club(Ace),
        new Diamond(Ace),
        new Heart(Ace),
        new Spade(Ace),
        new Joker(Red)
    };
    
    for(auto const& x : d) {
        std::cout << *x << std::endl;
    }
    return 0;
}