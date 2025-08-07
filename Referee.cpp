#include <iostream>
#include "Referee.h"
#include "Move.h"

Referee::Referee() {}
Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();
    if (move1->result(move2) == 1) {
        return player1;
    } else if (move1->result(move2) == 0) {
        return nullptr;
    } else {
        return player2;
    }
}