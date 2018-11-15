#include<cstdlib>
#include<time.h>

#include "Deck.h"

Deck::Deck(void) {
	top = 0;

	for (int suit=CLUBS; suit <= SPADES; ++suit) {
		for (int val=ACE; val <= KING; ++val) {
			myDeck.push_back(Card(suit, val));
		}
	}
}

void Deck::shuffle(void) {
	for (int i=0; i < SHUFFLE; ++i) {
		int card0 = rand() % 51;
		int card1 = rand() % 51;

		Card tmp = myDeck.at(card0);
		myDeck.at(card0) = myDeck.at(card1);
		myDeck.at(card1) = tmp;
	}

	return void();
}

Card& Deck::dealCard(void) {
	--deckSize;
	return myDeck[top++];
}

int Deck::getTop(void) {
	return top;
}

int Deck::getDeckSize(void) {
	return deckSize;
}

string Deck::toString(void) {
	string str = "";

	for (int i=top; i < deckSize; ++i) {
		str += i == deckSize - 1 ? myDeck[i].toString() + "\n" :
															 myDeck[i].toString();
	}

	return str;
}