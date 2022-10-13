//
// Created by jerem on 17.05.2022.
//

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H
#include "cField.h"
#include "cParentGame.h"

class cGame: public cParentGame{
private:
    cField ** mBoard;

public:
    cGame(int dimVertical, int dimHorizontal);
    cField* giveField(int x, int y);
    void showBoard();
    void clearSpace() override;
    void bombGenerator(int bombAmount);
    void setValues();
    int playerSteering();
    int checkWin(int bombAmount);
    void endScreen(int cond);
};


#endif //MINESWEEPER_GAME_H
