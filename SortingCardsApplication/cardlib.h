// header file for cardlib
// RJM 06/01/24
// Adapted by Hayden Scott, 32024813

#include <string>

enum Suit { hearts, clubs, diamonds, spades };      // define suits

struct aCard {                          // defines a card
    int cardVal;                        // number 1..13
    Suit cardSuit;                      // suit
};

std::string suitToStr(aCard c);			
std::string valueToStr(aCard c);        // These two functions take both parts of an aCard struct and represents the value and suit respectively.

aCard getCard(std::string studentNumber);        // declares function to get a card from stdno string.

void bubbleSort(aCard pack[], int size, int& comparisons, int& moves);         // declaring the function for the bubble sort.

int partitioner(aCard pack[], int higher, int lower, int& quickComparisons, int& quickMoves);
// This is a partitioner function and is necessary for quickSort which splits a pack into two about a pivot and then sorts the partitioned groups.

void quickSort(aCard pack[], int higher, int lower, int& quickComparisons, int& quickMoves);
// Here's the function for sorting the partitions.
