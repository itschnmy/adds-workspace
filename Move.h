#ifndef MOVE_H
#define MOVE_H
#include <string>

class Move {
protected: 
    std::string name;
public:
    Move(std::string name);
    virtual std::string getName();
    virtual int result(Move* other) = 0;
    virtual ~Move();
};

#endif