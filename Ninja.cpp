#include "Ninja.h"
#include <iostream>

Ninja::Ninja() : Move("Ninja") {}
string Ninja::getName() {
    return name;
}
int Ninja::result(Move* other) {
    if (other->getName() == "Pirate" || other->getName() == "Zombie") {
        return 1;
    } else if (other->getName() == "Ninja") {
        return 0;
    } else {
        return -1;
    }
}