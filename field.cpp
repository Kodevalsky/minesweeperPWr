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