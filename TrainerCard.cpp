#include "TrainerCard.h"

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << cardName
              << ", Effect: " << trainerEffect << "\n";
}

void TrainerCard::applyEffect() {
    std::cout << cardName << " is applying effect: " << trainerEffect << "\n";
}
