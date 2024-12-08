#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Game.h"

class Player {
private:
    double money;
    std::vector<Game> inventory;

public:
    // Constructor
    Player(double startingMoney);

    // Methods
    double getMoney() const;
    bool buyGame(const Game& game);
    void displayInventory() const;
};

#endif // PLAYER_