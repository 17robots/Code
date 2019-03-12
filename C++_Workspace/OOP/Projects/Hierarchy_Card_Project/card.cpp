#include "card.hpp"

Club::Club() {}

Club::Club(Rank r) : rank(r), color(Black), kind(Standard) {}

Diamond::Diamond() {}

Diamond::Diamond(Rank r) : rank(r), color(Red), kind(Standard) {}

Heart::Heart() {}

Heart::Heart(Rank r) : rank(r), color(Red), kind(Standard) {}

Spade::Spade() {}

Spade::Spade(Rank r) : rank(r), color(Black), kind(Standard) {}

Joker::Joker() {}

Joker::Joker(Color c) : rank(Joke), color(c), kind(JokerCard) {}

std::ostream& operator<<(std::ostream& os, Rank& r) {
	switch(r) {
		case Two: return os<< "2";
		case Three: return os<< "3";
		case Four: return os << "4";
		case Five: return os << "5";
		case Six: return os << "6";
		case Seven: return os << "7";
		case Eight: return os << "8";
		case Nine: return os << "9";
		case Ten: return os << "10";
		case Jack: return os << "JA";
		case Queen: return os << "Q";
		case King: return os << "K";
		case Ace: return os << "A";
		case Joke: return os << "JO";
	}
}
std::ostream& operator<<(std::ostream& os, Club& c) { return os << c.getRank() << " of Clubs"; }
std::ostream& operator<<(std::ostream& os, Diamond& c) { return os << c.getRank() << " of Diamonds"; }
std::ostream& operator<<(std::ostream& os, Heart& c) { return os << c.getRank() << " of Hearts"; }
std::ostream& operator<<(std::ostream& os, Spade& c) { return os << c.getRank() << " of Spades"; }
std::ostream& operator<<(std::ostream& os, Joker& c) { return os << (c.getColor() == Black ? "Black " : "Red ") << c.getRank(); }
std::ostream& operator<<(std::ostream& os, Card& c) { return os << "Card"; }
