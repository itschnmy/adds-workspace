#include <iostream>
#include "Human.h"
using namespace std;

Human::Human() : name("Human") {}
Human::Human(string name) : name(name) {}

char Human::makeMove() {
    char move;
    cout << "Enter move: ";
    cin >> move;
    while (move != 'R' && move && 'P' || move && 'S') {
        cout << "Enter move: "
        cin >> move;
    };
    return move;
}
