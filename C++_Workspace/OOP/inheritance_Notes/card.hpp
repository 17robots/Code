#ifndef CARD_HPP
#define CARD_HPP

enum Suit {};
enum Rank {};

enum Color {
  Black,
  Red
};

struct Card {
  Suit suit;
  Rank rank;
};

struct StandardCard : Card {
  StandardCard(Suit s, Rank r) : suit(s), rank(r) {}
  Suit suit;
  Rank rank;
};

struct Joker : Card {
  Joker(Color c) : color(c) {}
  Color c;
};

struct UnoCard : Card {

};

struct ReverseCard : UnoCard {

};

struct SkipCard : UnoCard {

};

struct Deck : std::deque<Card*> {
  using std::deque<Card*>::deque;
};

#endif
