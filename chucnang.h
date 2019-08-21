#ifndef CHUCNANG_H
#include "danhsach.h"
const int dong = 4;
const int cot = 10;

void begin();
void end();
///////////////////////GIAOVIEN
int MenuGV();
bool thoat();
void giao_vien();
void select_Lop(int);
bool find_MA(string);
void select_SV(int,  int, int);
void select_MH(int);
void select_CauHoi(int, int, MonHoc *&, int);
void select_DiemLop(int , MonHoc *, int);
void select_DiemMH(int );
void select_Diem(int, int, MonHoc *, int);
void show_listCHD(int x, int y, CauHoi *[], int *[], int , int);
void show_CHD(SinhVien *, MonHoc* , int);
void select_MHDE(int chon);
void select_DE(int , int, MonHoc *);
//////////////////SINHVIEN
bool notifi(string str);
void select_MHThi(int, SinhVien*);
void select_DETHI(int , MonHoc*, SinhVien *, int);
void swap_ab(int &, int &);
int rand_so( int *, int, int);
void take_EXAM(int *arr, CauHoi *exam[], MonHoc *a, int limit);
void show_debai(DeThi *, int, int, CauHoi*, int);
void show_dapan(int ans[], int);
int chon_DA();
void save_Diem(SinhVien *sv, string maMH, float score, int limit, int ans[],int arr[]);
void nop_bai(CauHoi *exam[], int ans[], int arr[], MonHoc *a, SinhVien *sv, int limit);
void show_ketqua(float score, int correct, int limit, SinhVien *);
void lam_bai(DeThi *, MonHoc *, SinhVien *);
void show_time(int x, int y, int limit, int timePassed);
void sinh_vien(SinhVien *&);
//////////////////DANGNHAP
void show();
void DangNhap();
void fail_login();
void password_login(int , int , int , string &);
bool GiaoVien(string, string);
void find_user(string, string);
void login_fun();
#endif
