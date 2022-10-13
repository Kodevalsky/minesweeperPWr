#include "cGame.h"
#include <iostream>

int main() {

    cGame * instance = new cGame(30, 30);
    std::cout << "Witaj w grze saper! Wprowadz prosze pozadana ilosc bomb na planszy 30x30 pol..." << std::endl;
    int g;
    std::cin >> g;
    instance->bombGenerator(g);
    instance->setValues();
    int cond = 0;
    while(cond == 0) {
        cond = instance->checkWin(g);
        if(cond == 2){
            break;
        }
        instance->showBoard();
        cond = instance->playerSteering();
        if(cond == 1){
            break;
        }
        instance->clearSpace();
    }
    instance->endScreen(cond);
    delete instance;
    return 0;
}
