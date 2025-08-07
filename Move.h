#ifndef MOVE_H
#define MOVE_H
#include <string>

class Move {
private: 
    string name;
public:
    Move();
    virtual string getName();
    virtual int result(Move* other) = 0;
};

#endif