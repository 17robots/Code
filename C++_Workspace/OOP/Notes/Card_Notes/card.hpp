#ifndef CARD_HPP
#define CARD_HPP

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

enum Suit {
	Clubs,
	Diamonds,
	Hearts,
	Spades
};

enum Color {
	Black,
	Red
};

struct Card {
	enum Kind {
		StandardCard,
		Joker
	};

	// virtual function will dispatch different signatures based on the type of "this"
	virtual void print(std::ostream& os) const;	
};

struct StandardCard : Card {
	Rank r;
	Suit s;
	
	// Override function that when the derived class calls the function with this same parameter, do this code instead of what we have
	virtual void print(std::ostream& os) const override;
};

struct JokerCard : Card {
	Rank r;
	Suit s;
};

#endif
