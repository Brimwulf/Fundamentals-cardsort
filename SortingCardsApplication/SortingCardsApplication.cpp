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
    cout << "Card Sorting!\n" << endl;

    for (int ct = 0; ct < maxCard; ct++) {
        thePack[ct] = getCard("32024813");   // change to your student number
        //cout << thePack[ct].cardVal << " of " << thePack[ct].cardSuit << endl;
        if (thePack[ct].cardVal == 1) cout << "Ace" << " of ";
        else if (thePack[ct].cardVal == 11) cout << "Jack" << " of ";
        else if (thePack[ct].cardVal == 12) cout << "Queen" << " of ";
        else if (thePack[ct].cardVal == 13) cout << "King" << " of ";
        else cout << thePack[ct].cardVal << " of ";
        if (thePack[ct].cardSuit == 0) cout << "clubs";
        else if (thePack[ct].cardSuit == 1) cout << "diamonds";
        else if (thePack[ct].cardSuit == 2) cout << "hearts";
        else if (thePack[ct].cardSuit == 3) cout << "spades";
        else cout << thePack[ct].cardSuit;
        cout << endl;
    }
}