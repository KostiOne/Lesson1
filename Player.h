#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player {
    int health;
    int energy;
    int fog;
    int damage;
    int portalsFound;

public:
    Player(int hp, int en, int dmg)
        : health(hp), energy(en), fog(0), damage(dmg), portalsFound(0) {}

    void adjustHealth(int amount);
    void adjustEnergy(int amount);
    void adjustFog(int amount);
    void adjustDamage(int amount);
    void incrementPortals();

    int getDamage() const;  // Геттер для урона
    int getHealth() const;
    bool hasWon() const;
    void showStats() const;
};

#endif // PLAYER_H
