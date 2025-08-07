#include <iostream>
#include "Computer.h"
#include "Rock.h"
using namespace std;

Computer::Computer() : Player("Computer") {}

Move* Computer::makeMove() {
    return new Rock();
}

string Computer::getName() {
    return name;
}