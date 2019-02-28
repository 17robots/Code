#include "Card.h"
#include <deque>
#include <algorithm>
#include <random>

class Game {
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
  int MAX_ROUNDS;

public:
  Game() : player1Wins(0), player2Wins(0), totalWars(0), totalRounds(0), MAX_ROUNDS(50001) {}
  void initialize() { // this sets up all of the cards based on the bits in the char. it goes up to 12, then shifts by 4, then goes up by 12, then shifts again, then goes up by 12 then shifts then up by 12 
    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 13; ++j) {
        this->mainDeck.push_back(Card(static_cast<char>(4 * i + j))); // using the constructor of the card based off the char
      }
    }
  }
  void deal() {
    std::random_device rng;
    std::minstd_rand prng(rng());
    std::shuffle(mainDeck.begin(), mainDeck.end(), prng); // random number generators 

    for (auto i = this->mainDeck.begin(); i != this->mainDeck.end(); ++i) { // dealing all of the cards in the main deck to the players
      if ((i - this->mainDeck.begin()) % 2 == 0) {
        this->player1Deck.push_back(*i);
      } else {
        this->player2Deck.push_back(*i);
      }
    }
  }
  void draw(int cardsToDraw) {
    int drawAmount = 1;
    if (this->player1Deck.size() < cardsToDraw || this->player2Deck.size() < cardsToDraw) { // base draw amount on who has the most cards or cardsToDraw
      drawAmount = (this->player1Deck.size() < this->player2Deck.size()) ? this->player1Deck.size() : this->player2Deck.size();
    } else {
      drawAmount = cardsToDraw;
    };

    for (int i = 0; i < drawAmount; ++i) { // actually draw the cards
      this->player1PlacePile.push_back(this->player1Deck[this->player1Deck.size() - 1]);
      this->player1Deck.pop_back();
      this->player2PlacePile.push_back(this->player2Deck[this->player2Deck.size() - 1]);
      this->player2Deck.pop_back();
    }
  }
  void gather(std::deque<Card> &winner) {
    for (int i = 0; i < player1PlacePile.size(); ++i) {
      // add the cards to the bottom of the deck
      winner.push_front(this->player1PlacePile.at(i));
      winner.push_front(this->player2PlacePile.at(i));
    }

    // clear the cards from the place pile
    this->player1PlacePile.clear();
    this->player1PlacePile.shrink_to_fit();
    this->player2PlacePile.clear();
    this->player2PlacePile.shrink_to_fit();
  }
  int compare(Card& a, Card& b) { // using the comparison operator from the card class
    if (a < b) {
      return 1;
    }
    else if (a > b) {
      return -1;
    } else {
      return 0;
    }
  }

  void run() { // main game logic facilitation for the game
    if (this->mainDeck.empty()) {
      this->initialize();
    } // if the deck wasn't initialized, init
    this->deal();
    while ((this->player1Deck.size() > 0 && this->player2Deck.size() > 0) && this->totalRounds < this->MAX_ROUNDS) {
      ++this->totalRounds;
      this->draw(1); // draw the cards
      switch (this->compare(this->player1PlacePile.at(this->player1PlacePile.size() - 1), this->player2PlacePile.at(this->player2PlacePile.size() - 1))) {
        case 1: {
          this->gather(this->player1Deck);
          ++this->player1Wins;
          break;
        }
        case -1: {
          this->gather(this->player2Deck);
          ++this->player2Wins;
          break;
        }
        default: {
          int result;
          do {
            ++this->totalWars;
            this->draw(3);
            result = this->compare(this->player1PlacePile.at(this->player1PlacePile.size() - 1), this->player2PlacePile.at(this->player2PlacePile.size() - 1));
          } while (result == 0);

          if (result == 1) {
            this->gather(this->player1Deck);
            ++this->player1Wins;
          }
          else {
            this->gather(this->player2Deck);
            ++this->player2Wins;
          }
          break;
        }
      }
    }
  }

  friend std::ostream& operator << (std::ostream& os, Game& game) { // making the output so there is no individual method necessary for the game to print its stuff - also allows us to keep the things we want hidden and not outputted
    os << ((game.totalRounds == game.MAX_ROUNDS) ? "Reached Max Number Of Rounds\n" : "");
    os << "Outcome of the war:\n";
    os << "Battle Played: " << game.totalRounds << '\n';
    os << "Battles won by Player 1: " << game.player1Wins << '\n';
    os << "Battles won by Player 2: " << game.player2Wins << '\n';
    os << "Total Wars: " << game.totalWars << '\n';
    os << ((game.totalRounds == game.MAX_ROUNDS) ? ((game.player1Wins < game.player2Wins) ? "Player 2 wins by default.\n" : "Player 1 wins by default.\n") : ((game.player1Deck.size() == 0) ? "Player 2 has won the war.\n" : "Player 1 has won the war.\n"));
    return os;
  }
};
