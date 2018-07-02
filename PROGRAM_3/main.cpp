#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
// #include <ofstream>
#include "Deck.h"
#include "Card.h"

using namespace std;

bool hasPair(const vector<Card> &v) {
    for (unsigned i = 0; i < v.size(); ++i) {
        for (unsigned j = 0; j < v.size(); ++j) {
            if (j != i) {
                Card c1 = v.at(i);
                Card c2 = v.at(j);
                if (c1.getRank() == c2.getRank()) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

ostream & operator<<(ostream &fout, const vector<Card> &v) {
    for (unsigned i = 0; i < v.size() - 1; ++i) {
        Card c1 = v.at(i);
        fout << c1 << " ";
    }
    
    Card last = v.back();
    fout << last << endl;
    
    return fout;
}


int main() {
    string ans;
    Deck d;
    vector <Card> v;
    ofstream outFile;
    int hand = 0;
    int deals = 0;
    int pairs = 0;
    double chance = 0.0;
    
    srand(2222);
    
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> ans;
    
    cout << "\n\n";
    
    if (ans == "Yes") {
        string file;
        cout << "Enter name of output file: ";
        cin >> file;
        
        cout << "\n\n";
        
        outFile.open(file.c_str());
        
        if(!outFile.is_open()) {
            cout << "Error opening " << file << endl;
            exit(1);
        }
    }
    
    cout << "Enter number of cards per hand: ";
    cin >> hand;
    
    v.resize(hand);
    
    cout << "\n\n";
    cout << "Enter number of deals (simulations): ";
    cin >> deals;
    
    for (int i = 0; i < deals; ++i) {
        for (unsigned j = 0; j < v.size(); ++j) {
            v.at(j) = d.dealCard();
        }
        
        if (hasPair(v)) {
            pairs += 1;
            if (ans == "Yes") {
                outFile << "Found pair!! ";
                outFile << v;
            }
        }
        else if (ans == "Yes") {
            outFile << v;
        }
        
        v.clear();
        v.resize(hand);
        d.shuffleDeck();
    }
    
    if (ans == "Yes") {
        outFile.close();   
    }

    chance = (pairs / static_cast<double>(deals)) * 100;
    
    cout << "\n\n";
    cout << "Chances of receiving a pair in a hand of " << hand << " cards is: " << chance << "%." << endl;
    
    return 0;
}