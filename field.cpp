//
// Created by jerem on 17.05.2022.
//

#include "field.h"

void field::deleteFlag() {
    flagStatus = false;
}

void field::revealField() {
    visibilityStatus = true;
}

void field::setFlag() {
    flagStatus = true;
}

void field::setValue(int tempValue) {
    value = tempValue;
}

int field::giveValue() {
    return value;
}

bool field::isFlagged() {
    return flagStatus;
};

bool field::isVisible() {
    return visibilityStatus;
}

int field::giveBombValue() {
    return bombValue;
}

void field::serialReveal(field ** board) {
    if(visibilityStatus == true) return;
    if(bombStatus == false) visibilityStatus = true;

    if(bombValue == 0) {
        for (int s = -1; s < 2; s++) {
            for (int g = -1; g < 2; g++) {
                if ((g != 0 || s != 0) && ((x + s <= 14 && x+s >=0) && (y+g <= 14 && y+g >= 0)) ) {
                    board[x + s][y + g].serialReveal(board);
                }
            }
        }
    }

}

void field::bombSetup() {
    bombStatus = true;
}

bool field::giveBombStatus() {
    return bombStatus;
}