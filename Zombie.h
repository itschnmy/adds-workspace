#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Move.h"

class Zombie : public Move {
public:
    Zombie();
    string getName() override;
    int result(Move* other) override;
};

#endif