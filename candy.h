/* Program name: candy.h
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Define the Candy class and enums for flavor and color.
 */
 
#ifndef CANDY_H
#define CANDY_H

#include <string>

enum flavorType {
    COTTON_CANDY,
    WATERMELON_BURST,
    PAPAYA_BLISS,
    CITRUS_SPLASH,
    COLA
};

enum colorType {
    SCARLET_BLAZE,
    AZURE_SKY,
    EMERALD_MIST,
    GOLDENROD_GLOW,
    AMETHYST_HAZE
};

class candy {
private:
    flavorType flavor;
    colorType color;

public:
    candy(flavorType f, colorType c);
    flavorType getFlavor() const;
    colorType getColor() const;
    void setFlavor(flavorType f);
    void setColor(colorType c);
    std::string flavorToString() const;
    std::string colorToString() const;
};

#endif