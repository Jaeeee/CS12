#include "Deck.h"
// #include "Card.h"

// #ifndef DECK_H
// #define DECK_H
#include <string>
#include <vector>
#include <algorithm>
#include "Card.h"
using namespace std;
// using namespace std;

Deck::Deck() {
    for (int i = 13; i > 0; --i) {
        Card newcard = Card('s', i);
        theDeck.push_back(newcard);
    }
    for (int i = 13; i > 0; --i) {
        Card newcard = Card('h', i);
        theDeck.push_back(newcard);
    }
    for (int i = 13; i > 0; --i) {
        Card newcard = Card('d', i);
        theDeck.push_back(newcard);
    }
    for (int i = 13; i > 0; --i) {
        Card newcard = Card('c', i);
        theDeck.push_back(newcard);
    }
}

Card Deck::dealCard() {
    Card deal = theDeck.back();
    theDeck.pop_back();
    dealtCards.push_back(deal);
    
    return deal;
}

void Deck::shuffleDeck() {
    for (unsigned i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i));
    }
    
    random_shuffle(theDeck.begin(), theDeck.end());
    
    dealtCards.clear();
}

unsigned Deck::deckSize() const {
    unsigned size = theDeck.size();
    
    return size;
}