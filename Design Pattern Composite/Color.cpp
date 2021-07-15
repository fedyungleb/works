//
// Created by User on 28.05.2021.
//

#include "Color.h"
#include "windows.h"

void Color::setConsoleColor(int color) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color);
}
