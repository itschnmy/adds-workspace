#include <iostream>
#include "Human.h"
using namespace std;

Human::Human() : Player("Human") {}
Human::Human(string name) : Player(name) {}

Move* Human::makeMove() {
    string move;
    cout << "Enter move: ";
    cin >> move;
    switch(move) {
    case "Rock":
        return new Rock();
        break;
    case "Scissors":
        return new Scissors();
        break;
    case "Paper":
        return new Paper();
        break;
    case "Ninja":
        return new Ninja();
        break;
    case "Pirate":
        return new Pirate();
        break;
    case "Monkey":
        return new Monkey();
        break;
    case "Robot":
        return new Robot();
        break;
    case "Zombie":
        return new Zombie();
    default:
        return nullptr;
        break;
    }
}

string Human::getName() {
    return name;
}
