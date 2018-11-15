#include<cstdlib>
#include<time.h>
#include "Card.h"

using namespace std;

Card::Card(void) {
	suit  = rand()%3;
	value = rand()%13 + 1;
	return;
}

Card::Card(int suit, int value) {
	suit  = suit;
	value = value;
	return;
}

int Card::getValue(void) {
	return value;
}

int Card::getSuit(void) {
	return suit;
}

string Card::toString(void) const {
	return getValueAsString() + " of " + getSuitAsString();
}

string Card::getSuitAsString(void) const {
	return(
		suit == CLUBS    ? "Clubs" :
		suit == DIAMONDS ? "Diamonds" :
		suit == HEARTS   ? "Hearts" :
		suit == SPADES   ? "Spades" :
		"Unknown suit"
	);
}

string Card::getValueAsString(void) const {
	return(
		value == ACE   ? "Ace" :
		value == JACK  ? "Jack" :
		value == QUEEN ? "Queen" :
		value == KING  ? "King" :
		std::to_string(value)
	);
}

bool Card::sameSuit(Card& other) {
	return other.getSuit() == suit;
}

bool Card::sameValue(Card& other) {
	return other.getValue() == value;
}

bool operator==(Card& c1, Card& c2) {
	return c1.getValue() == c2.getValue();
}

ostream& operator<<(ostream& output, const Card& c) {
	output << c.toString();
	return output;
}