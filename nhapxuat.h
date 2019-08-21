#ifndef NHAPXUAT_H
#include "mylib.h"
#include <string>
#include <iostream>
using namespace std;

const int UP = 72;
const int DOWN = 80;
const int RIGHT = 77;
const int LEFT = 75;
const int ENTER = 13;
const int ESC = 27;
const int INSERT = 82;
const int DEL = 83;
const int SPACE = 32;
const int EDIT = 9;
const int BACKSPACE = 8;
const int HOME = 96; /* ~ */
const int F1 = 59;

void input_check(int x, int y, int max, int width, string &data, bool id);
void show_string(string str, int max, int x, int y);

#endif
