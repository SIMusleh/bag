/* Program name: bag.cpp
 * Author: Sahar Musleh
 * Date last updated: 12/01/2025
 * Purpose: Implement the Bag class methods declared in bag.h.
 */

#include "bag.h"
#include <iostream>
#include <limits>
#include <sstream> // Added for getCandyList
using namespace std;

// Default constructor
bag::bag() {
    capacity = 25;
    size = 0;
    candies = new candy*[capacity];
}

// Parameterized constructor
bag::bag(int capacity) {
    this->capacity = capacity;
    size = 0;
    candies = new candy*[capacity]; // Dynamic array of candy pointers
}

// Destructor
bag::~bag() {
    for (int i = 0; i < size; i++) {
        delete candies[i]; // Delete each candy
    }
    delete[] candies; // Delete the array of pointers
}

// Copy constructor
bag::bag(const bag& other) {
    capacity = other.capacity;
    size = other.size;
    candies = new candy*[capacity];
    for (int i = 0; i < size; i++) {
        candies[i] = new candy(*other.candies[i]);
    }
}

// Assignment operator
bag& bag::operator=(const bag& other) {
    if (this != &other) {
        // Clean up existing candies
        for (int i = 0; i < size; i++) delete candies[i];
        delete[] candies;

        capacity = other.capacity;
        size = other.size;
        candies = new candy*[capacity];
        for (int i = 0; i < size; i++) {
            candies[i] = new candy(*other.candies[i]);
        }
    }
    return *this;
}

// Deep copy function
void bag::copyBag(const bag& other) {
    for (int i = 0; i < size; i++) delete candies[i];
    delete[] candies;

    capacity = other.capacity;
    size = other.size;
    candies = new candy*[capacity];
    for (int i = 0; i < size; i++) {
        candies[i] = new candy(*other.candies[i]);
    }
}

// Check for duplicates
bool bag::duplicateCheck(candy* newCandy) const {
    for (int i = 0; i < size; i++) {
        if (candies[i]->getFlavor() == newCandy->getFlavor() &&
            candies[i]->getColor() == newCandy->getColor()) {
            return true;
        }
    }
    return false;
}

// Fill bag with candies
void bag::fillBag() {
    cout << "How many candies will you be ordering today? (range: 1-" << capacity << "): ";
    int numCandies;
    do {
        cin >> numCandies;
        if (cin.fail() || numCandies < 1 || numCandies > capacity) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and " << capacity << ": ";
        }
    } while (numCandies < 1 || numCandies > capacity);

    for (int i = 0; i < numCandies; i++) {
        cout << "\nCandy #" << (i + 1) << " of " << numCandies << "\n";

        int flavorChoice, colorChoice;

        cout << "Choose a flavor:\n"
             << "[1] Cotton Candy\n[2] Watermelon Burst\n[3] Papaya Bliss\n[4] Citrus Splash\n[5] Cola\n";
        do {
            cin >> flavorChoice;
            if (cin.fail() || flavorChoice < 1 || flavorChoice > 5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter 1-5: ";
            }
        } while (flavorChoice < 1 || flavorChoice > 5);

        cout << "Choose a color:\n"
             << "[1] Scarlet Blaze\n[2] Azure Sky\n[3] Emerald Mist\n[4] Goldenrod Glow\n[5] Amethyst Haze\n";
        do {
            cin >> colorChoice;
            if (cin.fail() || colorChoice < 1 || colorChoice > 5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter 1-5: ";
            }
        } while (colorChoice < 1 || colorChoice > 5);

        candy* newCandy = new candy(static_cast<flavorType>(flavorChoice - 1),
                                    static_cast<colorType>(colorChoice - 1));

        if (duplicateCheck(newCandy)) {
            cout << "But wait, this is not unique, try again.\n";
            delete newCandy;
            i--;
        } else {
            candies[size++] = newCandy;
            cout << "Marvelous! Your candy was added to the order.\n";
        }
    }
}

// Display bag contents
void bag::displayBag() const {
    for (int i = 0; i < size; i++) {
        cout << "#" << (i + 1) << ": " << candies[i]->colorToString()
             << " " << candies[i]->flavorToString() << "\n";
    }
}

// Added Missing Methods

// Fixed overload for duplicateCheck (convert 1-based index to 0-based)
bool bag::duplicateCheck(int index, const candy& newCandy) const {
    int actualIndex = index - 1; // Adjust for 1-based index
    if (actualIndex < 0 || actualIndex >= size) return false;
    return (candies[actualIndex]->getFlavor() == newCandy.getFlavor() &&
            candies[actualIndex]->getColor() == newCandy.getColor());
}

// New method: getCandyList
std::string bag::getCandyList() const {
    std::ostringstream oss;
    for (int i = 0; i < size; i++) {
        oss << "#" << (i + 1) << " "
            << candies[i]->colorToString() << " "
            << candies[i]->flavorToString();
        if (i < size - 1) oss << "\n";
    }
    return oss.str();
}