// RJM's file for getting a random card
// 6/2/24
// Adapted by Hayden Scott, 32024813

#include <iostream>
#include "cardlib.h"
using namespace std;

string suitToStr(aCard c) {     // function for converting the suit of aCard to a string
    string suit_output;     // defining a string variable for the output.
    
    switch (c.cardSuit) {       // We want switch cases for each value of the enum for suits.
    case clubs: suit_output = "clubs"; break;       // Sets a str variable based on the value of the enum.
    case diamonds: suit_output = "diamonds"; break;
    case hearts: suit_output = "hearts"; break;
    case spades: suit_output = "spades"; break;
    }
    
    return suit_output;     // Returns the string.
}

string valueToStr(aCard c) {    // This function works similarly to above except for the value of the card.
    string value_output;        // Variable for string output.
    switch (c.cardVal) {        // Switch cases for the value of the card. If 1, 11, 12, 13 the string becomes ace, jack, queen or king respectively.
    case 1: value_output = "Ace"; break;
    case 11: value_output = "Jack"; break;
    case 12: value_output = "Queen"; break;
    case 13: value_output = "King"; break;
    default: value_output = std::to_string(c.cardVal);  // We also want a default case to return just the value of the card if not 1,11,12 or 13.
    }

    return value_output;    // returns the output string.
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
    bool swapMade;      // Declaring a boolean variable which will be used to check if a swap was made.
    moves = 0;
    comparisons = 0;    // Initialising variables for the number of moves and comparisons taken.
    for (int i = 0; i < size - 1; i++) {        // iterating through the size of the pack - 1 because i starts from 0.
        swapMade = false;                       // Set swapMade back to false for each iteration.
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;                      // Incrementing comparisons here since a comparison is made below.
            if (pack[j].cardVal > pack[j + 1].cardVal) {        // If the value of the card we're on is greater than the next card in the pack:
                aCard temp = pack[j];                           // Setting a temporary variable so we can make the swap.
                pack[j] = pack[j + 1];                          // Setting the current card to be the same as the next one.
                pack[j + 1] = temp;                             // Setting the next card to be the same as the current card.
                swapMade = true;                                // Setting swapMade to true to verify that we have swapped a card aroud.
                moves++;                                        // And finally incrementing the move counter.
            }
        }
        // if swapMade remains false after the iteration of the loop this means no swap took place we want the loop to break
        if (swapMade == false) break;
    }
}

int partitioner(aCard pack[], int lower, int higher, int& quickComparisons, int& quickMoves) {
    aCard pivot = pack[(higher+lower)/2];     // selecting the pivot as the midpoint between the higher and lower value.
    int i = lower;                            // creating a variable i which is equal to the lower end of the array passed in
    int j = higher - 1;                       // Same for the higher end but - 1 because the array is indexed from 0 to n.

    while (i <= j) {                          // Keep looping through the array until i is greater than j
        while (i <= j && pack[i].cardVal < pivot.cardVal) {     
            i++;
            quickComparisons++;
        }
        while (i <= j && pack[j].cardVal > pivot.cardVal) {
            j--;
            quickComparisons++;
        }       // Both of the above while loops are responsible for moving i and j closer to one another until it finds a value less than or equal to the pivot.
        if (i <= j) {
            swap(pack[i], pack[j]);
            i++;
            j--;
            quickMoves++;
        }       // This if statement is responsible for swapping values if i is less than j i.e. if the lower variable is less than the higher.
    }
    
    return i;       // returns i which is used as the index for the partitioner which the quickSort function will use.
}

void quickSort(aCard pack[], int lower, int higher, int& quickComparisons, int& quickMoves, int& recurDep) {   // Function takes the parameters, the pack as an array and the higher and lower bounds.
    if (lower < higher) {       // checking if the lower index is less than higher which checks if there are elements of the array yet to be sorted.
        int partitionIndex = partitioner(pack, lower, higher, quickComparisons, quickMoves);    // partitioning the array and using the return value as the partitionIndex variable.
        quickSort(pack, lower, partitionIndex - 1, quickComparisons, quickMoves, recurDep);
        quickSort(pack, partitionIndex + 1, higher, quickComparisons, quickMoves, recurDep);      // Recursively quickSorting both the higher and lower partitions of the array.
        recurDep++;     // Increasing the recursion counter each time this function is called.
    }
}