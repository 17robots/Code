#include "Card.h"

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
		
		const int MAX_ROUNDS = 0;
	public:
		Game() : player1Wins(0), player2Wins(0), totalWars(0), totalRounds(0)  {}
		void initialize() {
			char something = 0;
			while(static_cast<int>(something) < 64) {
				mainDeck.push_back(Card(something));
				something = static_cast<char>(something + 1);
			}
		}
		void deal() {
			std::random_device rng;
  		std::minstd_rand prng(rng());
  		std::shuffle(mainDeck.begin(), mainDeck.end(), prng);
			for (auto i = dealPile.begin(); i != dealPile.end(); ++i) {
    		if ((i - dealPile.begin()) % 2 == 0) {
      		player1Deck.push_back(*i);
				} else {
      		player2Deck.push_back(*i);
				}
			}
		}
		void draw(int cardsToDraw) {
			int drawAmount = 1;
  		if (player1Deck.size() < cardsToDraw || player2Deck.size() < cardsToDraw) {
    		drawAmount = (player1Deck.size() < player2Deck.size()) ? player1Deck.size() : player2Deck.size();
			} else {
    		drawAmount = cardsToDraw;
			}

  		for (int i = 0; i < drawAmount; ++i) {
    		player1PlacePile.push_back(player1Deck[player1Deck.size() - 1]);
    		player1Deck.pop_back();
    		player2PlacePile.push_back(player2Deck[player2Deck.size() - 1]);
    		player2Deck.pop_back();
  		}
		}
		void gather(std::deque<Card>& winner) {
			for (int i = 0; i < player1PlacePile.size(); ++i) {
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
		
		void start() {
			if(mainDeck.empty()) { initialize() } // if the deck wasn't initialized, init
			while ((player1Deck.size() > 0 && player2.size() > 0) && totalRounds < MAX_ROUNDS) {
				draw(); // draw the cards
				if(player1PlacePile.at(player1PlacePile.size() - 1).getRank() < player2PlacePile.at(player2PlacePile.size() - 1).getRank()) {
					gather(player1Deck);
					++player1Wins;
				else if(player1PlacePile.at(player1PlacePile.size() - 1).getRank() > player2PlacePile.at(player2PlacePile.size() - 1).getRank()) {
					gather(player2Deck);
					++player2Wins;
				}
				else {
					do {
						++totalWars;
							
