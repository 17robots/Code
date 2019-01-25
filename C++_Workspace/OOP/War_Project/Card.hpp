enum Suit
{
  Clubs = 1,
  Diamonds,
  Hearts,
  Spades
};

constexpr std::initializer_list<Suit> allSuits = {Clubs, Diamonds, Hearts, Spades};

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

constexpr std::initializer_list<Rank> allRanks = {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

struct Card
{
  Suit suit;
  Rank rank;
  Card(Suit newSuit, Rank newRank) : suit(newSuit), rank(newRank) {}
};