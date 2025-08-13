#include "Robot.h"
#include <iostream>
using namespace std;

Robot::Robot() : Move("Robot") {}
string Robot::getName() {
    return name;
}
int Robot::result(Move* other) {
    if (other->getName() == "Ninja" || other->getName() == "Zombie") {
        return 1;
    } else if (other->getName() == "Robot") {
        return 0;
    } else {
        return -1;
    }
}