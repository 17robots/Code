#include <deque>
#include <vector>
#include <ctime>
#include <iostream>
#include <random>
#include <algorithm>

enum Suit
{
  Clubs = 1,
  Diamonds,
  Hearts,
  Spades
};

std::initializer_list<Suit> allSuits = {Clubs, Diamonds, Hearts, Spades}; // so that we can build the decks later

enum Rank
{
  Two = 2,
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

std::initializer_list<Rank> allRanks = {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace}; // so that we can build the decks later

struct Card
{
  Suit suit;
  Rank rank;
  Card(Suit newSuit, Rank newRank) : suit(newSuit), rank(newRank) {} // constructor
};

