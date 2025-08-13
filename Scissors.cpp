#include "Scissors.h"
#include <iostream>
using namespace std;

Scissors::Scissors() : Move("Scissors") {}
string Scissors::getName() {
    return name;
}
int Scissors::result(Move* other) {
    if (other->getName() == "Paper") {
        return 1;
    } else if (other->getName() == "Scissors") {
        return 0;
    } else {
        return -1;
    }
}