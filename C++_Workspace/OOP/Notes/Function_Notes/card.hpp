#pragma once

#include <cassert>
#include <deque>
#include <iosfwd>
#include <stdexcept>

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

struct Card {
	Card() {
		print_fn = nullptr;
		color_fn = nullptr;
	}

	void print(std::ostream& os) const {
		print_fn(this, os);
	}
	
	Color getColor() {
		return color_fn(this);
	}

	void (*print_fn)(Card const*, std::ostream& os);
	Color (*color_fn)(Card const*);
};

struct StandardCard : Card {
	StandardCard() {
		print_fn = do_print;
		color_fn = do_get_color;
	}

	StandardCard(Rank r, Suit s) : suit(s), rank(r) {}
	static void do_print(Card const* self, std::ostream& os);
	
	static Color do_get_color(Card const* self) {
		StandardCard const* ptr = static_cast<StandardCard const*>(self);
		return static_cast<Color>(ptr->suit > Diamonds);
	}

	Rank rank;
	Suit suit;
};

struct JokerCard : Card {
	JokerCard(Color c) : color(c) {
		print_fn = do_print;
		color_fn = do_get_color;
		rank = Joker;
	}

	static void do_print(Card const* self, std::ostream& os);
	static Color do_get_color(Card const* self) {
		JokerCard const* ptr = static_cast<JokerCard const*>(self);
		return ptr->color;
	}

	Color color;
	Rank rank;
};

struct Deck : std::deque<Card*> {
	using std::deque<Card*>::deque;
};

std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Color c);
std::ostream& operator<<(std::ostream& os, StandardCard const& c);
std::ostream& operator<<(std::ostream& os, JokerCard const& c);
std::ostream& operator<<(std::ostream& os, Card const& c);
std::ostream& operator<<(std::ostream& os, Deck const& d);

