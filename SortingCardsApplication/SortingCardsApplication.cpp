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
    for (int ct = 0; ct < maxCard; ct++) {   // This for loop generates the pack of cards from 0 to maxCard thus generating maxCard number of cards.
        thePack[ct] = getCard("32025027");   // change to your student number
        cout << valueToStr(thePack[ct]) << " of " << suitToStr(thePack[ct]) << endl;    // This part prints out the value and suit of the pack.
    }

    int comparisons, moves;
    bubbleSort(thePack, maxCard, comparisons, moves);   // Performing a bubble sort on the pack, taking maxCard as the size of the pack and changing comparisons and moves through the function.
    cout << "\nSorted by bubble sort:\n" << endl;
    for (int ct = 0; ct < maxCard; ct++) {
        cout << valueToStr(thePack[ct]) << " of " << suitToStr(thePack[ct]) << endl;
    }
    cout << "Comparisons made: " << comparisons << " moves taken: " << moves << "\n" << endl;

    int quickComparisons = 0;
    int quickMoves = 0;
    int recurDep = 0;
    quickSort(thePack, 0, maxCard, quickComparisons, quickMoves, recurDep);   // This function takes the pack, the lower limit which is 0 i.e. the start of the pack and the max as the higher bound.
    cout << "Quicksort:\n" << endl;
    for (int ct = 0; ct < maxCard; ct++) {
        cout << valueToStr(thePack[ct]) << " of " << suitToStr(thePack[ct]) << endl;
    }
    cout << "Comparisons made: " << quickComparisons << " moves taken: " << quickMoves << endl;
    cout << "Max recursion depth: " << recurDep-1 << endl;      // -1 on recurDep to omit the initial call of the function.
}

// Note to self: Remember that aCard is already represented as a value + a suit. The above output streams handle suits and values seperately.