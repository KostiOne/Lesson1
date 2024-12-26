#include "Game.h"
#include <iostream>

Game::Game() : player(100, 10, 5), deck() {
    for (int i = 0; i < 3; ++i) {
        drawNewCard(); // Изначально добавляем 3 карты на поле
    }
}

void Game::drawNewCard() {
    if (!deck.isEmpty()) {
        field.push_back(deck.drawCard());
    }
}

void Game::showField() const {
    std::cout << "Cards on the field:" << std::endl;
    for (size_t i = 0; i < field.size(); ++i) {
        std::cout << i + 1 << ": ";
        field[i]->showCard();
    }
}

void Game::playCard(int choice) {
    if (choice > 0 && choice <= static_cast<int>(field.size())) {
        auto& selectedCard = field[choice - 1];

        if (selectedCard->getType() == "Portal") {
            dynamic_cast<PortalCard*>(selectedCard.get())->playEffect(player);
        }
        else if (selectedCard->getType() == "Monster") {
            dynamic_cast<MonsterCard*>(selectedCard.get())->playEffect(player);
        }

        field.erase(field.begin() + choice - 1); // Удаляем карту
        drawNewCard();                           // Добавляем новую карту на поле
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

void Game::start() {
    while (!player.hasWon() && player.getHealth() > 0) {
        std::cout << "Player stats:" << std::endl;
        player.showStats();

        showField();

        std::cout << "Choose a card to play (1-" << field.size() << "): ";
        int choice;
        std::cin >> choice;

        playCard(choice);
    }

    if (player.hasWon()) {
        std::cout << "Congratulations, you won the game!" << std::endl;
    }
    else {
        std::cout << "Game Over. You lost!" << std::endl;
    }
}
