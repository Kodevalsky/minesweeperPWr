//
// Created by jerem on 17.05.2022.
//

#ifndef MINESWEEPER_FIELD_H
#define MINESWEEPER_FIELD_H


class field {
private:
    bool visibilityStatus = false;
    bool flagStatus = false;
    bool bombStatus = false;
    int value;
    int bombValue = 0;
public:
    void revealField();
    void setFlag();
    void deleteFlag();
    void setValue(int tempValue);
    int giveValue();
    bool isFlagged();
    bool isVisible();
    int giveBombValue();
    void serialReveal(field ** board);
    int x;
    int y;
    void bombSetup();
    bool giveBombStatus();
};


#endif //MINESWEEPER_FIELD_H
