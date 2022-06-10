//
// Created by jerem on 17.05.2022.
//

#include "game.h"
#include <iostream>

game::game(int dimVertical, int dimHorizontal){
    dimVerticalTrue = dimVertical;
    dimHorizontalTrue = dimHorizontal;
    board = new field * [dimVertical];
    for (int i = 0; i < dimVertical; i++) {
        board[i] = new field [dimHorizontal];
    }
    int index = 0;
    for (int i = 0; i < dimVertical; i++) {
        for (int j = 0; j < dimHorizontal; j++) {
            board[i][j].setValue(index++);
        }
    }

}

field* game::giveField(int x, int y) {
    return &board[x][y];
}

int game::getFieldValue(int x, int y) {
    return board[x][y].giveValue();
}

void game::wyswietlenie() {
    std::cout << std::endl;
    for (int j = 0; j < dimHorizontalTrue; j++) {
        std::cout << j << " ";
    }
    for (int i = 0; i < dimVerticalTrue; i++) {
        std::cout << std::endl;
        std::cout << i+1 << " ";
        for (int j = 0; j < dimHorizontalTrue; j++) {
            if (giveField(i, j)->isFlagged()) {
                std::cout << "F" << " ";
            }
            else if (giveField(i, j)->isVisible()) {
                std::cout << giveField(i, j)->giveBombValue() << " ";
            }
            else{
                std::cout << "#" << " ";

            }
        }
    }
}

void game::clearSpace(){
    for(int i = 0; i < 50; i++){
        std::cout << std::endl;
    }
}