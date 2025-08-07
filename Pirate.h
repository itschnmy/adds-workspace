#ifndef PIRATE_H
#define PIRATE_H
#include "Move.h"

class Pirate : public Move {
public:
    Pirate();
    string getName() override;
    int result(Move* other) override;
};

#endif