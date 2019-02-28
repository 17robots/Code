#include <iostream>

struct Suit {
	int suit;
	Suit(char card) : suit((card >> 4) & 0x3) {}
};

struct Rank {
	int rank;
	Rank(char card) : rank(card & 0xf) {}
};

class Card {
	private:
		Rank rank;
		Suit suit;
	public:
		Card(char something) : suit(something), rank(something) {}
		Card(Suit newSuit, Rank newRank) : suit(newSuit), rank(newRank) {}
		int getRank() { return rank.rank; }
		int getSuit() { return suit.suit; }
		bool operator == (Card& b) { this->getRank() == b.getRank() && this->getSuit() == b.getSuit(); }
		bool operator != (Card& b) { return !(*(this) == b); }
		bool operator <  (Card& b) {
			if(this->getRank() > b.getRank())
				return true;
			if(b.getRank() > this->getRank())
				return false;
			if(this->getRank() == b.getRank())
				return false;
		}
		bool operator >  (Card& b) { return b < *(this); }
		bool operator <= (Card& b) { return !(b < *(this)); }
		bool operator >= (Card& b) { return !(*(this) < b); }
		friend std::ostream& operator<<(std::ostream& os, const Suit& s) {
			switch(s.suit) {
				case 0: return os << "Clubs";
				case 1: return os << "Diamonds";
				case 2: return os << "Hearts";
				case 3: return os << "Spades";
			}
		}
		friend std::ostream& operator << (std::ostream& os, const Rank& r) {
			switch(r.rank) {
				case 0: return os << "2";
				case 1: return os << "3";
				case 2: return os << "4";
				case 3: return os << "5";
				case 4: return os << "6";
				case 5: return os << "7";
				case 6: return os << "8";
				case 7: return os << "9";
				case 8: return os << "10";
				case 9: return os << "J";
				case 10: return os << "Q";
				case 11: return os << "K";
				case 12: return os << "A";
			}
		}
		friend std::ostream& operator << (std::ostream& os, Card& c) { return os << c.getRank() << " of " << c.getSuit() << std::endl; }
};
