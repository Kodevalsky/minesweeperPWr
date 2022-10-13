//
// Created by jerem on 17.05.2022.
//

#include "cGame.h"
#include <iostream>
#include <random>
#include <ctime>
#include <conio.h>
#include <windows.h>

cGame::cGame(int dimVertical, int dimHorizontal){
    mDimVerticalTrue = dimVertical;
    mDimHorizontalTrue = dimHorizontal;
    mBoard = new cField * [dimVertical];
    for (int i = 0; i < dimVertical; i++) {
        mBoard[i] = new cField [dimHorizontal];
    }
    for (int i = 0; i < dimVertical; i++) {
        for (int j = 0; j < dimHorizontal; j++) {
            mBoard[i][j].mX = i;
            mBoard[i][j].mY = j;

        }
    }

}

cField* cGame::giveField(int x, int y) {
    return &mBoard[x][y];
}


void cGame::showBoard() {
    std::cout << std::endl << "   ";
    for (int j = 0; j <= mDimHorizontalTrue; j++) {
        if(j < 10 && j != 0){
            std::cout << '0';
        }
        if(j != 0){
            std::cout << j << " ";

        }
    }
    for (int i = 0; i < mDimVerticalTrue; i++) {
        std::cout << std::endl;
        if(i+1 < 10 && i+1 != 0){
            std::cout << '0';
        }
        if(i+1 != 0){
            std::cout << i+1 << " ";}
        for (int j = 0; j < mDimHorizontalTrue; j++) {
            if (giveField(i, j)->isFlagged()) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                std::cout << " F ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else if(giveField(i, j)->isVisible()){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cField * s = giveField(i, j);
                std::cout << *s;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                std::cout << " # ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
        }
    }
    std::cout << std::endl << std::endl;
}

void cGame::clearSpace(){
    for(int i = 0; i < 50; i++){
        std::cout << std::endl;
    }
}

void cGame::bombGenerator(int bombAmount) {
    srand(time(NULL));
    for(int i = 0; i < bombAmount; i++){
        int a = rand() % mDimVerticalTrue, b = rand() % mDimHorizontalTrue;
        if(!mBoard[a][b].giveBombStatus()){
            mBoard[a][b] = true;
        }
        else{
            i--;
        }
    }
}

void cGame::setValues() {
    for (int s = 0; s < mDimVerticalTrue; s++) {
        for (int g = 0; g < mDimHorizontalTrue; g++) {
            if(~mBoard[s][g].giveBombStatus()){
                for (int r = -1; r < 2; r++) {
                    for (int t = -1; t < 2; t++) {
                        if ((s+r >= 0 && g+t >= 0) && (s+r < mDimVerticalTrue && g + t < mDimHorizontalTrue)){
                            if(mBoard[s + r][g + t].giveBombStatus())
                                mBoard[s][g] += 1;
                        }

                    }
                }
            }
        }
    }
}

int cGame::playerSteering(){
    here:
    std::cout << "Aby umiescic flage, kliknij 1, aby usunac flage kliknij 2, aby odkryc pole kliknij 3";
    int choice;
    std::cin >> choice;
    std::cout << "Wybierz prosze wspolrzedna X pola: " << std::endl;
    int x;
    std::cin >> x;
    std::cout << "Wybierz prosze wspolrzedna Y pola: " << std::endl;
    int y;
    std::cin >> y;
    cField * a = giveField(y - 1, x - 1);
    switch(choice){
        case 1:
            a->setFlag();
            return 0;
        case 2:
            a->deleteFlag();
            return 0;
        case 3:
            return a->serialReveal(mBoard, mDimVerticalTrue, mDimHorizontalTrue);

        default:
            std::cout << "Nieprawidlowa wartosc, wprowadz liczbe ponownie";
            goto here;
    }
}

int cGame::checkWin(int bombAmount){
    int count = 0;
    for (int i = 0; i < mDimVerticalTrue ; i++) {
        for (int j = 0; j < mDimHorizontalTrue; j++) {
            if(mBoard[i][j].giveBombStatus() && mBoard[i][j].isFlagged()){
                count++;
            }
        }
    }
    if(bombAmount == count) return 2;
    else return 0;
}

void cGame::endScreen(int cond) {
    clearSpace();
    if(cond == 1){
        std::cout << "Bardzo mi przykro ale przegrales, sprobuj nastepnym razem!";
    }
    else {
        std::cout << "Serdecznie gratuluje! Zwyciezyles! Zapraszamy do kolejnej gry!";
    }
}

