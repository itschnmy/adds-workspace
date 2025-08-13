#ifndef PAPER_H
#define PAPER_H
#include "Move.h"
#include <string>

class Paper : public Move {
public:
    Paper();
    std::string getName() override;
    int result(Move* other) override;
};

#endif