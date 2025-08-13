#include <iostream>
#include "Human.h"
#include "Monkey.h"
#include "Ninja.h"
#include "Paper.h"
#include "Pirate.h"
#include "Robot.h"
#include "Rock.h"
#include "Scissors.h"
#include "Zombie.h"
using namespace std;

Human::Human() : Player("Human") {}
Human::Human(string name) : Player(name) {}

Move* Human::makeMove() {
    string move;
    cout << "Enter move: ";
    cin >> move;
    if (move == "Rock") {
        return new Rock();
    } else if (move == "Paper") {
        return new Paper();
    } else if (move == "Scissors") {
        return new Scissors();
    } else if (move == "Pirate") {
        return new Pirate();
    } else if (move == "Robot") {
        return new Robot();
    } else if (move == "Monkey") {
        return new Monkey();
    } else if (move == "Zombie") {
        return new Zombie();
    } else if (move == "Ninja") {
        return new Ninja();
    } else {
        return nullptr;
    }
}

string Human::getName() {
    return name;
}
