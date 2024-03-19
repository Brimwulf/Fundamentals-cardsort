// SortingCardsApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.

// RJM 6/2/24
// Adapted by Hayden Scott, 32024813

#include <string>
#include <iostream>
#include "cardlib.h"
using namespace std;

const int maxCard = 20;

aCard thePack[maxCard];
// thePack is an array of aCards with an array size: maxCard.

int main() {
    cout << "Card Sorting!\n" << endl;

    cout << "Pack before:" << endl;
    for (int ct = 0; ct < maxCard; ct++) {
        thePack[ct] = getCard("32024813");   // change to your student number
        cout << thePack[ct].cardVal << " of " << cardToStr(thePack[ct]) << endl;
    }

    int comparisons, moves;
    bubbleSort(thePack, maxCard, comparisons, moves);
    cout << "\nSorted by bubble sort:\n" << endl;
    for (int ct = 0; ct < maxCard; ct++) {
        cout << thePack[ct].cardVal << " of " << cardToStr(thePack[ct]) << endl;
    }
    cout << "Comparisons made: " << comparisons << " moves taken: " << moves << endl;
}

// Remember that aCard is already represented as a number + another number. The above logic only represents it so that it can be printed out
// The same method of representing should later be moved to the card to string function