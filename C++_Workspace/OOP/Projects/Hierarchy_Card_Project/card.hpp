#pragma once
#include <iostream>
#include <deque>

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

enum Kind {
	Standard,
	JokerCard
};

class Card {
	private:
		Rank rank;
		Color color;
		Kind kind;
	public:
		Rank getRank() { return rank; }
		Color getColor() { return color; }
		Kind getKind() { return kind; }
		bool isJoker() { return this->getKind() == JokerCard; }
		bool isStandard() { return !(this->isJoker()); }
};

class Club : Card {
	public:
		Club();
		Club(Rank r);
		std::ostream& operator<<(std::ostream& os);
};

class Diamond : Card {
	public:
		Diamond();
		Diamond(Rank r);
		std::ostream& operator<<(std::ostream& os);
};

class Heart : Card {
	public:
		Heart();
		Heart(Rank r);
		std::ostream& operator<<(std::ostream& os);
};

class Spade : Card {
	public:
		Spade();
		Spade(Rank r);
		std::ostream& operator<<(std::ostream& os);
};

class Joker : Card {
	public:
		Joker();
		Joker(Color c);
		std::ostream& operator<<(std::ostream& os);
};

struct  Deck : std::deque<Card*> {
		using std::deque<Card*>::deque;
};

std::ostream& operator<<(std::ostream& os, Rank& r);

