#include "Game.h"

Game::Game(std::string t, double p, std::string g, int year, bool collectors)
    : title(t), price(p), genre(g), releaseYear(year), isCollectorsEdition(collectors) {}

std::string Game::getTitle() const {
    return title;
}

double Game::getPrice() const {
    return price;
}

std::string Game::getGenre() const {
    return genre;
}

int Game::getReleaseYear() const {
    return releaseYear;
}

bool Game::isCollectors() const {
    return isCollectorsEdition;
}

std::string Game::getDescription() const {
    std::string desc = title;
    return desc;
}