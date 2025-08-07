#ifndef MONKEY_H
#define MONKEY_H
#include "Move.h"

class Monkey : public Move {
public:
    Monkey();
    string getName() override;
    int result(Move* other) override;
};

#endif