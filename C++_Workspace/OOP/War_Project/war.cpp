
#include "Card.hpp"

const int MAX_ROUNDS = 50001;

void shuffle(std::deque<Card> &deck)
{
  // perform random number of swaps between 26 and 52 with random cards
  int numSwaps = rand() % 53 + 26;
  for (int i = 0; i < numSwaps; ++i)
  {
    int firstCard = rand() % 52;
    int secondCard = rand() % 52;

    Card tmp = deck[firstCard];
    deck[firstCard] = deck[secondCard];
    deck[secondCard] = tmp;
  }
}

void deal(std::deque<Card> &dealPile, std::deque<Card> &player1, std::deque<Card> &player2)
{
  for (auto i = dealPile.begin(); i != dealPile.end(); ++i)
  {
    if ((i - dealPile.begin()) % 2 == 0)
    {
      player1.push_back(*i);
    }
    else
    {
      player2.push_back(*i);
    }
  }
}

void draw(std::deque<Card> &player1, std::deque<Card> &player2, std::vector<Card> &player1Pile, std::vector<Card> &player2Pile, int cardsToDraw)
{
  int drawAmount = 1;
  if (player1.size() < cardsToDraw || player2.size() < cardsToDraw)
  {
    drawAmount = (player1.size() < player2.size()) ? player1.size() : player2.size();
  }
  else
  {
    drawAmount = cardsToDraw;
  }

  for (int i = 0; i < drawAmount; ++i)
  {
    player1Pile.push_back(player1[player1.size() - 1]);
    player1.pop_back();
    player2Pile.push_back(player2[player2.size() - 1]);
    player2.pop_back();
  }
}

void gather(std::deque<Card> &winner, std::vector<Card> &player1Place, std::vector<Card> &player2Place)
{
  for (int i = 0; i < player1Place.size(); ++i)
  {
    // add the cards to the bottom of the deck
    winner.push_front(player1Place.at(i));
    winner.push_front(player2Place.at(i));
  }

  // clear the cards from the place pile
  player1Place.clear();
  player1Place.shrink_to_fit();
  player2Place.clear();
  player2Place.shrink_to_fit();
}

int compare(Rank &rank1, Rank &rank2)
{
  if (rank1 > rank2)
  {
    return 1;
  }
  else if (rank1 < rank2)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  std::cout << "Game of War Simulation\n";

  std::deque<Card> mainDeck;
  for (auto suit : allSuits)
  {
    for (auto rank : allRanks)
    {
      mainDeck.push_back(Card(suit, rank));
    }
  }

  srand(time(NULL));

  shuffle(mainDeck);
  // std::random_device r;
  // std::mt19937 g(r());
  // std::shuffle(mainDeck.begin(), mainDeck.end(), g);

  std::deque<Card> player1;
  std::deque<Card> player2;

  deal(mainDeck, player1, player2);

  std::vector<Card> player1PlacePile;
  std::vector<Card> player2PlacePile;

  // set up the game loop and counters
  int totalRounds = 0, player1Wins = 0, player2Wins = 0, totalWars = 0;
  while ((player1.size() > 0 && player2.size() > 0) && totalRounds < MAX_ROUNDS)
  {
    // std::cout << "Player 1 Deck size: " << player1.size() << " cards.\n";
    // std::cout << "Player 2 Deck size: " << player2.size() << " cards.\n";

    draw(player1, player2, player1PlacePile, player2PlacePile, 1);
    // std::cout << "Round: " << ++totalRounds << '\n';
    ++totalRounds;

    switch (compare(player1PlacePile.at(player1PlacePile.size() - 1).rank, player2PlacePile.at(player2PlacePile.size() - 1).rank))
    {
    case 1:
      gather(player1, player1PlacePile, player2PlacePile);
      ++player1Wins;
      break;
    case -1:
      gather(player2, player1PlacePile, player2PlacePile);
      ++player2Wins;
      break;
    default:
      int result;
      do
      {
        ++totalWars;
        draw(player1, player2, player1PlacePile, player2PlacePile, 3);
        result = compare(player1PlacePile.at(player1PlacePile.size() - 1).rank, player2PlacePile.at(player2PlacePile.size() - 1).rank);
      } while (result == 0);

      if (result == 1)
      {
        gather(player1, player1PlacePile, player2PlacePile);
        ++player1Wins;
      }
      else
      {
        gather(player2, player1PlacePile, player2PlacePile);
        ++player2Wins;
      }
    }
  }

  std::cout << ((totalRounds == MAX_ROUNDS) ? "Reached Max Number Of Rounds\n" : "");
  std::cout << "Outcome of the war:\n";
  std::cout << "Battle Played: " << totalRounds << '\n';
  std::cout << "Battles won by Player 1: " << player1Wins << '\n';
  std::cout << "Battles won by Player 2: " << player2Wins << '\n';
  std::cout << "Total Wars: " << totalWars << '\n';
  std::cout << ((totalRounds == MAX_ROUNDS) ? ((player1Wins < player2Wins) ? "Player 2 wins by default.\n" : "Player 1 wins by default.\n") : ((player1.size() == 0) ? "Player 2 has won the war.\n" : "Player 1 has won the war.\n"));

  return 0;
}
