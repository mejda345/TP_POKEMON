#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"

class TrainerCard : public Card {
private:
    std::string trainerEffect;

public:
    TrainerCard(const std::string& name, const std::string& effect)
        : Card(name), trainerEffect(effect) {}

    void displayInfo() const override;
    void applyEffect();
};

#endif 
