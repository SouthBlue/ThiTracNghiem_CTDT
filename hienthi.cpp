#include "hienthi.h"



void press_key(){
	SetColor(WHITE);
	char menu2 [3][50] = {"<-  ->: DI CHUYEN", "      ENTER: CHON", "       ESC: THOAT"};
	for(int i = 0; i< 3; i++){
		gotoxy(3+i*20, 38);
		cout<< menu2[i];
	}
}
void Normal(){
	SetColor(BLUE);
	SetBGColor(BLACK);
}
void Normalw()
{
	SetColor(WHITE);
	SetBGColor(BLACK);
}
void HighLight(){
	SetColor(BLUE);
	SetBGColor(WHITE);
}
void rectangle(int x, int y, int width, int height, int color)
{
	SetColor(color);
	gotoxy(x, y);
	cout << static_cast<char>(201);
	for (int i = x; i < x + width - 2; i++) {
		gotoxy(i + 1, y);
		cout << static_cast<char>(205);
		gotoxy(i + 1, y + height - 1);
		cout << static_cast<char>(205);
	}
	gotoxy(x + width - 1, y);
	cout << static_cast<char>(187) << endl;
	for (int i = y; i < y + height - 1; i++) {
		gotoxy(x, i + 1);
		cout << static_cast<char>(186);
		gotoxy(x + width - 1, i + 1);
		cout << static_cast<char>(186) << endl;
	}
	gotoxy(x, y + height - 1);
	cout << static_cast<char>(200);
	gotoxy(x + width - 1, y + height - 1);
	cout << static_cast<char>(188);
	SetColor(WHITE);
}
void mauChu(int x, int y, int color, string chu){
	SetColor(color);
	gotoxy(x, y);
	cout << chu;
	SetColor(WHITE);
}
void GiaoDienGV(){
	SetColor(3);
	rectangle(0, 0, 105, 10, BLUE);
	rectangle(0, 10, 105, 27, BLUE);
	rectangle(106, 0, 38, 37, BLUE);
	rectangle(0, 37, 144, 3, BLUE);
	mauChu(112, 1, RED, "=======> THONG TIN <========");
	mauChu(112, 10, RED, "========> TAC VU <=========");
	mauChu(3, 37, RED, "---> HUONG DAN <---");
}
void GiaoDienSV(){
	SetColor(3);
	rectangle(0, 0, 105, 10, BLUE);
	rectangle(0, 10, 105, 27, BLUE);
	rectangle(106, 0, 38, 9, BLUE);
	rectangle(106, 9, 38, 4, BLUE);
	rectangle(106, 13, 38, 24, BLUE);
	rectangle(0, 37, 144, 3, BLUE);
	mauChu(112, 1, RED, "=======> THONG TIN <========");
	mauChu(112, 10, RED, "=======> THOI GIAN <========");
	mauChu(112, 14, RED, "========> DAP AN <=========");
	mauChu(3, 37, RED, "---> HUONG DAN <---");
}
void TieuDe(){
	SetColor(GREEN);
	gotoxy(5, 2);
	cout << "       ______  __              ______                          __  __          __                   \n";
	gotoxy(5, 3);
	cout << "      /\\__  _\\/\\ \\      __    /\\__  _\\                        /\\ \\/\\ \\        /\\ \\      __              \n";
	gotoxy(5, 4); 
	cout << "      \\/_/\\ \\/\\ \\ \\___ /\\_\\   \\/_/\\ \\/ _ __    __      ___    \\ \\ `\\\\ \\     __\\ \\ \\___ /\\_\\     __    ___ ___     \n";
	gotoxy(5, 5);
	cout << "         \\ \\ \\ \\ \\  _ `\\/\\ \\     \\ \\ \\/\\`'__\\/'__`\\   /'___\\   \\ \\ , ` \\  /'_ `\\ \\  _ `\\/\\ \\  /'__`\\/' __` __`\\   \n";
	gotoxy(5, 6);
	cout << "          \\ \\ \\ \\ \\ \\ \\ \\ \\ \\     \\ \\ \\ \\ \\//\\ \\L\\.\\_/\\ \\__/    \\ \\ \\`\\ \\/\\ \\L\\ \\ \\ \\ \\ \\ \\ \\/\\  __//\\ \\/\\ \\/\\ \\  \n";
	gotoxy(5, 7);
	cout << "           \\ \\_\\ \\ \\_\\ \\_\\ \\_\\     \\ \\_\\ \\_\\\\ \\__/.\\_\\ \\____\\    \\ \\_\\ \\_\\ \\____ \\ \\_\\ \\_\\ \\_\\ \\____\\ \\_\\ \\_\\ \\_\\ \n";
	gotoxy(5, 8);
	cout << "            \\/_/  \\/_/\\/_/\\/_/      \\/_/\\/_/ \\/__/\\/_/\\/____/     \\/_/\\/_/\\/___L\\ \\/_/\\/_/\\/_/\\/____/\\/_/\\/_/\\/_/ \n";
	gotoxy(5, 9);
	cout << "                                                                            /\\____/                               \n";
	gotoxy(5, 10);
	cout << "                                                                            \\_/__/                                \n";
}
void clear_screen(int x, int y, int width, int height)
{
	for(int i = 0; i < height; ++i)
	{
		gotoxy(x, i + y);
		for(int j = 0; j < width; ++j)
		{
			cout << " ";
		}
	}
	SetBGColor(BLACK);
	SetColor(WHITE);
}
void DangNhap(){
	rectangle(0, 0, 145, 39, GREEN);
	TieuDe();
	rectangle(45, 15, 50 , 15, GREEN);
	rectangle(46, 16, 48 , 14, GREEN);	
	rectangle(52, 19, 37, 3, GREEN);
	mauChu(63, 16, RED, "=> DANG NHAP <=");
	rectangle(65, 26, 10, 3, GREEN);
	mauChu(66, 27, RED, " ENTER ");
	mauChu(55, 19, WHITE, "NguoiDung:");
	rectangle(52, 23, 37, 3, GREEN);
	mauChu(57, 23, WHITE, "MatKhau:");
	gotoxy(55, 20);
}
void clear_screen1()
{
	Normal();
	clear_screen(1, 1, 102, 8);
}
void clear_screen2()
{
	Normal();
	clear_screen(1, 11, 103, 24);
}
void clear_screen3()
{
	Normal();
	clear_screen(1, 38, 140, 1);
}
void clear_screen4()
{
	Normal();
	clear_screen(107, 2, 36 , 7);
}
void clear_screen5()
{
	Normal();
	clear_screen(107, 11, 36 , 25);
}
void clear_screenTT()
{
	Normal();
	clear_screen(107, 4, 36 , 3);
}
void clear_screenTime()
{
	Normal();
	clear_screen(107, 11, 36 , 1);
}
void clear_screenDA()
{
	Normal();
	clear_screen(107, 15, 36 , 21);
}
void guide_Lop(){
	SetColor(WHITE);
	gotoxy(3, 38);
	cout<< "UP, DOWN, LEFT, RIGHT: DI CHUYEN      ESC: TRO VE     ~ : TRANG CHINH     INSERT: THEM      DELETE: XOA     ENTER: CHON";
}
void table_LOP()
{
	mauChu(35, 11, RED, "=====** DANH SACH CAC LOP **=====");
	mauChu(6, 14, WHITE, " Ma Lop                   ||   Ten Lop                     ||  So luong SV");
}
void guide_SV(){
	SetColor(WHITE);
	gotoxy(3, 38);
	cout << "UP, DOWN, LEFT, RIGHT: DI CHUYEN     ESC: TRO VE     ~ : TRANG CHINH      INSERT: THEM       DELETE: XOA";
}
void guide_MH(){
	SetColor(WHITE);
	gotoxy(3, 38);
	cout << "UP, DOWN: DI CHUYEN     ESC: TRO VE     ~ : TRANG CHINH     TAB: SUA    INSERT: THEM     DELETE: XOA     ENTER: CHON";
}
void guide_CH()
{
	SetColor(WHITE);
	gotoxy(3, 38);
	cout << "UP, DOWN, LEFT, RIGHT: DI CHUYEN     ESC: TRO VE     ~ : TRANG CHINH      INSERT: THEM       ENTER: HIEN THI";
}
void guide_DE()
{
	SetColor(WHITE);
	gotoxy(3, 38);
	cout << "UP, DOWN, LEFT, RIGHT: DI CHUYEN     ESC: TRO VE     ~ : TRANG CHINH      INSERT: THEM     DELETE: XOA ";
}
void guide_Thi(){
	SetColor(WHITE);
	gotoxy(3, 38);
	cout<< "UP, DOWN, LEFT, RIGHT: DI CHUYEN      ESC: TRO VE     F1: NOP BAI       ENTER: CHON";
}
void guide_Diem()
{
	SetColor(WHITE);
	gotoxy(3, 38);
	cout << "UP, DOWN, LEFT, RIGHT: DI CHUYEN     ESC: TRO VE     ~ : TRANG CHINH      ENTER: CHON ";
}
void table_MH(){
	mauChu(35, 11, RED, "=====** DANH SACH CAC MON **=====");
	mauChu(6, 14, WHITE, " Ma Mon Hoc       ||   Ten Mon Hoc                                        ||  SL cau hoi");
}
void table_DiemMH(){
	mauChu(35, 11, RED, "=====** DANH SACH CAC MON **=====");
	mauChu(6, 14, WHITE, " Ma Mon Hoc                          ||   Ten Mon Hoc                                ");
}
void table_SV()
{
	mauChu(30, 11, RED, "=====** DANH SACH SINH VIEN CUA LOP **=====");
	gotoxy(7, 14);
	cout << "MASV              ||     Ho                          ||    Ten                  ||    Phai   ";
}
void table_CH()
{
	mauChu(35, 11, RED, "=====** DANH SACH CAU HOI **=====");
	mauChu(6, 14, WHITE, " ID    || Cau hoi                                                             ||   Dap an  ");
}
void table_Diem(){
	mauChu(39, 11, RED, "=====** BANG DIEM **=====");
	mauChu(6, 14, WHITE, " MASV              ||               Ho va Ten                                ||     Diem      ");
}
void table_DE()
{
	mauChu(35, 11, RED, "=====** DANH SACH DE THI **=====");
	mauChu(6, 14, WHITE, " Ma De Thi       ||            So Luong Cau Hoi                     ||  Thoi Gian Thi");
}
void table_LB()
{
	mauChu(35, 11, RED, "=========** LAM BAI **=========");
}
void table_CHD()
{
	mauChu(27, 11, RED, "=====** DANH SACH CAU HOI DA THI CUA SV **=====");
	mauChu(6, 14, WHITE, " STT   ||  Cau hoi                                                      ||  DA dung  ||  DA chon ");
}
