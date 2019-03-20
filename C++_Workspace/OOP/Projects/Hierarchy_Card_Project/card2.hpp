#pragma once

#include <iostream>
#include <deque>
#include <iterator>
#include <string>

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
  Ace
};

enum Color {
  Black,
  Red
};

std::string getNameFromEnum(const Rank& c);
std::string getNameFromEnum(const Color& c);

class Card {
    protected:
        Color color;
    public:
      Card() {}
      Card(Color c) : color(c) {}
      virtual Color getColor() const = 0;
      virtual std::ostream& print(std::ostream& os) const = 0;
};

class Joker : public Card {
    public:
      Joker();
      Joker(Color c) : Card(c) {}
      Color getColor() const override { return Card::color; }
      std::ostream& print(std::ostream& os) const override { return os << getNameFromEnum(Card::color) << " Joker"; }
};

class StandardCard : public Card {
  protected:
    Rank rank;
  public:
    StandardCard(Rank r, Color c) : rank(r), Card() {}
    virtual Rank getRank() const = 0;
};

class Club : public StandardCard {
  public:
    Club();
    Club(Rank r) : StandardCard(r, Black) {}
    Color getColor() const override { return Black; }
    std::ostream& print(std::ostream& os) const override { return os << getNameFromEnum(StandardCard::rank) << " of Clubs"; }
    Rank getRank() const override { return StandardCard::rank; }
};

class Diamond : public StandardCard {
  public:
    Diamond();
    Diamond(Rank r) : StandardCard(r, Red) {}
    Color getColor() const override {return Red; }
    std::ostream& print(std::ostream& os) const override {return os << getNameFromEnum(StandardCard::rank) << " of Diamonds"; }
    Rank getRank() const override {return StandardCard::rank; }
};

class Heart : public StandardCard {
  public:
    Heart();
    Heart(Rank r) : StandardCard(r, Red) {}
    Color getColor() const override { return Red; }
    std::ostream& print(std::ostream& os) const override { return os << getNameFromEnum(StandardCard::rank) << " of Hearts"; }
    Rank getRank() const override { return StandardCard::rank; }
};

class Spade : public StandardCard {
  public:
    Spade();
    Spade(Rank r) : StandardCard(r, Black) {}
    Color getColor() const override { return Black; }
    std::ostream& print(std::ostream& os) const override { return os << getNameFromEnum(StandardCard::rank) << " of Spades"; }
    Rank getRank() const override { return StandardCard::rank; }
};

struct Deck : std::deque<Card*> {
  using std::deque<Card*>::deque;
};

std::ostream& operator<<(std::ostream& os, Card& c) {return c.print(os); }

std::string getNameFromEnum(const Rank& c) {
  switch(c) {
    case Two: return "2";
    case Three: return "3";
    case Four: return "4";
    case Five: return "5";
    case Six: return "6";
    case Seven: return "7";
    case Eight: return "8";
    case Nine: return "9";
    case Ten: return "10";
    case Jack: return "Jack";
    case Queen: return "Queen";
    case King: return "King";
    case Ace: return "Ace";
    default: return "Not a rank";
  }
}

std::string getNameFromEnum(const Color& c) {
  switch(c) {
    case Red: return "Red";
    case Black: return "Black";
  }
}
