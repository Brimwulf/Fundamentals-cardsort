// header file for cardlib
// RJM 06/01/24
// Adapted by Hayden Scott, 32024813

#include <string>

enum Suit { hearts, clubs, diamonds, spades };      // define suits

struct aCard {                          // defines a card
    int cardVal;                        // number 1..13
    Suit cardSuit;                      // suit
};

std::string suitToStr(aCard c);			// declare function to represent a card as a two character string
std::string valueToStr(aCard c);

aCard getCard(std::string studentNumber);        // declares function to get a card from stdno string

void bubbleSort(aCard pack[], int size, int& comparisons, int& moves);

int partitioner(aCard pack[], int higher, int lower, int& quickComparisons, int& quickMoves);
void quickSort(aCard pack[], int higher, int lower, int& quickComparisons, int& quickMoves);
