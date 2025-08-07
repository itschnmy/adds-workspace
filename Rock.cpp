#include "Rock.h"
#include <iostream>

Rock::Rock() : Move("Rock") {}
string Rock::getName() {
    return name;
}
int Rock::result(Move* other) {
    if (other->getName() == "Scissors") {
        return 1;
    } else if (other->getName() == "Rock") {
        return 0;
    } else {
        return -1;
    }
}