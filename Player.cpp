#include "Player.h"

void Player::adjustHealth(int amount) {
    health += amount;
    std::cout << "Health adjusted by " << amount << ". Current health: " << health << std::endl;
}

void Player::adjustEnergy(int amount) {
    energy += amount;
    std::cout << "Energy adjusted by " << amount << ". Current energy: " << energy << std::endl;
}

void Player::adjustFog(int amount) {
    fog += amount;
    std::cout << "Fog adjusted by " << amount << ". Current fog: " << fog << std::endl;
}

void Player::adjustDamage(int amount) {
    damage += amount;
    std::cout << "Damage adjusted by " << amount << ". Current damage: " << damage << std::endl;
}

void Player::incrementPortals() {
    portalsFound++;
    std::cout << "Portals found: " << portalsFound << std::endl;
}

int Player::getDamage() const {
    return damage;
}

int Player::getHealth() const {
    return health;
}

bool Player::hasWon() const {
    return portalsFound >= 3;
}

void Player::showStats() const {
    std::cout << "Health: " << health
        << ", Energy: " << energy
        << ", Fog: " << fog
        << ", Damage: " << damage
        << ", Portals Found: " << portalsFound << std::endl;
}
