#ifndef CARD_HPP
#define CARD_HPP

enum Suit {
	Clubs,
	Diamonds,
	Hearts,
	Spades
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

enum Color {
	Black,
	Red
};

struct CardVTable {
	void (*color_fn)(Card const*) = nullptr;
	void (*print_fn)(Card const*, std::ostream&) = nullptr;
};

struct StandardCardVTable : CardVTable {
	StandardCardVTable() {
		color_fn = StandardCard::get_color();
		print_fn = StandardCard::do_print();
	}
};

extern CardVTable cardVTable;
struct Card {
	Card() {
		vptr = &cardVTable;
	}

	Color getColor()  const {
		return vptr->color_fn(this);
	}

	void print(std::ostream& os) const {
		vptr->print_fn(this, os);
	}

	CardVTable* vptr;	
};

struct StandardCard : Card {
	StandardCard(Rank r, Suit s) : rank(r), suit(s) {
		
	}
};

struct JokerCard : Card {

};

#endif
