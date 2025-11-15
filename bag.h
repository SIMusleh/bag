/* Program name: bag.h
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Define the bag class to hold candies and manage memory.
 */

#ifndef BAG_H
#define BAG_H

#include "candy.h"

// bag class stores multiple candies and provides operations to manage them
class bag {
private:
    candy** candies; // Dynamic array of candy pointers
    int size;
    int capacity;

public:
    bag();                     // Default constructor
    bag(int capacity);         // Parameterized constructor
    ~bag();                    // Destructor
    bag(const bag& other);     // Copy constructor
    bag& operator=(const bag& other); // Assignment operator

    void copyBag(const bag& other);
    bool duplicateCheck(candy* newCandy) const; // Check duplicates
    void fillBag();
    void displayBag() const; // Display candies
};

#endif