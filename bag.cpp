/* Program name: bag.cpp
 * Author: Sahar Musleh
 * Date last updated: 12/02/2025
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

// Corrected fillBag()
void bag::fillBag() {
    cout << "How many candies will you be ordering today? (range: 1-" << capacity << ")\n";
    int numCandies;
    do {
        cin >> numCandies;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's not a number.\n";
            cout << "Invalid entry. Number must be between 1 and " << capacity << " inclusive. Try again.\n";
        } else if (numCandies < 1 || numCandies > capacity) {
            cout << "Invalid entry. Number must be between 1 and " << capacity << " inclusive. Try again.\n";
        }
    } while (numCandies < 1 || numCandies > capacity);

    for (int i = 0; i < numCandies; i++) {
        cout << "\nCandy #" << (i + 1) << " of " << numCandies << "\n";

        int flavorChoice, colorChoice;

        cout << "Choose a flavor you would like:\n"
             << "[1] Cotton Candy\n[2] Watermelon Burst\n[3] Papaya Bliss\n[4] Citrus Splash\n[5] Cola\n";
        do {
            cin >> flavorChoice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "That's not a number.\n";
                cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again.\n";
            } else if (flavorChoice < 1 || flavorChoice > 5) {
                cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again.\n";
            }
        } while (flavorChoice < 1 || flavorChoice > 5);

        // Create a temporary candy object for display
        candy tempCandy(static_cast<flavorType>(flavorChoice - 1), SCARLET_BLAZE);
        cout << tempCandy.flavorToString() << "? Great choice.\n";

        cout << "\nChoose a color for your " 
             << tempCandy.flavorToString() << " candy:\n"
             << "[1] Scarlet Blaze\n[2] Azure Sky\n[3] Emerald Mist\n[4] Goldenrod Glow\n[5] Amethyst Haze\n";
        do {
            cin >> colorChoice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "That's not a number.\n";
                cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again.\n";
            } else if (colorChoice < 1 || colorChoice > 5) {
                cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again.\n";
            }
        } while (colorChoice < 1 || colorChoice > 5);

        candy* newCandy = new candy(static_cast<flavorType>(flavorChoice - 1),
                                    static_cast<colorType>(colorChoice - 1));

        candy confirmCandy(static_cast<flavorType>(flavorChoice - 1),
                           static_cast<colorType>(colorChoice - 1));
        cout << confirmCandy.colorToString() << " "
             << confirmCandy.flavorToString() << " it is!\n";

        if (duplicateCheck(newCandy)) {
            cout << "But wait, this is not unique, try again.\n";
            delete newCandy;
            i--;
        } else {
            candies[size++] = newCandy;
            cout << "Marvelous! Your candy was added to the order.\n\n";

            // Show current order with proper formatting
            cout << "\nYour order:\n"; // newline before and after
            for (int j = 0; j < size; j++) {
                cout << "#" << (j + 1) << " " << candies[j]->colorToString()
                     << " " << candies[j]->flavorToString() << "\n";
            }
        }
    }
}

// Corrected displayBag()
void bag::displayBag() const {
    for (int i = 0; i < size; i++) {
        cout << "#" << (i + 1) << " " << candies[i]->colorToString()
             << " " << candies[i]->flavorToString() << "\n";
    }
}

// Added Missing Methods

// Fixed overload for duplicateCheck (search entire bag for a match)
bool bag::duplicateCheck(int index, const candy& newCandy) const {
    // Ignore index, search entire bag for a match
    for (int i = 0; i < size; i++) {
        if (candies[i]->getFlavor() == newCandy.getFlavor() &&
            candies[i]->getColor() == newCandy.getColor()) {
            return true;
        }
    }
    return false;
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