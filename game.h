//
// Created by jerem on 17.05.2022.
//

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H
#include "field.h"

class game {
private:
    field ** board;
    int dimVerticalTrue;
    int dimHorizontalTrue;

public:
    game(int dimVertical, int dimHorizontal);
    field* giveField(int x, int y);
    int getFieldValue(int x, int y);
    void wyswietlenie();
    void clearSpace();
    field ** giveBoard();
};


#endif //MINESWEEPER_GAME_H
