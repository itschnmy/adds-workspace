#include <iostream>
#include "Computer.h"
using namespace std;

Computer::Computer() : Player("Computer") {}

char Computer::makeMove() {
    return 'R';
}

string Computer::getName() {
    return name;
}