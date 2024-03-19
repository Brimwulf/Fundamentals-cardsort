// RJM's file for getting a random card
// 6/2/24
// Adapted by Hayden Scott, 32024813

#include <iostream>
#include "cardlib.h"
using namespace std;

string cardToStr(aCard c) {
    string output;
    switch (c.cardSuit) {
    case clubs: output = "clubs"; break;
    case diamonds: output = "diamonds"; break;
    case hearts: output = "hearts"; break;
    case spades: output = "spades"; break;
    }
    return output;
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
        comparisons++;
        for (int j = 0; j < size - i - 1; j++) {
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