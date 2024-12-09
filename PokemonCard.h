#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <vector>
#include <tuple>
#include <string>

class PokemonCard : public Card {
private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<std::tuple<int, int, std::string, int>> attacks;

public:
    PokemonCard(const std::string& name, const std::string& type, const std::string& family, 
                int level, int maxHp, 
                int attackCost1, const std::string& attackDesc1, int attackDmg1,
                int attackCost2, const std::string& attackDesc2, int attackDmg2);

    void attachEnergy(int attackIndex, int energy);
    int useAttack(int attackIndex) const;
    void takeDamage(int damage);
    void displayInfo() const override;
    int attack(int attackIndex) const;
    const std::tuple<int, int, std::string, int>& getAttack(int attackIndex) const {
    return attacks[attackIndex];
}


};

#endif 
