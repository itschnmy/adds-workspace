#include "Monkey.h"
#include <iostream>

Monkey::Monkey() : Move("Monkey") {}
string Monkey::getName() {
    return name;
}
int Monkey::result(Move* other) {
    if (other->getName() == "Ninja" || other->getName() == "Robot") {
        return 1;
    } else if (other->getName() == "Monkey") {
        return 0;
    } else {
        return -1;
    }
}