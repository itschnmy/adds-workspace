#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include "Move.h"

class Human : public Player {
public:
    Human();
    Human(std::string name);
    Move* makeMove() override;
    std::string getName() override;
};

#endif