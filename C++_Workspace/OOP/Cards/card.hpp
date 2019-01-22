#pragma once
#ifndef CARD_HPP
#define CARD_HPP

private:
enum Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

enum Rank {
    A,
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
    King
};

public:
struct Card {
    Suit suit;
    Rank rank;
}

