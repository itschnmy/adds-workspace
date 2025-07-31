#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(string name) : name(name) {}
string getName() {
    return name;
}