// #ifndef CARD_H
// #define CARD_H
#include <string>
#include <vector>
#include <ostream>
#include "Deck.h"
using namespace std;

#include "Card.h"

Card::Card() {
    suit = 'c';
    rank = 2;
}

Card::Card(char soot, int wrank) {
    suit = tolower(soot);
    rank = wrank;
}

char Card::getSuit() const {
    return tolower(suit);
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream &out, const Card &rhs) {
    string name;
    switch(rhs.getSuit()) {
        case 'C':
        case 'c':
        name = "Clubs";
        break;
        case 'D':
        case 'd':
        name = "Diamonds";
        break;
        case 'H':
        case 'h':
        name = "Hearts";
        break;
        case 'S':
        case 's':
        name = "Spades";
        break;
    }
    if(rhs.rank == 1 || rhs.rank >= 11) {
    string rankToName;
    switch(rhs.getRank()) {
        case 1:
        rankToName = "Ace";
        break;
        case 11:
        rankToName = "Jack";
        break;
        case 12:
        rankToName = "Queen";
        break;
        case 13:
        rankToName = "King";
        break;
    } 
    out << rankToName << " of " << name;
    } else {
    out << rhs.getRank() << " of " << name;
    }
    return out;
}