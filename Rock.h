#ifndef ROCK_H
#define ROCK_H
#include "Move.h"

class Rock : public Move {
public:
    Rock();
    std::string getName() override;
    int result(Move* other) override;
};

#endif