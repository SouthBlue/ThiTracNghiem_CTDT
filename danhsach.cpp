#include "danhsach.h"
int xmh = 7, ymh = 15;
///////////////////////lop//////////
bool Lop::insertinfo_Lop()
{
	int x = 108, y= 12;
	mauChu(x, y, RED, "-----THEM LOP-----");
	gotoxy(x, y + 1);
	cout << "Nhap vao ma lop: ";
	input_check(x + 17, y + 1, 15, 15, maLop, 1);
	gotoxy(x, y + 2);
	cout << "Nhap vao ten lop: ";
	input_check(x + 18, y + 2, 50, 17, tenLop, 0);
	if(maLop == "" || tenLop == "")
	{
		return 0;
	}
	else{
		return 1;
	}

}
void Lop::read_Lop(ifstream &fl)
{
	fl.ignore();
	getline(fl, maLop, '@');
	fl.ignore();
	getline(fl, tenLop, '@');
	Firstsv->read_listSV(fl);
}
void Lop::write_Lop(ofstream &fl)
{
	fl << maLop <<"@ ";
	fl << tenLop <<"@ ";
	Firstsv->write_listSV(fl);
}
bool listLop::find_Lop(string ma)
{
	for(int i = 0; i < slLop; i++)
	{
		if(ma.compare(nodesL[i]->maLop) ==0)
		{
			return 1;
		}
	}
	return 0;
}
void listLop::insert_Lop()
{
	Nocursortype(1);
	if(slLop > MAXLOP)
	{
		mauChu(113, 4, YELLOW, "DANH SACH LOP DA DAY!");
		Nocursortype(0);
		return;
	}
	nodesL[slLop] = new Lop;
	bool e = nodesL[slLop]->insertinfo_Lop();
	if(find_Lop(nodesL[slLop]->maLop))
	{
		mauChu(113, 4, YELLOW, "MA LOP DA TON TAI!");
		Nocursortype(0);
		return;
	}
	else
	{
		if(e)
		{
			slLop++;
			mauChu(113, 4, YELLOW, "THEM LOP THANH CONG!");	
		}
		else
		{
			mauChu(113, 4, YELLOW, "THEM LOP KHONG THANH CONG!");	
		}
	}
	Nocursortype(0);
}
void listLop::output_Lop(int page)
{
	
	int x = 7, y = 15;
	table_LOP();
	gotoxy(x, y - 3);
	cout << "So luong lop: " << slLop <<"/200";
	if(slLop <= 0)
	{
		gotoxy(x + 20, y + 1);
		cout << "Danh sach lop hoc trong!";
		return;
	}
	for (int i = 20*(page - 1); i < page*20 && i < slLop; i ++)
	{
		 gotoxy(x, y);	
		 cout << nodesL[i]->maLop;
		 gotoxy(x + 30, y );
		 cout << nodesL[i]->tenLop;
		 gotoxy(x + 62, y);
		 cout << nodesL[i]->Firstsv->slsv;
		x = 7;
		y++; 
	}
	gotoxy(94, 35); cout << "trang: " << page;
}
void listLop::del_Lop(int vitri)
{
	nodesL[vitri]->Firstsv->delall_SV();
	for(int i = vitri; i < slLop; i++)
	{
		nodesL[i] = nodesL[i + 1];	
	}
	delete nodesL[slLop];
	slLop--;
}
bool listLop::find_SV(string ma)
{
	SinhVien *find;
	for(int i = 0; i < slLop; i++)
	{
		find = nodesL[i]->Firstsv->find(ma);
		if(find != NULL) return 1;
	}
	return 0;
}
void listLop::add_SV(int l)
{
	SinhVien a;
	bool t = a.insert_SV();
	if(find_SV(a.maSV))
	{
		mauChu(113, 4, YELLOW, "MA SINH VIEN DA TON TAI!");
		Nocursortype(0);
		return;
	}else{
		if(t)
		{
			nodesL[l]->Firstsv->AddTail_SV(a);	
			nodesL[l]->Firstsv->slsv++;
			mauChu(116, 4, YELLOW, "THEM THANH CONG!");
		}
		else{
			mauChu(113, 4, YELLOW, "THEM KHONG THANH CONG!");
			Nocursortype(0);
			return;
		}
	}
	
}
void listLop::free_listLop()
{
	
	for(int i = 0; i < slLop; i++)
	{
		nodesL[i]->Firstsv->delall_SV();
		delete nodesL[i];	
	}
	slLop = 0;
}
void listLop::write_listLop()
{
	ofstream fl("DSlop.txt");
	fl << slLop << "\n";
	for(int i = 0; i < slLop; i++)
	{
		nodesL[i]->write_Lop(fl);
	}
	fl.close();
}
void listLop::read_listLop()
{
	ifstream fl("DSlop.txt");
	fl >> slLop;
	for(int i = 0; i < slLop; i++)
	{
		nodesL[i] = new Lop;
		nodesL[i]->read_Lop(fl);

	}
	fl.close();
}

///////////////////////sinh vien.///////
//void listSinhVien::listAddHead_SV(NODESV *p)
//{
//   if (svFirst == NULL) 
//      svFirst  = svLast = p;
//   else
//   {
//      p->svnext = svFirst; 
//      svFirst = p; 
//   }
//}
void listSinhVien::AddTail_SV(SinhVien a)
{
	NODESV p = new nodeSinhVien;
	p->sv = a;
	p->svnext = NULL;
   if (svFirst == NULL) 
    	svFirst  = svLast = p;
   else
   {
      	svLast->svnext = p;
      	svLast = p;
   }
}
bool SinhVien::sexs_SV()
{
	string s[2] = {" nam ", " nu "};
	bool chon = true;
	for(int i = 0; i < 2; i++)
	{
		mauChu(120 + i*10, 16, RED, s[i]);
	}
	HighLight();
	mauChu(120, 16, RED, s[0]);
	char key;
	do{
		key = getch();
		if(key == 0) key= getch();
		switch (key){
			case LEFT: 
				    chon = true;
					Normal();
	              	mauChu(120 + 10, 16, RED, s[1]);	
	              	HighLight();
	              	mauChu(120, 16, RED, s[0]);
				break;
			case RIGHT:
				    chon = false;
					Normal();
	              	mauChu(120, 16, RED, s[0]);
	              	HighLight();
	              	mauChu(120 + 10, 16, RED, s[1]);
				break;
			case ENTER:
				 	SetBGColor(BLACK);
					return chon;
		}
	} while(1);

}
void SinhVien::password_in(int x, int y, int width, string &pass)
 {
 	int a = 0, b = 0;
	char key;
	string result;
	while(1)
	{
		key = getch();
		if (key==0) key = getch();
		switch(key)
		{
			case ENTER :
				pass = result;
				return;
			case SPACE :
				break;
			case BACKSPACE :
				if(result.size() != 0) 
				{
					if(a == 0) 
					{
						b--;
						a = width;
					}
					result.pop_back();
					a--;
					gotoxy(x + a, y + b); 
					cout << " ";
					gotoxy(x + a, y + b); 
				}	
				break;
			default:				
					if(result.length() != width)
					{	
						result.push_back(key);	
						gotoxy(x + a++, y + b);
						cout << key;
						if(a == width){			
							a = 0;
							b++;	
						}
					}
				break;	
		}
	}
 }
bool SinhVien::insert_SV()
{
	Nocursortype(1);
	int x = 108, y = 12; 
	fflush(stdin);
	mauChu(x, y, RED, "----Them sinh vien----");
	gotoxy(x, y + 1);
	cout << "Nhap ma sinh vien: ";
	input_check(127, y + 1, 10, 10, maSV, 1);
	gotoxy(x, y + 2);
	cout << "Nhap Ho: ";
	input_check(117, y + 2, 25, 25, Ho, 0);
	gotoxy(x, y + 3);
	cout << "Nhap Ten: ";
	input_check(118, y + 3, 15, 15, Ten, 0);
	gotoxy(x, y + 4);
	cout << "Phai: ";
	Nocursortype(0);
	phai = sexs_SV();
	Nocursortype(1);
	gotoxy(x, y + 5);
	cout << "Password: ";
	password_in(x + 10, y + 5, 16, password);
	Nocursortype(0);
	if(maSV == "" || Ho == "" || Ten == "" || password == "")
	{
		return 0;
	}
	else  return 1;
}
void SinhVien::sex_SV(bool x)
{
	if(x == 1)
	{
		cout << "nam";
	}
	else cout << "nu";
}
void SinhVien::output_SV(int x, int y)
{
	gotoxy(x, y);
	cout << maSV;
	gotoxy(x + 25, y);
	cout << Ho;
	gotoxy(x + 59, y);
	cout << Ten;
	gotoxy(x + 86, y);
	sex_SV(phai);
}
void listSinhVien::outputlist_SV(int page)
{
	int x = 7, y = 15;
	gotoxy(x, y - 2); 
	cout << "So sinh vien: " << slsv;
	table_SV();
	guide_SV();
	if(slsv == 0)
	{
		gotoxy(x + 27, y + 2);
		cout << "Danh sach sinh vien trong!";
		return;
	}
	int i = 0;
	for(NODESV p = svFirst; p != NULL; p = p->svnext)
	{
		if(20*(page - 1) <= i && i < (page*20) && i < slsv)
		{
			p->sv.output_SV(x, y);
			y++;
		}
		
		i++;
	}
	gotoxy(94, 35); cout << "trang: " << page;
}
SinhVien *listSinhVien::find(string masv)
{
	NODESV p = svFirst;
	while(p != NULL)
	{
		if(masv.compare(p->sv.maSV ) == 0)
		{
			return &p->sv;
		}
		p = p->svnext;
	}
	return NULL;
}
SinhVien *listSinhVien::find_tt(int k)
{
	NODESV p = svFirst;
	int count = 0;
	while(p != NULL)
	{
		if(count >= k)
			return &p->sv;
		count++;
		p = p->svnext;
	}
	return NULL;
}
void listSinhVien::del_SV(int k)
{
	NODESV p = svFirst;
	int count = 0;
	if (k==0)
	{
		svFirst = p->svnext;
		p->sv.FirstDiem->del_allDiem();
		delete p;
		slsv--;
		return;
	}
	else
	  	while ((count + 1 < k)&&(p != NULL))
	  	{
		   p = p->svnext;
		   count++;
	 	}
	
	if (p==NULL) return;
	if (p->svnext == NULL) return;	
	else
	{
	    NODESV pLink = p->svnext->svnext;
	    NODESV pDelete = p->svnext; 
	    p->svnext = pLink;
	    pDelete->sv.FirstDiem->del_allDiem();
	    delete pDelete;
	    slsv--;
	}
} 
void listSinhVien::delall_SV()
{
	NODESV p;
	while(svFirst != NULL)
	{
		p = svFirst;
		svFirst = svFirst->svnext;
		p->sv.FirstDiem->del_allDiem();
		delete p;
	}
	slsv = 0;
}
void SinhVien::read_SV(ifstream &fsv)
{	
	fsv.ignore();
	getline(fsv, maSV, '@');
	fsv.ignore();
	getline(fsv, Ho, '@');
	fsv.ignore();
	getline(fsv, Ten, '@');
	fsv.ignore();
	getline(fsv, password, ' ');
	fsv >> phai ;
	FirstDiem->read_listDiem(fsv);
}
void SinhVien::write_SV(ofstream &fsv)
{
	fsv << maSV << "@ ";
	fsv << Ho << "@ ";
	fsv << Ten << "@ ";
	fsv << password << ' ';
	fsv << phai << ' ';
	FirstDiem->write_listDiem(fsv);
}
void listSinhVien::read_listSV(ifstream &fsv)
{
	fsv >> slsv;
	for(int i = 0; i < slsv; i++){
		SinhVien sv;
		sv.read_SV(fsv);		
		AddTail_SV(sv);
	}
}
void listSinhVien::write_listSV(ofstream &fsv)
{
	fsv << slsv << "\n";
	NODESV p = svFirst;
	for(int i = 0; i < slsv; i++)
	{
		p->sv.write_SV(fsv);
		p = p->svnext;
	}
}
void SinhVien::show_Diemsv(int x, int y, string maMH)
{
	SetBGColor(BLACK);
	gotoxy(x , y);
	cout << maSV;
	gotoxy(x + 30, y);
	cout << Ho << " " << Ten;
	FirstDiem->show_Diem(x + 83, y, maMH);
}
void listSinhVien::showlist_Diem(string maMH, int page)
{
	int x = 7, y = 15;
	table_Diem();
	gotoxy(x + 70, y - 2); 
	cout << "So sinh vien: " << slsv;
	if(slsv == 0)
	{
		gotoxy(x + 27, y + 2);
		cout << "Danh sach sinh vien trong!";
		return;
	}
	int i = 0;
	for(NODESV p = svFirst; p != NULL; p = p->svnext)
	{
		if(20*(page - 1) <= i && i < (page*20) && i < slsv)
		{
			p->sv.show_Diemsv(x, y, maMH);
			y++;
		}
		i++;
	}
	gotoxy(94, 35); cout << "trang: " << page;
}
/////////////////////////////////DIEM//////////////
void DiemThi::outputD(int x, int y)
{
	gotoxy(x, y);
	cout << ceilf(diem * 100) / 100;
}
void DiemThi::read_Diem(ifstream &file)
{
	file.ignore();
	getline(file, maMonHoc, '@');
	file.ignore();
	file >> diem;
	CHDT.read_listCHD(file);
}
void DiemThi::write_Diem(ofstream &file)
{
	file << maMonHoc << "@ " << diem <<' ';
	CHDT.write_listCHD(file);
}
void listDiemThi::Add_Diem(DiemThi a)
{
	NODEDIEM p = new nodeDiemThi;
	p->dt = a;
	p->dnext = NULL;
   if (dFirst == NULL) 
    	dFirst   = dLast = p;
   else
   {
      	dLast->dnext = p;
      	dLast = p;
   }
}
void listDiemThi::insert_Diem(string id, float diem, int arr[], int ans[], int limit)
{
	DiemThi data;
	data.maMonHoc = id;
	data.diem = diem;
	data.CHDT.add_data(limit, arr, ans);
	Add_Diem(data);
	sldiem++;
}
void listDiemThi::show_Diem(int x, int y, string maMH)
{

	NODEDIEM p = dFirst;
	while(p != NULL)
	{   
		if((p->dt.maMonHoc.compare(maMH)) == 0)
		{
			p->dt.outputD(x, y);
			return;
		}
		p = p->dnext; 
	}
	gotoxy(x , y);
	cout << "Chua thi";
}
DiemThi* listDiemThi::find_Diem(string maMH)
{
	NODEDIEM p = dFirst;
	while(p != NULL)
	{
		if(p->dt.maMonHoc.compare(maMH) == 0)
		{
			return &p->dt;
		}
		p = p->dnext;
	}
	return NULL;
}
void listDiemThi::del_allDiem()
{
	NODEDIEM p;
	while(dFirst != NULL)
	{
		p = dFirst;
		dFirst = dFirst->dnext;
		p->dt.CHDT.del_allCHD();
		delete p;
	}
	sldiem = 0;
}
void listDiemThi::read_listDiem(ifstream &file)
{
	file >> sldiem;
	for(int i = 0; i < sldiem; i++)
	{
		DiemThi a;
		a.read_Diem(file);
		Add_Diem(a);
	}
}
void listDiemThi::write_listDiem(ofstream &file)
{
	file << sldiem << "\n";
	NODEDIEM sc = dFirst;
	for(int i = 0; i < sldiem; ++i)
	{
		sc->dt.write_Diem(file);
		sc = sc->dnext;
	}
}
//////////////////////Mon Hoc//////////////
bool MonHoc::input_MH()
{ 
	int x = 108, y = 11;
	Nocursortype(1);
	mauChu(x, y, RED, "=====Them mon hoc=====");
	gotoxy(x, y + 1);
	cout << "Nhap ma mon hoc: ";
	input_check(x + 17, y + 1, 15, 15, maMonHoc, 1);
	gotoxy(x, y + 2);
	cout << "Nhap ten mon hoc: ";
	input_check(x + 18, y + 2, 50, 17, tenMonHoc, 0);
	Nocursortype(0);
	if(maMonHoc == "" || tenMonHoc == "") return 0;
	return 1;
}
void listMonHoc::add_MH(){
	MonHoc a;
	if(a.input_MH())
	{
			if(InsertNode(a)) {
			++slmh;
			mauChu(112, 6, YELLOW, "THEM MON HOC THANH CONG!");
			}
			else mauChu(114, 6, YELLOW, "MA MON HOC DA TON TAI!");		
	}
	else mauChu(110, 6, YELLOW, "THEM MON HOC KHONG THANH CONG!");
}
void MonHoc::output_MH(int x, int y)
{
	gotoxy(x, y);
	cout << maMonHoc;
	gotoxy(x + 42, y);
	cout << tenMonHoc;
}
void listMonHoc::change_MH(MonHoc *a)
{
	int x = 108, y = 11;
	Nocursortype(1);
	mauChu(x, y, RED, "=====Sua mon hoc=====");
	gotoxy(x, y + 1);
	cout << "Ma mon hoc: ";
	cout << a->maMonHoc;
	gotoxy(x, y + 2);
	cout << "Sua ten mon hoc: ";
	input_check(x + 18, y + 2, 50, 17, a->tenMonHoc, 0);
	Nocursortype(0);	
}
NODEMH listMonHoc::CreateNode(MonHoc a)
{
    NODEMH p = new nodeMonHoc(a);
    return p;
}
NODEMH listMonHoc::SearchNode_Re(NODEMH root, string ma)
{
	if (root == NULL) return NULL;
	NODEMH p = root;
	while (p != NULL)
	{
		if (p->MH.maMonHoc.compare(ma) == 0) return p;
		if (p->MH.maMonHoc.compare(ma) > 0) p = p->left;
		else p = p->right;
	}
	return NULL;
}
NODEMH listMonHoc::FindInsert(MonHoc a)
{
    if(root == NULL) return NULL;
    NODEMH p = root;
    NODEMH f = p;
    while (p != NULL)
    {
        f = p;
        if (p->MH.maMonHoc.compare(a.maMonHoc) > 0) p = p->left;
        else p = p->right;
    }        
    return f;
}
bool listMonHoc::InsertNode(MonHoc a)
{
	if(SearchNode_Re(root, a.maMonHoc) != NULL) return 0;
    NODEMH n = CreateNode(a);
    if (root == NULL)
    {
        root = n;
        return 1;
    }
    else
    {
        NODEMH f = FindInsert(a);
        if (f != NULL)
        {
            if (f->MH.maMonHoc.compare(a.maMonHoc) > 0) f->left = n;
            else f->right = n;
        }
    }
    return 1;
}

//void listMonHoc::LNR(NODEMH &t)
//{
//	table_MH();
//	gotoxy(7, 13);
//	cout << "So mon hoc: " << slmh;
//
//	if(t != NULL)
//	{
//		LNR(t->left);
//		output_MH(xmh, ymh, t->MH);
//		LNR(t->right);
//	}
//}
void listMonHoc::LNRkodequy(int page)
{
	
	int x = 7, y = 15, i=0;
	table_DiemMH();
	gotoxy(x, y - 2);
	cout << "So mon hoc: " << slmh;
	if(slmh <= 0)
	{
		gotoxy(x + 27, y + 2);
		cout << "Danh sach mon hoc trong!";
		return;
	}
	NODEMH p, f = root;
	while(f)
	{
		if(f->left == NULL)
		{
			if(20*(page - 1) <= i && i < (page*20) && i < slmh)
			{
					f->MH.output_MH(x, y);
					y++;
			}
			i++;
			f = f->right;
		}
		else
		{
			p = f->left;
			while(p->right && p->right != f)
			{
				p = p->right;
			}
			if(p->right == NULL)
			{
				p->right = f;
				f = f->left;
			}
			else
			{
				p->right = NULL;
				if(20*(page - 1) <= i && i < (page*20) && i < slmh)
				{
					f->MH.output_MH(x, y);
					y++;
				}
				i++;
				f = f->right;
			}
		}
	}
	gotoxy(94, 35); cout << "trang: " << page;
}
string listMonHoc::tree_to_arr(int a)
{
	string arr[slmh];
	NODEMH p, f = root;
	int i = 0;
	while(f)
	{
		if(f->left == NULL)
		{
			arr[i] = f->MH.maMonHoc;
			i++;
			f = f->right;
		}
		else
		{
			p = f->left;
			while(p->right && p->right != f)
			{
				p = p->right;
			}
			if(p->right == NULL)
			{
				p->right = f;
				f = f->left;
			}
			else
			{
				p->right = NULL;
				arr[i] = f->MH.maMonHoc;
				i++;
				f = f->right;
			}
		}
	}
	return arr[a];
}
void remove(NODEMH &q, NODEMH &p)
{
	if(p->left != NULL) remove(q, p->left);
	else
	{
		q->MH = p->MH;
		q = p;
		p = p->right;
	}
}
void listMonHoc::del_MH(string ma, NODEMH &t)
{
	if(t == NULL)
	return;
	if(root->left == NULL && root->right == NULL) {
		root->MH.DE.delall_DE();
 		delete root;
 		root = NULL;
 		slmh = 0;
 		return;
	}
	if(t->MH.maMonHoc.compare(ma) > 0) del_MH(ma, t->left);
	if(t->MH.maMonHoc.compare(ma) < 0) del_MH(ma, t->right);
	if(t->MH.maMonHoc.compare(ma) == 0)
	{
		NODEMH q = t;
		if(t->left == NULL) {
			t = t->right;
		}
		else if(t->right == NULL){
			t = t->left;
		}
		else remove(q, t->right);
		q->MH.DE.delall_DE();
		delete q;
		slmh--;
	}	
}
void listMonHoc::Free_listMH(NODEMH &t )
{
    if ( t != NULL ){
    	Free_listMH( t->left );
   		Free_listMH( t->right );
    	t->MH.DE.delall_DE();
    	delete t; 	
		t = NULL;	
	}
    slmh = 0;
}
void MonHoc::read_MH(ifstream &file)
{
	file.ignore();
	getline(file, maMonHoc, '@');
	file.ignore();
	getline(file, tenMonHoc, '@');
	file.ignore();
	DE.read_listDE(file);
}
void MonHoc::write_MH(ofstream &file)
{
	file << maMonHoc <<"@ ";
	file << tenMonHoc << "@" << ' ';
	DE.write_listDE(file);
}
void listMonHoc::read_listMH()
{
	ifstream file("DSmh.txt");
	file >> slmh;
	for(int i = 0; i < slmh; i++)
	{
		MonHoc a;
		a.read_MH(file);
		InsertNode(a);
	}
	file.close();
}
void listMonHoc::write_listMH()
{
	ofstream file("DSmh.txt");
	file << slmh << "\n";
	NODEMH p, f = root;
	while(f)
	{
		if(f->left == NULL)
		{
			f->MH.write_MH(file);
			f = f->right;
		}
		else
		{
			p = f->left;
			while(p->right && p->right != f)
			{
				p = p->right;
			}
			if(p->right == NULL)
			{
				p->right = f;
				f = f->left;
			}
			else
			{
				p->right = NULL;
				f->MH.write_MH(file);
				f = f->right;
			}
		}
	}
	file.close();
}
/////////////////////CAU HOI///////////////
int CauHoi::select_DA()
{
	Nocursortype(0);
	int x = 20, y = 8;
	string da[4] = {"  A  ", "  B  ", "  C  ", "  D  "};
	int chon = 0;
 	int i;
 	for ( i = 0; i < 4 ; i++){
	 	mauChu(x + 10*i, y, RED,da[i]);
 	}
	  	HighLight();
	  	mauChu(x + 10*chon, y, RED, da[chon]);
	  	char kytu;
	do {
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {
	    case LEFT :if (chon+1 >1)
	  			  {
	  		        Normal();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	              	chon --;
	              	HighLight();
	              	mauChu(x + chon*10, y, RED, da[chon]);	
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 < 4)
	  			  {
	  		        Normal();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	  			  }
	  			  break;
	  	case ENTER : 
	  				SetBGColor(BLACK);
	  				return chon + 1;
	  } 
	  } while (1);

}
bool CauHoi::inputCH(int x, int y, string maMH, int slch)
{
	maMonHoc = maMH;
	id = slch + 1;
	gotoxy(x, y);
	cout << "Nhap cau hoi: ";
	input_check(x + 14, y, 250, 86, noiDung, 0);
	gotoxy(x, y + 3);
	cout << "A: ";
	input_check(x + 2, y + 3, 80, 80, A, 0);
	gotoxy(x, y + 4);
	cout << "B: ";
	input_check(x + 2, y + 4, 80, 80, B, 0);
	gotoxy(x, y + 5);
	cout << "C: ";
	input_check(x + 2, y + 5, 80, 80, C, 0);
	gotoxy(x, y + 6);
	cout << "D: ";
	input_check(x + 2, y + 6, 80, 80, D, 0);
	gotoxy(x, y + 7);
	cout << "Dap An: ";
	dapAn = select_DA();
	if(noiDung == "" || A == "" || B == "" || C == "" || D == "")
	{
		return 0;
	}
	return 1;
}
void listCauHoi::DA_CauHoi(int x)
{
	if(x == 1)
	{
		cout << "A";
	}
	else if(x == 2)
	{
		cout << "B";
	}
	else if(x == 3)
	{
		cout << "C";
	}
	else if(x == 4)
	{
		cout << "D";
	}
}
void listCauHoi::sort_CH()
{
	for(int j = slch - 1; j > 0; j--)
	{
		if(nodesCH[j]->maMonHoc.compare(nodesCH[j-1]->maMonHoc) < 0)
		{
			CauHoi *temp = nodesCH[j];
			nodesCH[j] = nodesCH[j-1];
			nodesCH[j-1] = temp;
		}
	}
}
void listCauHoi::insert_CH(string maMH)
{
	Nocursortype(1);
	clear_screen1();
	int x = 3, y = 1;
	if(slch > MAXCAUHOI)
	{
		mauChu(113, 4, YELLOW, "DANH SACH CAU HOI DA DAY!");
		Nocursortype(0);
		return;
	}
	nodesCH[slch] = new CauHoi;
	if(nodesCH[slch]->inputCH(x, y, maMH, slch))
	{
		slch++;
		mauChu(113, 4, YELLOW, "THEM CAU HOI THANH CONG!");	
	}
	else mauChu(110, 4, YELLOW, "THEM CAU HOI KHONG THANH CONG!");	
	Nocursortype(0);
}
CauHoi *listCauHoi::find_CH(int id)
{
	for(int i = 0; i < slch ; i++)
	{
		if(id == nodesCH[i]->id)
		{
			return nodesCH[i] ;
		}
	}
	return NULL;
}
int listCauHoi::count_CH(string maMH)
{
	int  sl = 0;
	for(int i = 0; i < slch; i++) {
		if(nodesCH[i]->maMonHoc.compare(maMH) == 0)
		{
			sl++;
		}
	}
	return sl;	
}
void listCauHoi::output_CH(int page, string maMH)
{
	SetBGColor(BLACK);
	int x = 7, y = 15, j = 0 , sl = count_CH(maMH);

	table_CH();
	gotoxy(x, y - 2);	
	cout << "so luong cau hoi: " << sl;
	if(sl == 0)
	{
		gotoxy(x + 30, y + 1);
		cout << "Danh sach cau hoi trong!";
		return;
	}
	CauHoi *arrCH[sl];
	for(int i = 0; i < slch; i++)
	{
		if(nodesCH[i]->maMonHoc.compare(maMH) == 0)
		{
			arrCH[j] = nodesCH[i];
			j++;
		}
	}
	for (int i = (page-1)*20; i < page*20 && i < count_CH(maMH); i++)
	{
			gotoxy(x, y);
			cout << "CH" << arrCH[i]->id;
			gotoxy(x + 9, y);	
			string tmp;
			tmp.append(arrCH[i]->noiDung, 0, 63);
			if(arrCH[i]->noiDung.length() > 63) tmp.append("... ?");
			cout << tmp;
			gotoxy(x + 85, y);
			DA_CauHoi(arrCH[i]->dapAn);
			x = 7;
			y++; 
	}
	gotoxy(94, 35); cout << "trang: " << page;
}
void CauHoi::show_EXAM(int chon)
{
	int x = 3, y = 1;
	gotoxy(x, y);
	cout << "CH" << chon + 1 << ": ";
	show_string(noiDung, 95, x + 5, y);
	gotoxy(x, y + 3);
	cout << "A:   " << A;
	gotoxy(x, y + 4);
	cout << "B:   " << B;
	gotoxy(x, y + 5);
	cout << "C:   " << C;
	gotoxy(x, y + 6);
	cout << "D:   " << D;
}
void listCauHoi::output1_CH(int chon, string maMH)
{
	int x = 3, y = 1 , j = 0, sl = count_CH(maMH);

	CauHoi *arrCH[sl];
	for(int i = 0; i < slch; i++)
	{
		if(nodesCH[i]->maMonHoc.compare(maMH) == 0)
		{
			arrCH[j] = nodesCH[i];
			j++;
		}
	}
	gotoxy(x, y);
	cout << "CH" << arrCH[chon]->id << ": ";
	show_string(arrCH[chon]->noiDung, 93, x + 7, y);
	gotoxy(x, y + 3);
	cout << "A:   " << arrCH[chon]->A;
	gotoxy(x, y + 4);
	cout << "B:   " << arrCH[chon]->B;
	gotoxy(x, y + 5);
	cout << "C:   " << arrCH[chon]->C;
	gotoxy(x, y + 6);
	cout << "D:   " << arrCH[chon]->D;
	if(arrCH[chon]->dapAn == 1) mauChu(x + 3, y + 3, YELLOW, "#");
		else if(arrCH[chon]->dapAn == 2) 	mauChu(x + 3, y + 4, YELLOW, "#");
			else if(arrCH[chon]->dapAn == 3) mauChu(x + 3, y + 5, YELLOW, "#");		
				else if(arrCH[chon]->dapAn == 4) mauChu(x + 3, y + 6, YELLOW, "#");
}
void listCauHoi::del_CauHoi(int vitri, string maMH)
{
	for(int i = vitri; i < slch - 1; i++)
	{
		nodesCH[i]->noiDung = nodesCH[i + 1]->noiDung;
		nodesCH[i]->A = nodesCH[i + 1]->A;
		nodesCH[i]->B = nodesCH[i + 1]->B;
		nodesCH[i]->C = nodesCH[i + 1]->C;
		nodesCH[i]->D = nodesCH[i + 1]->D;
		nodesCH[i]->dapAn = nodesCH[i + 1]->dapAn;	
	}
	slch--;
}
void listCauHoi::free_CH()
{
	for(int i = 0; i < slch; i++)
	{
		delete nodesCH[i];
	}
	slch = 0;
}
void CauHoi::write_CH(ofstream &file)
{
	file << maMonHoc << '@'<< "\n";
	file << id << ' ';
	file << noiDung << '@' <<"\n";
	file << A << '@' <<"\n";
	file << B << '@' <<"\n";
	file << C << '@' <<"\n";
	file << D << "@ " << dapAn <<"\n";
}
void listCauHoi::write_listCauHoi()
{
	ofstream file("DScauhoi.txt");
	file << slch << "\n";
	if(slch == 0) return;
	for(int i = 0; i < slch; i++)
	{
		nodesCH[i]->write_CH(file);
	}
	file.close();
}
void CauHoi::read_CH(ifstream &file)
{
		file.ignore();
		getline(file, maMonHoc, '@');
		file >> id;
		file.ignore();
		getline(file, noiDung, '@');
		file.ignore();
		getline(file, A, '@');
		file.ignore();
		getline(file, B, '@');
		file.ignore();
		getline(file, C, '@');
		file.ignore();
		getline(file, D, '@');
		file >> dapAn;
}
void listCauHoi::read_listCauHoi()
{
	ifstream file("DScauhoi.txt");
	file >> slch;
	for(int i = 0; i < slch; i++)
	{
		nodesCH[i] = new CauHoi;
		nodesCH[i]->read_CH(file);
	}
	file.close();
}
/////////////////////////////DE THI/////////////////
void listDeThi::AddTail_DE(DeThi a)
{
	NODEDE p = new nodeDeThi;
	p->de = a;
	p->denext = NULL;
   	if (deFirst == NULL) 
    	deFirst  = deLast = p;
    else
   	{
      	deLast->denext = p;
      	deLast = p;
   	}
}
bool DeThi::insert_DE()
{
	int x = 108, y = 12; 
	fflush(stdin);
	mauChu(x, y, RED, "----Them de thi----");
	gotoxy(x, y + 1);
	cout << "Nhap ma de: ";
	input_check(120, y + 1, 10, 10, maDe, 1);
	fflush(stdin);
	gotoxy(x, y + 2);
	cout << "Nhap so cau: ";
	cin >> socau;
	fflush(stdin);
	gotoxy(x, y + 3);
	cout << "Nhap thoi gian: ";
	gotoxy(x + 22, y + 3);
	cout <<"phut";
	gotoxy(x + 16, y + 3);
	cin >> thoigian;
	if(maDe == "" || socau <= 0 ||socau > 100 || thoigian <= 0 )
	{
		return 0;
	}
	else  return 1;
}
bool listDeThi::find_DE(DeThi a)
{

	NODEDE p = deFirst;
	while(p != NULL)
	{
		if(a.maDe.compare(p->de.maDe ) == 0)
		{
			return 1;
		}
		p = p->denext;
	}
	return 0;
}
DeThi* listDeThi::find_Num(int n)
{
	NODEDE p = deFirst;
	int i = 0;
	while(p != NULL)
	{
		if(i == n)
		{
			return &p->de;
		}
		p = p->denext;
		i++;
	}
	return NULL;	
}
void listDeThi::insertlist_DE(int ch)
{
	Nocursortype(1);
	clear_screen5();
	DeThi a;
	bool s = a.insert_DE();
	if(a.socau > ch)
	{
		mauChu(113, 4, YELLOW, "SO LUONG CAU HOI KHONG DU!");
		Nocursortype(0);
		return;
	}
	if(find_DE(a))
	{
		mauChu(113, 4, YELLOW, "MA DE THI NAY DA TON TAI!");
		Nocursortype(0);
		return;
	}
	else
	{
		if(s)
		{
			AddTail_DE(a);	
			slde++;
			mauChu(116, 4, YELLOW, "THEM THANH CONG!");
		}
		else{
			mauChu(113, 4, YELLOW, "THEM KHONG THANH CONG!");
			Nocursortype(0);
			return;
		}
	}
	Nocursortype(0);

}
void DeThi::output_DE(int x, int y)
{
	gotoxy(x, y);
	cout << maDe;
	gotoxy(x + 38, y);
	cout << socau;
	gotoxy(x + 78, y);
	cout << thoigian;
}
void listDeThi::outputlist_DE(int page)
{
	int x = 7, y = 15;
	gotoxy(x, y - 2); 
	cout << "So de thi: " << slde;
	table_DE();
	if(slde == 0)
	{
		gotoxy(x + 27, y + 2);
		cout << "Danh sach de thi trong!";
		return;
	}
	int i = 0;
	for(NODEDE p = deFirst; p != NULL; p = p->denext) 
	{
		if(20*(page - 1) <= i && i < (page*20) && i < slde)
		{
			p->de.output_DE(x, y);
			y++;
		}
		i++;
	}
	gotoxy(94, 35); cout << "trang: " << page;
}
void listDeThi::del_DE(int k)
{
	NODEDE p = deFirst;
	int count = 0;
	if (k==0)
	{
		deFirst = p->denext;
		delete p;
		slde--;
		return;
	}
	else
	  	while ((count + 1 < k)&&(p != NULL))
	  	{
		   p = p->denext;
		   count++;
	 	}
	
	if (p==NULL) return;
	if (p->denext == NULL) return;	
	else
	{
	    NODEDE pLink = p->denext->denext;
	    NODEDE pDelete = p->denext; 
	    p->denext = pLink;
	    delete pDelete;
	    slde--;
	}
} 
void listDeThi::delall_DE()
{
	NODEDE p;
	while(deFirst != NULL)
	{
		p = deFirst;
		deFirst = deFirst->denext;
		delete p;
	}
	slde = 0;
}
void DeThi::read_DE(ifstream &file)
{	
	file.ignore();
	getline(file, maDe, '@');
	file >> socau >> thoigian;

}
void DeThi::write_DE(ofstream &file)
{
	file << maDe << "@ " << socau << ' ' << thoigian << "\n";
}
void listDeThi::read_listDE(ifstream &file)
{
	file >> slde;
	for(int i = 0; i < slde; i++){
		DeThi a;
		a.read_DE(file);
		AddTail_DE(a);
	}
}
void listDeThi::write_listDE(ofstream &file)
{
	file << slde << "\n";
	NODEDE p = deFirst;
	for(int i = 0; i < slde; i++)
	{
		p->de.write_DE(file);
		p = p->denext;
	}
}
//////////////////////////////Cau Hoi Da Thi/////////////
void CauHoiDaThi::read_CHD(ifstream &file)
{
	file >> id;
	file >> DAchon;
}
void CauHoiDaThi::write_CHD(ofstream &file)
{
	file << id << ' ' << DAchon << '\n';
}
void listCHDT::add_data(int limit, int arr[], int ans[])
{
	sldt = limit;
	cout << sldt;
	for(int i = 0; i < limit; i++)
	{
		nodesD[i] = new CauHoiDaThi;
		nodesD[i]->id = arr[i];
		nodesD[i]->DAchon = ans[i];
	}
}
void listCHDT::del_allCHD()
{
	for(int i = 0; i < sldt ;i++)
	{
		delete nodesD[i];
	}
	sldt = 0;
}
void listCHDT::read_listCHD(ifstream &file)
{
	file >> sldt;
	for(int i = 0; i < sldt; i++)
	{
		nodesD[i] = new CauHoiDaThi;
		nodesD[i]->read_CHD(file);
	}
}
void listCHDT::write_listCHD(ofstream &file)
{
	file << sldt << '\n';
	for(int i = 0; i < sldt; i++)
	{
		nodesD[i]->write_CHD(file);
	}
}
