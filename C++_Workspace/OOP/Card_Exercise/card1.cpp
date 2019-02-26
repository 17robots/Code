#include "card1.hpp"

std::ostream& Card::operator <<(std::ostream& os, Card &card) { return os << "" }

std::ostream& Joker::operator <<(std::ostream& os, Joker &joker) { return os << }

PlayingCard::PlayingCard() {}

PlayingCard::PlayingCard(Color color) : c(color), r(Joker) {}

PlayingCard::PlayingCard(Suit suit, Rank rank) : s(suit), r(rank), c((suit == Clubs || suit == Spades) ? Black : Red){}

PlayingCard::bool isJoker(){ return this->rank() == Joker; }

bool PlayingCard::isCard(){ return !(this->isJoker()); }

Card PlayingCard::asCard() { return Card(this->suit(), this->rank()); }

Joker PlayingCard::asJoker() { return Joker(this->color(), this->rank()); }

Rank rank() { return r; }

Suit suit() { return s; }

Color color() { return c; }

bool PlayingCard::operator==(PlayingCard& card){ return (this->rank() == Joker ? (this->rank() == card.rank() && this->color() == card.color()) : (this->rank() == card.rank() && this->suit() == card.suit())); }

bool PlayingCard::operator==(Card& card) {return (this->rank() == card.rank() && this->suit() == card.suit()); }

bool PlayingCard::operator==(Joker& joker) {return (this->rank() == card.rank() && this->color() == card.color()); }

std::ostream& PlayingCard::operator <<(std::ostream& os, PlayingCard &card) { return os << this->isJoker() ? this->asJoker() : this->asCard(); }