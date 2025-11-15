/* Program name: bag.h
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Define the Bag class to hold candies and manage memory.
 */

 #ifndef BAG_H
 #define BAG_H

 #include "candy.h"
 #include <string>

 class Bag {
 private:
    candy** candies; // Dynamic array of candy pointers
    int size;
    int capacity;

 public:
    Bag(int capacity); // Constructor
    Bag(const Bag& other);
    ~Bag(); // Destructor

    void fillBag();
    void copyBag(const Bag& other);
    bool duplicatecheck(candy* newCandy) const; // Check duplicates
    void displayBag() const; // Display candies
 };
 
 #endif