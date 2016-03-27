#include "Cell.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Cell::Cell(int x, string y) {
    set(x, y);
}

Cell::Cell(int x) {
    setX(x);
}

void Cell::set(int x, string y) {
    X = x;
    Y = y;
}

void Cell::setX(int x) {
    X = x;
}

void Cell::setY(string y) {
    Y = y;
}

void Cell::setPlayer(char player) {
    Player = player;
}

int Cell::getX()const {
    return X;
}

string Cell::getY()const {
    return Y;
}

char Cell::getPlayer()const {
    return Player;
}

bool Cell::operator<(const Cell other) {
    if (Y < other.getY())
        return true;
    else if (Y == other.getY()) {
        if (X < other.getX())
            return true;
        else
            return false;
    } else
        return false;
}

bool Cell::operator>(const Cell other) {
    if (convertToInt(Y) > other.convertToInt(other.getY()))
        return true;
    else if (convertToInt(Y) == other.convertToInt(other.getY())) {
        if (X > other.getX())
            return true;
        else
            return false;
    } else
        return false;
}

bool Cell::operator<=(const Cell other) {
    if (convertToInt(Y) <= other.convertToInt(other.getY()))
        return true;
    else
        return false;
}

bool Cell::operator>=(const Cell other) {
    if (convertToInt(Y) >= other.convertToInt(other.getY()))
        return true;
    else
        return false;
}

bool Cell::operator==(const Cell other) {
    if (convertToInt(Y) == other.convertToInt(other.getY())) {
        if (X == other.getX())
            return true;
        else
            return false;
    } else
        return false;
}

bool Cell::operator!=(const Cell other) {
    if (convertToInt(Y) != other.convertToInt(other.getY()))
        return true;
    else if (convertToInt(Y) == other.convertToInt(other.getY())) {
        if (X != other.getX())
            return true;

    }
    return false;
}

Cell Cell::operator++() {

    setX(X + 1);
    setY(convertToStr(convertToInt(Y) + 1));

    return *this;
}

Cell Cell::operator++(int) {
    Cell temp;
    temp.setX(X);
    temp.setY(Y);

    setX(X + 1);
    setY(convertToStr(convertToInt(Y) + 1));

    return temp;
}

Cell Cell::operator--() {
    setX(X - 1);
    setY(convertToStr(convertToInt(Y) - 1));

    return *this;
}

Cell Cell::operator--(int) {
    Cell temp;
    temp.setX(X);
    temp.setY(Y);

    setX(X - 1);
    setY(convertToStr(convertToInt(Y) - 1));

    return temp;
}

int Cell::convertToInt(const string strCol)const {
    int col = 0;
    for (int i = 0; i < (signed)strCol.length(); ++i)
        col = col * 26 + strCol[i] - 64;

    return col;
}

string Cell::convertToStr(int num)const {
    string strCol = "";
    while (num > 0) {
        strCol = (char) (65 + (num - 1) % 26) + strCol;
        num = (num - 1) / 26;
    }
    return strCol;
}