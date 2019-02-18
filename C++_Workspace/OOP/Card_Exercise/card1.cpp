#include "card1.hpp"

StandardCard::StandardCard() : {}
StandardCard::StandardCard(Suit s, Rank r) : {}

JokerCard::JokerCard() : color(Black), rank(Joker) {}
JokerCard::JokerCard(Color newColor) : color(newColor), rank(Joker) {}
