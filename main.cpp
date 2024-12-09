#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Création du joueur 1 (Hadi)
    Player player1("Hadi");
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 2, "thunder bolt", 20, 3, "thunder storm", 30));

    // Activation de la carte Pokémon de Hadi (Pikachu)
    cout << "Hadi is activating a Pokemon Card: Pikachu" << endl;
    player1.activatePokemonCard(3);

    // Attacher des cartes d'énergie
    cout << "Hadi is attaching Energy Card of type Electric to the Pokemon Pikachu" << endl;
    player1.attachEnergyCard(0, 0); // Attache l'énergie à l'attaque 0
    cout << "Hadi is attaching Energy Card of type Electric to the Pokemon Pikachu" << endl;
    player1.attachEnergyCard(0, 0); // Attache l'énergie à l'attaque 0

    // Affichage des cartes de banc et des cartes d'action de Hadi
    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();

    // Création du joueur 2 (Germain)
    Player player2("Germain");
    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, "Leech Seed", 15, 3, "Vine Whip", 25));

    // Activation de la carte Pokémon de Germain (Bulbasaur)
    cout << "Germain is activating a Pokemon Card: Bulbasaur" << endl;
    player2.activatePokemonCard(2);

    // Attacher des cartes d'énergie
    cout << "Germain is attaching Energy Card of type Grass to the Pokemon Bulbasaur" << endl;
    player2.attachEnergyCard(0, 0); // Attache l'énergie à l'attaque 0

    // Affichage des cartes de banc et des cartes d'action de Germain
    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();

    // Hadi attaque avec Pikachu
    cout << "Hadi attacking Germain’s Pokemon Bulbasaur with the Pokemon Pikachu with its attack: thunder bolt" << endl;
    player1.attack(0, 0, player2, 0); // Attaque de Hadi

    // Affichage de l'état de Germain après l'attaque
    cout << endl;
    player2.displayAction();

    // Germain utilise la carte Trainer pour soigner son Pokémon
    cout << "Germain is using the Trainer Card to \"heal all your action pokemon\"" << endl;
    player2.useTrainer(0); // Utilisation de la carte Trainer

    // Affichage de l'état de Germain après l'effet de la carte Trainer
    cout << endl;
    player2.displayAction();

    return 0;
}
