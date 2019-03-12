#include "card.hpp"

int main() {
	Deck d {
		new Club(Ace),
		new Diamond(Ace),
		new Heart(Ace),
		new Spade(Ace),
	};
	std::cout << *(d[0]) << std::endl;
	return 0;
}
