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
	Joke
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
		friend std::ostream& operator<<(std::ostream& os, Card& c);
};

class Club : public Card {
	private:
		Rank rank;
		Color color;
		Kind kind;
	public:
		Club();
		Club(Rank r);
		friend std::ostream& operator<<(std::ostream& os, Club& c);

};

class Diamond : public Card {
	private:
		Color color;
		Kind kind;
		Rank rank;
	public:
		Diamond();
		Diamond(Rank r);
		friend std::ostream& operator<<(std::ostream& os, Diamond& c);

};

class Heart : public Card {
	private:
		Rank rank;
		Kind kind;
		Color color;
	public:
		Heart();
		Heart(Rank r);
		friend std::ostream& operator<<(std::ostream& os, Heart& c);

};

class Spade : public Card {
	private:
		Kind kind;
		Rank rank;
		Color color;
	public:
		Spade();
		Spade(Rank r);
		friend std::ostream& operator<<(std::ostream& os, Spade& c);

};

class Joker : public Card {
	private:
		Color color;
		Rank rank;
		Kind kind;
	public:
		Joker();
		Joker(Color c);
		friend std::ostream& operator<<(std::ostream& os, Joker& c);
};

struct Deck : public std::deque<Card*> {
		using std::deque<Card*>::deque;
};

std::ostream& operator<<(std::ostream& os, Rank& r);

