#include <iostream>
#include "Referee.h"

Referee::Referee() {}
Player* Referee::refGame(Player* player1, Player* player2) {
    char move1 = player1->makeMove();
    char move2 = player2->makeMove();
    if (move1 == move2) {
        return nullptr;
    } else if (move1 == 'R') {
        if (move2 == 'S') {
            return player1;
        } else {
            return player2;
        }
    } else if (move1 == 'S') {
        if (move2 == 'P') {
            return player1;
        } else {
            return player2;
        }
    } else if (move1 == 'P') {
        if (move2 == 'S') {
            return player2;
        } else {
            return player1;
        }
    }
}