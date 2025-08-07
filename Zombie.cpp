#include "Zombie.h"
#include <iostream>

Zombie::Zombie() : Move("Zombie") {}
string Zombie::getName() {
    return name;
}
int Zombie::result(Move* other) {
    if (other->getName() == "Pirate" || other->getName() == "Monkey") {
        return 1;
    } else if (other->getName() == "Zombie") {
        return 0;
    } else {
        return -1;
    }
}