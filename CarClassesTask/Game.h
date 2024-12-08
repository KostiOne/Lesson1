#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
private:
    std::string title;
    double price;
    std::string genre;
    int releaseYear;
    bool isCollectorsEdition;

public:
    // Constructor
    Game(std::string t, double p, std::string g, int year, bool collectors = false);

    // Getter methods
    std::string getTitle() const;
    double getPrice() const;
    std::string getGenre() const;
    int getReleaseYear() const;
    bool isCollectors() const;
    std::string getDescription() const;
};

#endif // GAME_H