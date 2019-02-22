#ifndef CARD1_HPP
#define CARD1_HPP

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

class Card {
	private:
		Suit s;
		Rank r;
	public:
		
};

class Joker {
	private:
		Color c;
		Rank r;
	public:
		
};

class PlayingCard {
	private:
		Rank r;
		Suit s,
		Color c;
		union {
			Card as_Standard_Card;
			Joker as_Joker_Card;
		};	
	public:
		
};

#endif
