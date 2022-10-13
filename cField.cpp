//
// Created by jerem on 17.05.2022.
//

#include "cField.h"
#include <iostream>

void cField::deleteFlag() {
    mFlagStatus = false;
}

void cField::setFlag() {
    mFlagStatus = true;
}

bool cField::isFlagged(){
    return mFlagStatus;
}

bool cField::isVisible(){
    return mVisibilityStatus;
}

int cField::giveBombValue(){
    return mBombValue;
}

int cField::serialReveal(cField ** board, int dimVertical, int dimHorizontal) {
    if(mVisibilityStatus) return 0;
    if(!mBombStatus) mVisibilityStatus = true;
    else{
        return 1;
    }

    if(mBombValue == 0) {
        for (int s = -1; s < 2; s++) {
            for (int g = -1; g < 2; g++) {
                if ((g != 0 || s != 0) && ((mX + s < dimVertical && mX + s >= 0) && (mY + g < dimHorizontal && mY + g >= 0)) ) {
                    board[mX + s][mY + g].serialReveal(board, dimVertical, dimHorizontal);
                }
            }
        }
    }
    return 0;
}

void cField::bombSetup() {
    mBombStatus = true;
}

bool cField::giveBombStatus() {
    return mBombStatus;
}

void cField::addValue() {
    mBombValue++;
}

std::ostream & operator << (std::ostream &wyjscie, cField &i) {
    wyjscie << " " << i.giveBombValue() << " ";
    return wyjscie;
}

cField & operator+= (cField & val, int a){
    val.mBombValue = val.mBombValue + a;
    return val;
}

cField & cField::operator= (bool a){
    this->mBombStatus = true;
    return * this;
}
