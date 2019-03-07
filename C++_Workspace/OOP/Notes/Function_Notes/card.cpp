#include "card.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Suit s) {
	switch(s) {
		case Clubs: return os << "C";
		case Diamonds: return os << "D";
		case Hearts: return os << "H";
		case Spades: return os << "S";
	}
}

std::ostream& operator<<(std::ostream& os, Rank r) {
	switch(r) {
		case Two: return os << "2";
		case Three: return os << "3";
		case Four: return os << "3";
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
		case Joker: return os << "JO";
	}
}
std::ostream& operator<<(std::ostream& os, Color c) {
	return os << (c == Black ? "B" : "R");
}

std::ostream& operator<<(std::ostream& os, StandardCard const& c) {
	return os << c.rank << " Of " << c.suit;
}

std::ostream& operator<<(std::ostream& os, JokerCard const& c) {
	return os << c.color << c.rank;
}

void StandardCard::do_print(Card const* c, std::ostream& os) {
	os << *static_cast<StandardCard const*>(c);
}

void JokerCard::do_print(Card const* c, std::ostream& os) {
	os << *static_cast<JokerCard const*>(c);
}

std::ostream& operator<<(std::ostream& os, Card const& c) {
	c.print(os);
	return os;
}

std::ostream& operator<<(std::ostream& os, Deck const& d) {
	for(auto x : d) {
		os << x << '\n';
	}
	return os;
}

