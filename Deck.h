#ifndef _DECK_H
#define _DECK_H

#include<string>
#include<vector>
#include "Card.h"

int const SHUFFLE = 5000; 

using namespace std;

class Deck {
 private:
    vector<Card> myDeck;
    int top;
    int deckSize;
 public:
    Deck();
    void shuffle();
    Card& dealCard();
    int getTop();
    int getDeckSize();
    string toString();
};

#endif

