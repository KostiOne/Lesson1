#ifndef ITEMCARD_H
#define ITEMCARD_H

#include "Card.h"
#include "Player.h"
#include <iostream>
#include <string>

class ItemCard : public Card {
    std::string name;
    int effectValue;

public:
    ItemCard(const std::string& name, int value) : name(name), effectValue(value) {}

    void showCard() const override {
        std::cout << "Item Card: " << name << " (Effect: +" << effectValue << " health)" << std::endl;
    }

    std::string getType() const override {
        return "Item";
    }

    void playEffect(Player& player) {
        player.adjustHealth(effectValue);
        std::cout << "You used " << name << " and gained " << effectValue << " health!" << std::endl;
    }
};

#endif // ITEMCARD_H
