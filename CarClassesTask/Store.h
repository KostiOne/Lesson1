#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include "Game.h"

class Store {
private:
    std::string name;
    std::vector<Game> inventory;

public:
    // Constructor
    Store(std::string n);

    // Methods
    void addGame(const Game& game);
    void displayGames() const;
    Game* getGame(int id);
    std::string getName() const;
};

#endif // STORE_H