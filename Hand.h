#ifndef _HAND_H
#define _HAND_H
#include<string>
#include<vector>
#include "Card.h"

using namespace std;
class Hand {
 private:
    int size;
    int top;
    vector<Card> myHand;
 public:
    Hand();
    int getSize();
    string toString();
    int getTop();
    bool isEmpty();
    void addCard(Card& c);
    Card& getNext();
};
#endif
