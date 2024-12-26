#ifndef PORTALCARD_H
#define PORTALCARD_H

#include "Card.h"
#include "Player.h" 
#include <iostream>

class PortalCard : public Card {
public:
    void showCard() const override {
        std::cout << "Portal Card: Collect this to progress towards victory!" << std::endl;
    }

    std::string getType() const override {
        return "Portal";
    }

    void playEffect(Player& player) {
        player.incrementPortals();
        if (player.hasWon()) {
            std::cout << "You have found all the portals! You win the game!" << std::endl;
        }
    }
};

#endif // PORTALCARD_H
