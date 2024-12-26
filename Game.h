#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"
#include <memory>

class Game {
    Player player;
    Deck deck;
    std::vector<std::unique_ptr<Card>> field;

    void drawNewCard();
    void showField() const;
    void playCard(int choice);

public:
    Game();
    void start();
};

#endif // GAME_H
