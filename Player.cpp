#include "Player.h"
#include "EnergyCard.h"

Player::~Player() {
    for (auto card : benchCards) {
        delete card;
    }
    for (auto card : actionCards) {
        delete card;
    }
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        PokemonCard* card = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (card) {
            actionCards.push_back(card);
            benchCards.erase(benchCards.begin() + index);
        }
    }
}

void Player::attachEnergyCard(int benchIndex, int attackIndex) {
    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
    if (energy && !actionCards.empty()) {
        actionCards[0]->attachEnergy(attackIndex, 1);
        delete energy;
        benchCards.erase(benchCards.begin() + benchIndex);
    }
}

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << ":\n";
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << ":\n";
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int defenderIndex) {
    if (attackerIndex >= 0 && attackerIndex < actionCards.size()) {
        int damage = actionCards[attackerIndex]->attack(attackIndex);
        // Reduce opponent's PokemonCard HP, etc.
    }
}

void Player::useTrainer(int trainerIndex) {
    // Logic for trainer card effect.
}
