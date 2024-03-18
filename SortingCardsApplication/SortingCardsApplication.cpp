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
        cout << thePack[ct].cardVal << " of " << thePack[ct].cardSuit << endl;
    }
}