#ifndef NINJA_H
#define NINJA_H
#include "Move.h"

class Ninja : public Move {
public:
    Ninja();
    string getName() override;
    int result(Move* other) override;
};

#endif