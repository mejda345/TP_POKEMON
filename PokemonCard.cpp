#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& family, 
                         int level, int maxHp, 
                         int attackCost1, const std::string& attackDesc1, int attackDmg1,
                         int attackCost2, const std::string& attackDesc2, int attackDmg2)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(level), maxHP(maxHp), hp(maxHp) {
    // Initialisation des attaques
    attacks.emplace_back(attackCost1, 0, attackDesc1, attackDmg1);
    attacks.emplace_back(attackCost2, 0, attackDesc2, attackDmg2);
}

void PokemonCard::attachEnergy(int attackIndex, int energy) {
    if (attackIndex >= 0 && attackIndex < attacks.size()) {
        auto& currentEnergy = std::get<1>(attacks[attackIndex]);
        currentEnergy += energy;
        std::cout << "Energy added to attack #" << attackIndex << ". Current energy: " << currentEnergy << "\n";
    } else {
        std::cout << "Invalid attack index.\n";
    }
}

int PokemonCard::useAttack(int attackIndex) const {
    if (attackIndex >= 0 && attackIndex < attacks.size()) {
        const auto& attack = attacks[attackIndex];
        int cost = std::get<0>(attack);
        int currentEnergy = std::get<1>(attack);

        if (currentEnergy >= cost) {
            std::cout << "Using attack: " << std::get<2>(attack) << "\n";
            return std::get<3>(attack); 
        } else {
            std::cout << "Not enough energy for this attack.\n";
        }
    } else {
        std::cout << "Invalid attack index.\n";
    }
    return 0;
}

void PokemonCard::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
    std::cout << cardName << " took " << damage << " damage. Remaining HP: " << hp << "/" << maxHP << "\n";
}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << cardName
              << ", Type: " << pokemonType
              << ", Family: " << familyName
              << ", Evolution Level: " << evolutionLevel
              << ", HP: " << hp << "/" << maxHP << "\n";

    for (size_t i = 0; i < attacks.size(); ++i) {
        const auto& attack = attacks[i];
        std::cout << "Attack #" << i << ":\n"
                  << "  Energy Cost: " << std::get<0>(attack) << "\n"
                  << "  Current Energy: " << std::get<1>(attack) << "\n"
                  << "  Description: " << std::get<2>(attack) << "\n"
                  << "  Damage: " << std::get<3>(attack) << "\n";
    }
}


