#include <iostream>
#include "Card.hpp"
#include <deque>
#include <vector>
#include <ctime>

/* Steps 
    1. Gather the cards
    2. Shuffle the deck
    3. Deal the deck
    4. Draw top card from each deck
    5. Compare
    6. If not war, collect spoils to winners hand, but if war, repeat step 4 with top 3 cards (if 3 are available from each party)
    7. If someome has pile of 0, other player wins

                                                    <---  3 With top 3 cards
                                                    |               ^
                                                    |               |
                                                    |              No
                                                    |               ^
                                                    |               |
                                                    |           Player 1 Smaller -> yes -> Give player two all cards to bottom
                                                    |                ^
                                                    |                |
                                                    |                No
                                                    |                 ^
                                                   \ /                |
    Collect -> Shuffle -> Deal -> Draw Top Card From Decks -> Player 1 bigger? -> yes -> Give player one all cards to bottom
*/

// step 1. Gather Deck
// step 2. Shuffle Deck
// Step 3. Deal Deck
// Step 4. Check deck lenghts, if someone has 0, other player wins
// Step 5. Draw hand
// Step 6. Compare
// Step 7. If not war, gather cards and go to step4, if war, repeat step 5 with 3 cards (or however many the max cards are in other player's hand)

/*
        going to have 3 deques and 2 vectors
        deque 1 - initial deque for the cards at the beginning of the game
        deque 2 - deque for player 1
        deque 2 - deque for player 2
        vector 1 - place pile for player 1
        vector 2 - place pile for player 2
    */

// possible methods
// build - build the initial deck
// shuffle - shuffle the deck
// deal - deals to each player
// draw - draw out cards into draw pile and compares the last one drawn
// gather - move draw pile cards into winner's deck

void shuffle(std::deque<Card> &deck)
{
  for (int i = 0; i < 52; ++i)
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

  std::cout << "Player 1 drew the " << player1Pile[player1Pile.size() - 1].rank << " of " << player1Pile[player1Pile.size() - 1].suit << '\n';
  std::cout << "Player 2 drew the " << player2Pile[player2Pile.size() - 1].rank << " of " << player2Pile[player2Pile.size() - 1].suit << '\n';
}

void gather(std::deque<Card> &winner, std::vector<Card> &player1Place, std::vector<Card> &player2Place)
{
  for (int i = 0; i < player1Place.size() - 1; ++i)
  {
    // add the cards to the bottom of the deck
    winner.push_front(player1Place[i]);
    winner.push_front(player2Place[i]);
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

  std::deque<Card> player1;
  std::deque<Card> player2;

  deal(mainDeck, player1, player2);

  std::vector<Card> player1PlacePile;
  std::vector<Card> player2PlacePile;

  // set up the game loop
  while (player1.size() > 0 && player2.size() > 0)
  {
    std::cout << "Player 1 Deck size: " << player1.size() << " cards.\n";
    std::cout << "Player 2 Deck size: " << player2.size() << " cards.\n";

    draw(player1, player2, player1PlacePile, player2PlacePile, 1);

    switch (compare(player1PlacePile[player1PlacePile.size() - 1].rank, player2PlacePile[player2PlacePile.size() - 1].rank))
    {
    case 1:
      std::cout << "Player 1 took this battle.\n";
      gather(player1, player1PlacePile, player2PlacePile);
      break;
    case -1:
      std::cout << "Player 2 took this battle.\n";
      gather(player2, player1PlacePile, player2PlacePile);
      break;
    default:
      std::cout << "WAR\n";
      int result;
      do
      {
        draw(player1, player2, player1PlacePile, player2PlacePile, 3);
        result = compare(player1PlacePile[player1PlacePile.size() - 1].rank, player2PlacePile[player2PlacePile.size() - 1].rank);
      } while (result == 0);

      if (result == 1)
      {
        std::cout << "Player 1 took this battle.\n";
        gather(player1, player1PlacePile, player2PlacePile);
      }
      else
      {
        std::cout << "Player 2 took this battle.\n";
        gather(player2, player1PlacePile, player2PlacePile);
      }
    }
  }

  std::cout << (player1.size() == 0) ? "Player 2 Won the war\n" : "Player 1 won the war\n";

  return 0;
}