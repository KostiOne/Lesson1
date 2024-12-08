#include "Store.h"
#include <iostream>
#include <iomanip>

Store::Store(std::string n) : name(n) {}

void Store::addGame(const Game& game) {
    inventory.push_back(game);
}

void Store::displayGames() const {
    std::cout << "\nAvailable Games:";
    std::cout << "\n" << std::string(60, '-') << std::endl;
    std::cout << std::setw(5) << std::left << "ID"
        << std::setw(35) << std::left << "Title"
        << std::setw(15) << std::left << "Genre"
        << std::setw(10) << std::left << "Year"
        << "Price" << std::endl;
    std::cout << std::string(60, '-') << std::endl;

    for (size_t i = 0; i < inventory.size(); i++) {
        std::cout << std::setw(5) << std::left << i + 1
            << std::setw(35) << std::left << inventory[i].getDescription()
            << std::setw(15) << std::left << inventory[i].getGenre()
            << std::setw(10) << std::left << inventory[i].getReleaseYear()
            << "$" << std::fixed << std::setprecision(2) << inventory[i].getPrice() << std::endl;
    }
}

Game* Store::getGame(int id) {
    if (id >= 1 && id <= static_cast<int>(inventory.size())) {
        return &inventory[id - 1];
    }
    return nullptr;
}

std::string Store::getName() const {
    return name;
}