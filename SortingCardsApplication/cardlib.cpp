// RJM's file for getting a random card
// 6/2/24
// Adapted by Hayden Scott, 32024813

#include <iostream>
#include "cardlib.h"
using namespace std;

string suitToStr(aCard c) {
    string suit_output;
    
    switch (c.cardSuit) {
    case clubs: suit_output = "clubs"; break;
    case diamonds: suit_output = "diamonds"; break;
    case hearts: suit_output = "hearts"; break;
    case spades: suit_output = "spades"; break;
    }
    
    return suit_output;
}

string valueToStr(aCard c) {
    string value_output;
    switch (c.cardVal) {
    case 1: value_output = "Ace"; break;
    case 11: value_output = "Jack"; break;
    case 12: value_output = "Queen"; break;
    case 13: value_output = "King"; break;
    default: value_output = std::to_string(c.cardVal);
    }

    return value_output;
}

aCard getCard(string studentNumber) { 
    // I'm changing "stdno" to studentNumber for my own benefit. I felt that the std confused me to often with "std::". Plus I prefer to name it that way.
    // function returns a card  - using student number stdno (8 numerical chars)
    aCard ans;
    string rcardstr = studentNumber.substr(rand() % 8, 1) + studentNumber.substr(rand() % 8, 1);    // two random characters from stdno
    int rcard = stoi(rcardstr) % 52;          // get integer in range 0..51
    string res = "  ";
    ans.cardVal = 1 + rcard % 13;                          // give cardVal 1..13 
    ans.cardSuit = static_cast<Suit>(rcard / 13);         // and for suit
    return ans;
}

void bubbleSort(aCard pack[], int size, int& moves, int& comparisons) {
    bool swapMade;
    moves = 0;
    comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        swapMade = false;
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (pack[j].cardVal > pack[j + 1].cardVal) {
                aCard temp = pack[j];
                pack[j] = pack[j + 1];
                pack[j + 1] = temp;
                swapMade = true;
                moves++;
            }
        }
        // if swapMade remains false after the iteration of the loop this means no swap took place we want the loop to break
        if (swapMade == false) break;
    }
}

int partitioner(aCard pack[], int lower, int higher, int& quickComparisons, int& quickMoves) {
    aCard pivot = pack[higher];
    int i = lower;
    int j = higher - 1;

    while (i <= j) {
        while (i <= j && pack[i].cardVal < pivot.cardVal) {
            i++;
            quickComparisons++;
        }
        while (i <= j && pack[j].cardVal > pivot.cardVal) {
            j--;
            quickComparisons++;
        }
        if (i <= j) {
            swap(pack[i], pack[j]);
            i++;
            j--;
            quickMoves++;
        }
    }
    if (i != higher) {
        swap(pack[i], pack[higher]);
        quickMoves++;
    }
    return i;
}

void quickSort(aCard pack[], int lower, int higher, int& quickComparisons, int& quickMoves) {
    if (lower < higher) {
        int partitionIndex = partitioner(pack, lower, higher, quickComparisons, quickMoves);
        quickSort(pack, lower, partitionIndex - 1, quickComparisons, quickMoves);
        quickSort(pack, partitionIndex + 1, higher, quickComparisons, quickMoves);
    }
}