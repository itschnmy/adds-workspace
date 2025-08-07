#include "Pirate.h"
#include <iostream>

Pirate::Pirate() : Move("Pirate") {}
string Pirate::getName() {
    return name;
}
int Pirate::result(Move* other) {
    if (other->getName() == "Robot" || other->getName() == "Monkey") {
        return 1;
    } else if (other->getName() == "Pirate") {
        return 0;
    } else {
        return -1;
    }
}