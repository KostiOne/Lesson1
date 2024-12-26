#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    virtual ~Card() = default;
    virtual void showCard() const = 0;
    virtual std::string getType() const = 0;
};

#endif // CARD_H
