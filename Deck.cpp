#include "Deck.h"

Deck::Deck() {
    initializeDeck();
    std::shuffle(cards.begin(), cards.end(), std::mt19937{ std::random_device{}() });
}

void Deck::initializeDeck() {
    for (int i = 0; i < 30; ++i) {
        cards.push_back(std::make_unique<MonsterCard>(10 + i % 10, 20 + i % 5));
    }
    for (int i = 0; i < 10; ++i) {
        cards.push_back(std::make_unique<PortalCard>());
    }
    for (int i = 0; i < 20; ++i) {
        cards.push_back(std::make_unique<ItemCard>("Health Potion", 15));
    }
}

bool Deck::isEmpty() const {
    return cards.empty();
}

std::unique_ptr<Card> Deck::drawCard() {
    if (isEmpty()) return nullptr;

    std::unique_ptr<Card> card = std::move(cards.back());
    cards.pop_back();
    return card;
}
