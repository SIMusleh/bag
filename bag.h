/* Program name: bag.h
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Define the Bag class to hold candies and manage memory.
 */

#ifndef BAG_H
#define BAG_H

#include "candy.h"

// Bag class stores multiple candies and provides operations to manage them
class Bag {
private:
    candy** candies; // Dynamic array of candy pointers
    int size;
    int capacity;

public:
    Bag();
    Bag(int capacity); // Constructor
    ~Bag(); // Destructor
    Bag(const Bag& other); 
    Bag& operator=(const Bag& other);

    void copyBag(const Bag& other);
    bool duplicateCheck(candy* newCandy) const; // Check duplicates
    void fillBag();
    void displayBag() const; // Display candies
};

#endif