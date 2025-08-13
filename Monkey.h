#ifndef MONKEY_H
#define MONKEY_H
#include "Move.h"
#include <string>

class Monkey : public Move {
public:
    Monkey();
    std::string getName() override;
    int result(Move* other) override;
};

#endif