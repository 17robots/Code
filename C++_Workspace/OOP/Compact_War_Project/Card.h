// make the char the holder of the card 
// bits: 00000000 - we only need 6 
// 2 bits for suit
// 4 for rank
// ignore the first 2 bits
//

struct Suit {}

struct Rank {}

class Card {
    private:
	Rank rank;
	Suit suit;
    public:
	
}
