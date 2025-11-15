/* Program name: bag.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Implement the Bag class methods declared in bag.h.
 */

#include "bag.h"
#include <iostream>
#include <limits>
using namespace std;

Bag::Bag(int capacity) {
    this->capacity = capacity;
    size = 0;
    candies = new candy*[capacity]; // Dynamic array of candy pointers
}

Bag::~Bag() {
    for (int i = 0; i < size; i++) {
        delete candies[i]; // Delete each candy
    }
    delete[] candies; // Delete the array of pointers
}

Bag::Bag(const Bag& other) {
    capacity = other.capacity;
    size = other.size;
    candies = new candy*[capacity];
    for (int i = 0; i < size; i++) {
        candies[i] = new candy(*other.candies[i]);
    }
}

Bag& Bag::operator=(const Bag& other) {
    if (this != &other) {
        // Clean up existing candies
        for (int i = 0; i < size; i++) {
            delete candies[i];
        }
        delete[] candies;

        // Copy new data
        capacity = other.capacity;
        size = other.size;
        candies = new candy*[capacity];
        for (int i = 0; i < size; i++) {
            candies[i] = new candy(*other.candies[i]);
        }
    }
    return *this;
}

void Bag::copyBag(const Bag& other) {
    // Delete old candies
    for (int i = 0; i < size; i++) {
        delete candies[i];
    }
    delete[] candies;

    // Allocate new array
    capacity = other.capacity;
    size = other.size;
    candies = new candy*[capacity];

    for (int i = 0; i < size; i++) {
        candies[i] = new candy(*other.candies[i]);
    }
}

bool Bag::duplicateCheck(candy* newCandy) const {
    for (int i = 0; i < size; i++) {
        if (candies[i]->getFlavor() == newCandy->getFlavor() &&
            candies[i]->getColor() == newCandy->getColor()) {
            return true;
        }
    }
    return false;
}

void Bag::fillBag() {
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

        // Flavor menu
        cout << "Choose a flavor you would like:\n"
             << "[1] Cotton Candy\n[2] Watermelon Burst\n[3] Papaya Bliss\n[4] Citrus Splash\n[5] Cola\n";

        do {
            cin >> flavorChoice;
            if (cin.fail() || flavorChoice < 1 || flavorChoice > 5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter 1-5: ";
            }
        } while (flavorChoice < 1 || flavorChoice > 5);

        // Color menu
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

            // Show current order
            cout << "\nYour order:\n";
            displayBag();
        }
    }
}

void Bag::displayBag() const {
    for (int i = 0; i < size; i++) {
        cout << "#" << (i + 1) << ": " << candies[i]->colorToString()
             << " " << candies[i]->flavorToString() << "\n";
    }
}