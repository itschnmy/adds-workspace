#ifndef NINJA_H
#define NINJA_H
#include "Move.h"
#include <string>

class Ninja : public Move {
public:
    Ninja();
    std::string getName() override;
    int result(Move* other) override;
};

#endif