#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "MonsterCard.h"
#include "PortalCard.h"
#include "ItemCard.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

class Deck {
    std::vector<std::unique_ptr<Card>> cards;
    void initializeDeck();

public:
    Deck();
    bool isEmpty() const;
    std::unique_ptr<Card> drawCard();
};

#endif // DECK_H
