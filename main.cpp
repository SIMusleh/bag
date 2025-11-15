/* Program name: main.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Allow the user to create multiple bags of candy using Bag and Candy classes.
 */

#include <iostream>
#include <limits>
#include "bag.h"
using namespace std;

int main() {
    cout << "=========================================================================================\n";
    cout << "                              Welcome to The Cavity Factory!\n";
    cout << "=========================================================================================\n\n";
    cout << "- We allow our beloved Candy Connoisseurs (yes, that'd be you) to build their own candy!\n";
    cout << "There's only one catch: To ensure that our customers explore their palate,\n";
    cout << "we only allow unique candy to be ordered in each bag. Don't think of it as a limitation, but as an EXPERIENCE!\n\n";

    int numBags;
    cout << "How many bags of candy will you be ordering today? ";
    do {
        cin >> numBags;
        if (cin.fail() || numBags < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
        }
    } while (numBags < 1);
    
    Bag* bags = new Bag[numBags];

    int filled = 0;
    while (filled < numBags) {
        cout << "\nBag #" << (filled + 1) << " of " << numBags << "\n";
        bags[filled].fillBag();

        cout << "\nHow many more bags like the last one would you like? ";
        int copies;
        do {
            cin >> copies;
            if (cin.fail() || copies < 0 || copies > (numBags - filled - 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a number between 0 and " << (numBags - filled - 1) << ": ";
            }
        } while (copies < 0 || copies > (numBags - filled - 1));

        for (int i = 0; i < copies; i++) {
            bags[filled + i + 1].copyBag(bags[filled]);
        }
        filled += (copies + 1);
    }
    
    // Display all bags
    cout << "\nYour order:\n";
    for (int i = 0; i < numBags; i++) {
        cout << "\nBag #" << (i + 1) << "\n";
        bags[i].displayBag();
    }

    cout << "\nThank you for choosing The Cavity Factory, where tooth decay is our priority!\n";

    delete[] bags;
    return 0;
}