#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"

class EnergyCard : public Card {
private:
    std::string energyType;

public:
    EnergyCard(const std::string& type) : Card("Energy"), energyType(type) {}
    void displayInfo() const override;
};

#endif
