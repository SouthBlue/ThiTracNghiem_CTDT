#ifndef DANHSACH_H
#include "hienthi.h"
#include "nhapxuat.h"
#include <fstream>

const int MAXLOP = 500;
const int MAXCAUHOI = 2000;
const int MAXDATHI = 100;


using namespace std;

struct CauHoiDaThi{
	int id;
	int DAchon;
	void read_CHD(ifstream &);
	void write_CHD(ofstream &);
};
struct listCHDT{
	int sldt = 0;					
	CauHoiDaThi *nodesD[MAXDATHI];
	void output_CHD(int);
	void del_allCHD();
	void add_data(int limit, int arr[], int ans[]);
	void read_listCHD(ifstream &);
	void write_listCHD(ofstream &);
};

struct DiemThi{
	string maMonHoc;
	float diem;
	listCHDT CHDT;
	void outputD(int x, int y);
	void read_Diem(ifstream &file);
	void write_Diem(ofstream &file);
};
// Khoi tao danh sach diem thi (danh sach lien ket don)
struct nodeDiemThi{
	DiemThi dt;
	struct nodeDiemThi *dnext;
};
typedef struct nodeDiemThi *NODEDIEM; /// + ///

struct listDiemThi
{
	int sldiem = 0;
	NODEDIEM dLast = NULL;
	NODEDIEM dFirst = NULL;
	void Add_Diem(DiemThi a);
	void insert_Diem(string id, float diem, int arr[], int ans[], int limit);
	void show_Diem(int x, int y, string maMonHoc);
	DiemThi* find_Diem(string maMH);
	void del_allDiem();
	void read_listDiem(ifstream &file);
	void write_listDiem(ofstream &file);
};
typedef struct listDiemThi *LISTDIEM;

////////////////////SINH VIEN////////////////////
struct SinhVien{
	string maSV;
	string Ho;
	string Ten;
	bool phai;
	string password;
	LISTDIEM FirstDiem = new listDiemThi;
	bool sexs_SV();
	void password_in(int x, int y, int width, string &pass);
	bool insert_SV();
	void sex_SV(bool x);
	void output_SV(int x, int y);
	void read_SV(ifstream &);
	void write_SV(ofstream &);
	void show_Diemsv(int x, int y, string maMH);
};
// Khoi tao danh sach lien ket don sinh vien
struct nodeSinhVien{
	SinhVien sv;
	struct nodeSinhVien *svnext;
};
typedef struct nodeSinhVien *NODESV;
struct listSinhVien
{
	int slsv = 0;
	NODESV svLast = NULL;
	NODESV svFirst = NULL;
	void outputlist_SV(int);
//	void AddHead_SV(SinhVien sv);
	void AddTail_SV(SinhVien sv);
	SinhVien *find(string);
	SinhVien *find_tt(int k);
	void del_SV(int);
	void delall_SV();
	void read_listSV(ifstream &);
	void write_listSV(ofstream &);
	void showlist_Diem(string maMH, int);
};
typedef struct listSinhVien *LISTSV;
//////////////////lop////////////
struct Lop{
	string maLop;
	string tenLop;
	LISTSV Firstsv = new listSinhVien;
	bool insertinfo_Lop();
	void read_Lop(ifstream &);
	void write_Lop(ofstream &);
};

// khai bao mang con tro lop
struct listLop{
	int slLop = 0;
	Lop *nodesL[MAXLOP];
	void insert_Lop();
	void output_Lop(int);
	int select_Lop(int chon);
	bool find_Lop(string);
	void del_Lop(int vitri);
	void free_listLop();
	void add_SV(int);
	bool find_SV(string);
	void write_listLop();
	void read_listLop();
	
};
///////////////////////CAU HOI////////
struct CauHoi{
	int id;
	string maMonHoc;
	string noiDung;
	string A;
	string B;
	string C;
	string D;
	int dapAn;
	int select_DA();
	bool inputCH(int, int, string, int);
	void show_EXAM(int );
	void write_CH(ofstream &file);
	void read_CH(ifstream &file);
};
struct listCauHoi{
	int slch = 0;
	CauHoi *nodesCH[MAXCAUHOI];	
		//void dapan(int a);
	void DA_CauHoi(int);
	void insert_CH(string);
	void output_CH(int, string);
	void sort_CH();
	CauHoi *find_CH(int);
	int count_CH(string maMH);
	void write_listCauHoi();
	void read_listCauHoi();
	void output1_CH(int, string);
	void del_CauHoi(int, string);
	void free_CH();
};
typedef struct listCauHoi LISTCH;
//////////////////DE THI/////
struct DeThi
{
	string maDe;
	int socau;
	int thoigian;	
	bool insert_DE();
	void output_DE(int, int);
	void read_DE(ifstream &);
	void write_DE(ofstream &);
};
struct nodeDeThi
{
	DeThi de;
	struct nodeDeThi *denext;
};
typedef struct nodeDeThi *NODEDE;
struct listDeThi
{
	int slde = 0;
	NODEDE deFirst = NULL;
	NODEDE deLast = NULL;
	void AddTail_DE(DeThi);
	void insertlist_DE(int);
	bool find_DE(DeThi a);
	DeThi* find_Num(int);
	void del_DE(int k);
	void delall_DE();
	void outputlist_DE(int);
	void read_listDE(ifstream &);
	void write_listDE(ofstream &);
};

////////MON HOC/////
struct MonHoc{
	string maMonHoc;
	string tenMonHoc;
	listDeThi DE;
	bool input_MH();
	void output_MH(int x, int y);
	void output_DiemMH(int x, int y);
	void read_MH(ifstream &file);
	void write_MH(ofstream &file);
};
// Khoi tao cay nhi phan Mon Hoc
struct nodeMonHoc{
	nodeMonHoc(MonHoc a){
		MH = a;
		left = NULL;
		right = NULL;
	}
	MonHoc MH;     	
	nodeMonHoc *left;
	nodeMonHoc *right;
};
typedef struct nodeMonHoc *NODEMH;
struct listMonHoc
{
	int slmh = 0;
	NODEMH root = NULL;
//	void LNR(NODEMH &t);
	void LNRkodequy(int);
	NODEMH CreateNode(MonHoc a);
	NODEMH FindInsert(MonHoc a);
	bool InsertNode(MonHoc a);
	NODEMH SearchNode_Re(NODEMH p, string);
	void add_MH();
	void change_MH(MonHoc *);
	void Free_listMH(NODEMH & );
	void read_listMH();
	void write_listMH();
	string tree_to_arr(int);
	void del_MH(string,  NODEMH &p);
};
//////////////////////////////////THOI GIAN//////
struct Timer{
    clock_t begin;
    int timeout;
 
    Timer(int timeout) : begin(clock()), timeout(timeout){}
 
    bool timeOut(){
        return getElapseTime() >= timeout;
    }
 
    int getElapseTime(){
        return (clock() - begin) / CLOCKS_PER_SEC;
    }
 
    string getTimeLeft(){
        int left = timeout - getElapseTime();
        int h = left / 3600;
        int m =  (left - h * 3600) / 60;
        int s = left % 60;     
        string ch = to_string(h);
		if(ch.length() == 1) ch = '0' + ch;
		string cm = to_string(m);
		if(cm.length() == 1) cm = '0' + cm;
		string cs = to_string(s);
		if(cs.length() == 1) cs = '0' + cs;
		if(left < 60) SetColor(RED);
		return ch + ':' + cm + ':' + cs;

    }
};
#endif
