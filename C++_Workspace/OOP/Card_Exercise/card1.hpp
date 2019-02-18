#include <string>

// this is the card class using the union

enum Color {
	Black,
	Red
};

struct Suit {
	Color color;
	int suitValue;
	Suit(Color newColor, int newSuitValue) : color(newColor), suitValue(newSuitValue) {}	
};

enum Rank {
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,
	Joker	
};

class StandardCard {
	private:
		Rank rank;
		Suit suit;
	public:
		StandardCard();
		StandardCard(Suit s, Rank r);	
};

class JokerCard {
	private:
		Color color;
		Rank rank;
	public:
		JokerCard();
		JokerCard(Color newColor);
		Color getColor();
};
