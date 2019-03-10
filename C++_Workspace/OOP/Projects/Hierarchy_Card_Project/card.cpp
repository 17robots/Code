#include "card.hpp"

Club::Club() {}

Club::Club(Rank r) : rank(r), color(Black), kind(Standard) {}

std::ostream& Club::operator<<(std::ostream& os) {
	return os << this->getRank() << " of Clubs";
}

Diamond::Diamond() {}

Diamond::Diamond(Rank r) : rank(r), color(Red), kind(Standard) {}

std::ostream& Diamond::operator<<(std::ostream& os) {
	return os << this->getRank() << " of Diamonds";
}

Heart::Heart() {}

Heart::Heart(Rank r) : rank(r), color(Red), kind(Standard) {}

std::ostream& Heart::operator<<(std::ostream& os) {
	return os << this->getRank() << " of Hearts";
}

Spade::Spade() {}

Spade::Spade(Rank r) : rank(r), color(Black), kind(Standard) {}

std::ostream& Spade::operator<<(std::ostream& os) {
	return os << this->getRank() << " of Spades";
}

Joker::Joker() {}

Joker::Joker(Color c) : rank(Joker), color(c), kind(JokerCard) {}

std::ostream& Joker::operator<<(std::ostream& os) {
	return os << (this->getColor() == Black ? "Black " : "Red ") << c.getRank();
}

std::ostream& operator<<(std::ostream& os, Rank& r) {
	switch(r) {
		case Two: return "2";
		case Three: return "3";
		case Four: return "4";
		case Five: return "5";
		case Six: return "6";
		case Seven: return "7";
		case Eight: return "8";
		case Nine: return "9";
		case Ten: return "10";
		case Jack: return "JA";
		case Queen: return "Q";
		case King: return "K";
		case Ace: return "A";
		case Joker: return "JO";
	}
}

