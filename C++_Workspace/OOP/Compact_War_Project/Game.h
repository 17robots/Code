#include "Card.h"
#include <deque>
#include <algorithm>
#include <random>

class Game
{
private:
  std::deque<Card> mainDeck;
  std::deque<Card> player1Deck;
  std::deque<Card> player2Deck;
  std::vector<Card> player1PlacePile;
  std::vector<Card> player2PlacePile;

  int player1Wins;
  int player2Wins;
  int totalWars;
  int totalRounds;

  const int MAX_ROUNDS = 0;

public:
  Game() : player1Wins(0), player2Wins(0), totalWars(0), totalRounds(0) {}
  void initialize()
  {
    char something = 0;
    while (static_cast<int>(something) < 64)
    {
      mainDeck.push_back(Card(something));
      something = static_cast<char>(something + 1);
    }
  }
  void deal()
  {
    std::random_device rng;
    std::minstd_rand prng(rng());
    std::shuffle(mainDeck.begin(), mainDeck.end(), prng);

    for (auto i = dealPile.begin(); i != dealPile.end(); ++i)
    {
      if ((i - dealPile.begin()) % 2 == 0)
      {
        player1Deck.push_back(*i);
      }
      else
      {
        player2Deck.push_back(*i);
      }
    }
  }
  void draw(int cardsToDraw)
  {
    int drawAmount = 1;
    if (player1Deck.size() < cardsToDraw || player2Deck.size() < cardsToDraw)
    {
      drawAmount = (player1Deck.size() < player2Deck.size()) ? player1Deck.size() : player2Deck.size();
    }
    else
    {
      drawAmount = cardsToDraw;
    }

    for (int i = 0; i < drawAmount; ++i)
    {
      player1PlacePile.push_back(player1Deck[player1Deck.size() - 1]);
      player1Deck.pop_back();
      player2PlacePile.push_back(player2Deck[player2Deck.size() - 1]);
      player2Deck.pop_back();
    }
  }
  void gather(std::deque<Card> &winner)
  {
    for (int i = 0; i < player1PlacePile.size(); ++i)
    {
      // add the cards to the bottom of the deck
      winner.push_front(player1PlacePile.at(i));
      winner.push_front(player2PlacePile.at(i));
    }

    // clear the cards from the place pile
    player1PlacePile.clear();
    player1PlacePile.shrink_to_fit();
    player2PlacePile.clear();
    player2PlacePile.shrink_to_fit();
  }
  int compare(Card a, Card b)
  {
    if (a < b)
    {
      return 1;
    }
    else if (a > b)
    {
      return -1;
    }
    else
    {
      return 0;
    }
  }

  void run()
  {
    if (mainDeck.empty())
    {
      initialize();
    } // if the deck wasn't initialized, init
    while ((player1Deck.size() > 0 && player2Deck.size() > 0) && totalRounds < MAX_ROUNDS)
    {
      draw(1); // draw the cards
      switch (compare(player1PlacePile.at(player1PlacePile.size() - 1), player2PlacePile.at(player2PlacePile.size() - 1)))
      {
      case 1:
      {
        gather(player1Deck);
        ++player1Wins;
        break;
      }
      case -1:
      {
        gather(player2Deck);
        ++player2Wins;
        break;
      }
      default:
      {
        int result;
        do
        {
          ++totalWars;
          draw(3);
          result = compare((player1PlacePile.at(player1PlacePile.size() - 1), player2PlacePile.at(player2PlacePile.size() - 1)));
        } while (result == 0);

        if (result == 1)
        {
          gather(player1Deck);
          ++player1Wins;
        }
        else
        {
          gather(player2Deck);
          ++player2Wins;
        }
        break;
      }
      }
    }
  }
  
  void printResults() {
    std::cout << ((totalRounds == MAX_ROUNDS) ? "Reached Max Number Of Rounds\n" : "");
    std::cout << "Outcome of the war:\n";
    std::cout << "Battle Played: " << totalRounds << '\n';
    std::cout << "Battles won by Player 1: " << player1Wins << '\n';
    std::cout << "Battles won by Player 2: " << player2Wins << '\n';
    std::cout << "Total Wars: " << totalWars << '\n';
    std::cout << ((totalRounds == MAX_ROUNDS) ? ((player1Wins < player2Wins) ? "Player 2 wins by default.\n" : "Player 1 wins by default.\n") : ((player1Deck.size() == 0) ? "Player 2 has won the war.\n" : "Player 1 has won the war.\n"));
  }
  
  std::ostream& operator << (std::ostream& os, Game* game) {
    os << ((totalRounds == MAX_ROUNDS) ? "Reached Max Number Of Rounds\n" : "");
    os << "Outcome of the war:\n";
    os << "Battle Played: " << totalRounds << '\n';
    os << "Battles won by Player 1: " << player1Wins << '\n';
    os << "Battles won by Player 2: " << player2Wins << '\n';
    os << "Total Wars: " << totalWars << '\n';
    os << ((totalRounds == MAX_ROUNDS) ? ((player1Wins < player2Wins) ? "Player 2 wins by default.\n" : "Player 1 wins by default.\n") : ((player1Deck.size() == 0) ? "Player 2 has won the war.\n" : "Player 1 has won the war.\n"));
  }
}
