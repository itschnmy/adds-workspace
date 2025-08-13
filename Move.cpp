#include "Move.h"
#include <iostream>
using namespace std;

Move::Move(string name) : name(name) {}

string Move::getName() {
    return name;
}

Move::~Move() {}