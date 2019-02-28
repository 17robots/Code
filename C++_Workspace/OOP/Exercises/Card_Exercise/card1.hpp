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
		Card(Suit s, Rank r);
		operator <<(std::ostream& os, Card &card);
};

class Joker {
	private:
		Color c;
		Rank r;
	private:
		Joker(Color color, Rank rank);
		std::ostream& operator <<(std::ostream& os, Joker &joker);
		
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
		PlayingCard();
		PlayingCard(Color color);
		PlayingCard(Suit suit, Rank rank);
		bool isJoker();
		bool isCard();
		Card asCard();
		Joker asJoker();
		bool operator==(PlayingCard& card);
		bool operator==(Card& card);
		bool operator==(Joker& joker);
		std::ostream& operator <<(std::ostream& os, PlayingCard &card);
		Rank rank();
		Suit suit();
		Color color();
		
};

#endif
