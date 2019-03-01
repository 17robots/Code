#ifndef CARD2_HPP
#define CARD2_HPP

enum Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

enum Rank {
    Two,
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
    Ace,
    Joker
};

enum Color {
    Black,
    Red
};

enum Kind {
    Standard,
    Joker
};

class PlayingCard {
    private:
        Kind kind;
        Rank rank;
        Suit suit;
        Color color;
    public:
        PlayingCard();
        PlayingCard(char identifier);
        Suit getSuit();
        Rank getRank();
        Color getColor();
        Kind getKind();
        std::ostream& operator << (std::ostream& os, PlayingCard& c);
};

#endif