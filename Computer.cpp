#include <iostream>
#include "Computer.h"
using namespace std;

Computer::Computer() : name("Computer") {}

char Computer::makeMove() {
    return 'R';
}

string Computer::getName() {
    return name;
}