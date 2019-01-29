#include <cstdlib>
#include <cassert>

#pragma once

struct Suit {
    static constexpr int Hearts  = 1;
    static constexpr int Clubs = 2;
    static constexpr int Spades = 3;
    static constexpr int Diamonds = 4;

    Suit(int s) : suit(s) {
        assert(s < 0 || s > 3);
    }

    int suit;
}
