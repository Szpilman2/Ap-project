//
// Created by peyman on 1/31/18.
//

#ifndef OTHELLO_GAME_CORE_H
#define OTHELLO_GAME_CORE_H

#include "accessories.h"

class Core{
public:
    Core();
    Board getBoard();
    int score(int player);
    std::vector<Suggestion> suggest(int player);
    void AIchoice();
    void setBoard(int,int,int);
private:
    Board board;


};
#endif //OTHELLO_GAME_CORE_H
