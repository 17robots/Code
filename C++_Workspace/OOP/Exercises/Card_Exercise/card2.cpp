#include "card2.hpp"

PlayingCard::PlayingCard() {}

PlayingCard::PlayingCard(char identifier) : rank(static_cast<Rank>(identifier & 0xf)) {
    kind = static_cast<Kind>((identifier >> 128) & 0x1);
    switch(kind) {
        case Standard: {
            suit = static_cast<Suit>((identifier >> 4) & 0x3);
            color = (suit == Diamonds || suit == Hearts ? Red : Black);
            break;
        }
        
        case Joker: {
            suit = Joker;
            color = (((identifier >> 4) & 0x3) == 2 || ((identifier >> 4) & 0x3) == 3 ? Red : Black);
            break;
        }
    }
    
    // suit = (kind == Joker ? Joker : static_cast<Suit>((identifier >> 4) & 0x3));
    // color = (kind == Joker ? color = (((identifier >> 4) & 0x3) == 2 || ((identifier >> 4) & 0x3) == 3 ? Red : Black) : (suit == Diamonds || suit == Hearts ? Red : Black));
}

PlayingCard::Suit getSuit() { return suit; }

Rank PlayingCard::getRank() { return rank; }

Color PlayingCard::getColor() { return color; }

Kind PlayingCard::getKind() { return kind; }

std::ostream& PlayingCard::operator << (std::ostream& os, PlayingCard& c) {
    std::string returnString = "";
    
    if(c.getKind() == Joker) {
        
    } else {
        switch(c.getRank()) {
            case Two:
                returnString += "2 of ";
                break;
            case Three:
                returnString += "3 of ";
                break;
            case Four:
                returnString += "4 of ";
                break;
            case Five:
                returnString += "5 of ";
                break;
            case Six:
                returnString += "6 of ";
                break;
            case Seven:
                returnString += "7 of ";
                break;
            case Eight:
                returnString += "8 of ";
                break;
            case Nine:
                returnString += "9 of ";
                break;
            case Ten:
                returnString += "10 of ";
                break;
            case Jack:
                returnString += "Jack of ";
                break;
            case Queen:
                returnString += "Queen of ";
                break;
            case King:
                returnString += "King of ";
                break;
            case Ace:
                returnString += "Ace of ";
                break;
            case Joker:
                switch(c.getColor()) {
                    case Red:
                        returnString += "Red Joker";
                        break;
                    case Black:
                        returnString += "Black Joker";
                        break;
                }
                break;
        }
        
        switch(c.getSuit()) {
            case Clubs:
                returnString += "Clubs";
                break;
            case Diamonds:
                returnString += "Diamonds";
                break;
            case Hearta:
                returnString += "Hearts";
                break;
            case Spades:
                returnString += "Spades";
                break;
            default:
                break; // used for joker
        }
    }
    
    return os << returnString << '\n';
}