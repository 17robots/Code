#include "card.hpp"

int main() {
	Deck d {
		new Club(Ace),
		new Diamond(Ace),
		new Heart(Ace),
		new Spade(Ace),
	};
	
	for(auto x : d) {
		std::cout << x << '\n';
		std::cout << "Card type: " << (x->isJoker() ? "Joker\n" : "Standard\n");
	}
	return 0;
}
