#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "PokemonCard.h"
#include <vector>
#include <string>

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;

public:
    Player(const std::string& name) : playerName(name) {}
    ~Player();

    void addCardToBench(Card* card);
    void activatePokemonCard(int index);
    void attachEnergyCard(int benchIndex, int attackIndex);
    void displayBench() const;
    void displayAction() const;
    void attack(int attackerIndex, int attackIndex, Player& opponent, int defenderIndex);
    void useTrainer(int trainerIndex);
};

#endif 
