#ifndef PAPER_H
#define PAPER_H
#include "Move.h"

class Paper : public Move {
public:
    Paper();
    string getName() override;
    int result(Move* other) override;
};

#endif