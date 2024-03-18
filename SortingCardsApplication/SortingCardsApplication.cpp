// SortingCardsApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.

// RJM 6/2/24
// Adapted by Hayden Scott, 32024813

#include <string>
#include <iostream>
#include "cardlib.h"
using namespace std;

const int maxCard = 20;

aCard thePack[maxCard];


int main() {
    cout << "Card Sorting!\n";

    for (int ct = 0; ct < maxCard; ct++) {
        thePack[ct] = getCard("32024813");   // change to your student number
        //cout << thePack[ct].cardVal << " of " << thePack[ct].cardSuit << endl;
        if (thePack[ct].cardVal == 1) cout << "Ace";
        else if (thePack[ct].cardVal == 11) cout << "Jack";
        else if (thePack[ct].cardVal == 12) cout << "Queen";
        else if (thePack[ct].cardVal == 11) cout << "King";
        else cout << thePack[ct].cardVal;
        cout << " of " << thePack[ct].cardSuit << endl;
    }
}