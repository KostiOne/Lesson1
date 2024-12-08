#include "Player.h"
#include <iostream>
#include <iomanip>

Player::Player(double startingMoney) : money(startingMoney) {}

double Player::getMoney() const {
    return money;
}

bool Player::buyGame(const Game& game) {
    if (money >= game.getPrice()) {
        money -= game.getPrice();
        inventory.push_back(game);
        return true;
    }
    return false;
}

void Player::displayInventory() const {
    std::cout << "\nYour Game Collection:\n";
    if (inventory.empty()) {
        std::cout << "No games in your collection yet!\n";
        return;
    }
    std::cout << std::string(70, '-') << std::endl;
    std::cout << std::setw(35) << std::left << "Title"
        << std::setw(15) << std::left << "Genre"
        << std::setw(10) << std::left << "Year"
        << "Price" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    double totalValue = 0.0;
    for (const auto& game : inventory) {
        std::cout << std::setw(35) << std::left << game.getDescription()
            << std::setw(15) << std::left << game.getGenre()
            << std::setw(10) << std::left << game.getReleaseYear()
            << "$" << std::fixed << std::setprecision(2) << game.getPrice() << std::endl;
        totalValue += game.getPrice();
    }

    std::cout << std::string(70, '-') << std::endl;
    std::cout << "Total Collection Value: $" << std::fixed << std::setprecision(2) << totalValue << std::endl;
}