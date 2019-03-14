#pragma once
#include <iostream>
#include <deque>
#include <iterator>

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

enum Kind {
  StandardCard,
  JokerCard
};

enum Color {
  Black,
  Red
};

enum Suit {
  Clubs,
  Diamonds,
  Hearts,
  Spades
};

class Card {
  private:
  Rank rank;
  Color color;
  Kind kind;
  public:
  Card(Rank r, Color c, Kind k): rank(r), color(c), kind(k) {}
  Rank getRank() { return rank; }
  Color getColor() { return color; }
  Kind getKind() { return kind; }
  bool isStandard() { return kind == StandardCard; }
  bool isJoker() { return kind == JokerCard; }
  virtual std::ostream& print(std::ostream& os) {
    return os<< "Card";
  }
  friend std::ostream& operator<<(std::ostream& os, Card& c) {
    return c.print(os);
  }
};

class Standard : public Card {
  private:
  Suit suit;
  public:
  Standard(Rank r, Color c, Kind k, Suit s) : Card(r, c, k), suit(s) {}
  Suit getSuit() { return suit; }
  std::ostream& print(std::ostream& os) override {
    return os << getRank() << " of " << getSuit();
  }
};

class Joker : public Card {
  public:
  Joker(Color c) : Card(Joke, c, JokerCard) {}
  std::ostream& print(std::ostream& os) override {
    return os << this->getColor() << " " << this->getColor();
  }
};

class Club : public Standard {
  public:
  Club(Rank r): Standard(r, Black, StandardCard, Clubs) {}
};

class Diamond : public Standard {
  public:
  Diamond(Rank r): Standard(r, Red, StandardCard, Diamonds) {}
};

class Heart : public Standard {
  public:
  Heart(Rank r) : Standard(r, Red, StandardCard, Hearts) {}
};

class Spade : public Standard {
  public:
  Spade(Rank r) : Standard(r, Black, StandardCard, Spades) {}
};

struct Deck : public std::deque<Card*> {
  using std::deque<Card*>::deque;
};

std::ostream& operator<<(std::ostream& os, Rank& r) {
  switch(r) {
    case Two: return os << "2";
    case Three: return os << "3";
    case Four: return os << "4";
    case Five: return os << "5";
    case Six: return os << "6";
    case Seven: return os << "7";
    case Eight: return os << "8";
    case Nine: return os << "9";
    case Ten: return os << "10";
    case Jack: return os << "Jack";
    case Queen: return os << "Queen";
    case King: return os << "King";
    case Ace: return os << "Ace";
    case Joke: return os << "Joker";
  }
}

std::ostream& operator<<(std::ostream& os, Color& c) {
  switch(c) {
    case Black: return os << "Black";
    case Red: return os << "Red";
  }
}

std::ostream& operator<<(std::ostream& os, Kind& k) {
  switch(k) {
    case StandardCard: return os << "Standard Card";
    case JokerCard: return os << "Joker Card";
  }
}

std::ostream& operator<<(std::ostream& os, Suit& s) {
  switch(s) {
    case Clubs: return os << "Clubs";
    case Diamonds: return os << "Diamonds";
    case Hearts: return os << "Hearts";
    case Spades: return os << "Spades";
  }
}

std::ostream& operator<<(std::ostream& os, Deck& d) {
  for(auto x : d) {
    os << *x << "\n";
  }
}