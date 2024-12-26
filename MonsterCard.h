#ifndef MONSTERCARD_H
#define MONSTERCARD_H

#include "Card.h"
#include "Player.h" // Для доступа к игроку
#include <iostream>

class MonsterCard : public Card {
    int strength;
    int health;

public:
    MonsterCard(int str, int hlt) : strength(str), health(hlt) {}

    void showCard() const override {
        std::cout << "Monster Card: Strength = " << strength
            << ", Health = " << health << std::endl;
    }

    std::string getType() const override {
        return "Monster";
    }

    void playEffect(Player& player) {
        std::cout << "Fighting a monster with strength " << strength << " and health " << health << "!" << std::endl;

        if (player.getDamage() >= strength) {  // Используем геттер
            player.adjustHealth(-strength / 2);
            std::cout << "You defeated the monster!" << std::endl;
        }
        else {
            player.adjustHealth(-strength);
            std::cout << "The monster was too strong! You took damage." << std::endl;
        }
    }
};

#endif // MONSTERCARD_H
