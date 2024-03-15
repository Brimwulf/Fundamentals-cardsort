// RJM's file for getting a random card
// 6/2/24
// Adapted by Hayden Scott, 32024813

#include "cardlib.h"
using namespace std;

string cardToStr(aCard c) {
    return "";
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