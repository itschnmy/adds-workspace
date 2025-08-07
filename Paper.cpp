#include "Paper.h"
#include <iostream>

Paper::Paper() : Move("Paper") {}
string Paper::getName() {
    return name;
}
int Paper::result(Move* other) {
    if (other->getName() == "Rock") {
        return 1;
    } else if (other->getName() == "Paper") {
        return 0;
    } else {
        return -1;
    }
}