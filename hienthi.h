#ifndef HIENTHI_H

#include "mylib.h"
#include <string>
#include <iostream>
#include <ctime>
#include <math.h>

const int YELLOW = 14;
const int WHITE = 15;
const int BLACK = 0;
const int BLUE = 3;
const int GREEN = 10;
const int RED = 4;

using namespace std;
void press_key();
void Normal();
void Normalw();
void HighLight();
void rectangle(int x, int y, int width, int height, int color);
void mauChu(int x, int y, int color, string chu);
void GiaoDienGV();
void GiaoDienSV();
void TieuDe(); 	
void DangNhap();
void clear_screen(int x, int y, int width, int height);
void clear_screen1();
void clear_screen2();
void clear_screen3();
void clear_screen4();
void clear_screen5();
void clear_screenDA();
void clear_screenTime();
void clear_screenTT();
void guide_Lop();
void table_LOP();
void guide_MH();
void guide_Thi();
void guide_Diem();
void table_MH();
void table_DiemMH();
void table_Diem();
void table_SV();
void table_CH();
void table_DE();
void guide_DE();
void guide_SV();
void guide_CH();
void table_LB();
void table_CHD();

#endif
