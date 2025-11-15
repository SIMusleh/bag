/* Program name: candy.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Implement the Candy class methods declared in candy.h.
 */

#include "candy.h"
#include <string>
// Constructor: initializes flavor and color
candy::candy(flavorType f, colorType c) {
    flavor = f;
    color = c;
}
// Getter for flavor
flavorType candy::getFlavor() const { return flavor; }
// Getter for color
colorType candy::getColor() const { return color; }
// Setter for flavor
void candy::setFlavor(flavorType f) { flavor = f; }
// Setter for color
void candy::setColor(colorType c) { color = c; }
// Convert flavor enum to string
std::string candy::flavorToString() const {
    switch (flavor) {
        case COTTON_CANDY: return "Cotton Candy";
        case WATERMELON_BURST: return "Watermelon Burst";
        case PAPAYA_BLISS: return "Papaya Bliss";
        case CITRUS_SPLASH: return "Citrus Splash";
        case COLA: return "Cola";
    }
    return "";
}
// Convert color enum to string
std::string candy::colorToString() const {
    switch (color) {
        case SCARLET_BLAZE: return "Scarlet Blaze";
        case AZURE_SKY: return "Azure Sky";
        case EMERALD_MIST: return "Emerald Mist";
        case GOLDENROD_GLOW: return "Goldenrod Glow";
        case AMETHYST_HAZE: return "Amethyst Haze";
    }
    return "";
}