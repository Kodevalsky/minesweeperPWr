//
// Created by jerem on 17.05.2022.
//

#ifndef MINESWEEPER_FIELD_H
#define MINESWEEPER_FIELD_H
#include <iostream>


class cField {
private:
    bool mVisibilityStatus = false;
    bool mFlagStatus = false;
    bool mBombStatus = false;
    int mBombValue = 0;
public:
    int mX;
    int mY;
    void setFlag();
    void deleteFlag();
    bool isFlagged();
    bool isVisible();
    int giveBombValue();
    int serialReveal(cField ** board, int dimVertical, int dimHorizontal);
    void bombSetup();
    bool giveBombStatus();
    void addValue();
    friend std::ostream & operator<< (std::ostream &wyjscie, cField &i);
    friend cField & operator+= (cField & val , int a);
    cField & operator= (bool a);
};


#endif //MINESWEEPER_FIELD_H
