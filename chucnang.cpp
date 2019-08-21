#include "chucnang.h"
listLop dsL;
listMonHoc tMH;
listCauHoi CH;


void begin()
{
	dsL.read_listLop();
	tMH.read_listMH();
	CH.read_listCauHoi();
}
void end()
{
	dsL.write_listLop();
	tMH.write_listMH();
	CH.write_listCauHoi();
	dsL.free_listLop();
	tMH.Free_listMH(tMH.root);
	CH.free_CH();
}
////////////////////////////GIAOVIEN///////////////////
bool thoat()
{
	Normalw();
	mauChu(114, 4, RED, "BAN CO MUON THOAT KHONG?");
	string s[2] = {" YES ", " NO "};
	Normalw();
	bool chon = true;
	for(int i = 0; i < 2; i++)
	{
		mauChu(118 + i*10, 6, RED, s[i]);
	}
	HighLight();
	mauChu(118, 6, RED, s[0]);
	Normalw();
	char key;
	while(1){
		key = getch();
		if(key == 0) key= getch();
		switch (key){
			case LEFT: 
				    chon = true;
					Normal();
	              	mauChu(118 + 10, 6, RED, s[1]);	
	              	HighLight();
	              	mauChu(118, 6, RED, s[0]);
					break;
			case RIGHT:
				    chon = false;
					Normal();
	              	mauChu(118, 6, RED, s[0]);
	              	HighLight();
	              	mauChu(118 + 10, 6, RED, s[1]);
					break;
			case ENTER:
				 	Normalw();
					return chon;
		}
	} 
}
int MenuGV(){
	system("cls");
	string td[4]= {"    LOP    ", "   CAU HOI  ", "  DE THI  ", " BANG DIEM "};
	GiaoDienGV();
	rectangle(8, 3, 15, 3, BLUE);
	rectangle(34, 3, 15, 3, BLUE);
	rectangle(58, 3, 15, 3, BLUE);
	rectangle(83, 3, 15, 3, BLUE);
	press_key();
	int chon =0;
 	int i;
 	for ( i=0; i< 4 ; i++){
	 	mauChu(cot + 25*i, dong, BLUE, td[i]);
 	}
	  	HighLight();
	  	mauChu(cot + 25*chon, dong, BLUE, td[chon]);
		Nocursortype(0);
	  	char kytu;
	while(1){
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {
	    case LEFT :if (chon+1 >1)
	  			  {
					Normal();
					mauChu(cot + chon*25, dong, BLUE, td[chon]);
					chon --;
					HighLight();
					mauChu(cot + chon*25, dong, BLUE, td[chon]);		
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 < 4)
	  			  {
	  		        Normal();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);	
	  			  }
	  			  break;
	  	case ESC : return 5;
	  	case ENTER : return chon+1;
	  } 
	  } 

}
/////////////////////////////////////////////
int up_down(int x, int y, int a, int c)
{
	if(c == 72){
	    Normal();
	  	mauChu(x, y + (a%20), BLACK, " -> ");
	  	a--;
	  	HighLight();
	  	mauChu(x, y + (a%20), BLACK, " -> ");	
  	}
  	else{
	    Normal();
	  	mauChu(x, y + (a%20), BLACK, " -> ");
	  	a++;
	  	HighLight();
	  	mauChu(x, y + (a%20), BLACK, " -> ");	
  	}
  	Normalw();
  	return a;
}
bool del_hoi()
{
	clear_screen4(); 
	mauChu(114, 4, RED, "BAN CO MUON XOA KHONG?");
	string s[2] = {" YES ", " NO "};
	bool chon = true;
	for(int i = 0; i < 2; i++)
	{
		mauChu(118 + i*10, 6, RED, s[i]);
	}
	HighLight();
	mauChu(118, 6, RED, s[0]);
	char key;
	do{
		key = getch();
		if(key == 0) key= getch();
		switch (key){
			case LEFT: 
				    chon = true;
					Normal();
	              	mauChu(118 + 10, 6, RED, s[1]);	
	              	HighLight();
	              	mauChu(118, 6, RED, s[0]);
				break;
			case RIGHT:
				    chon = false;
					Normal();
	              	mauChu(118, 6, RED, s[0]);
	              	HighLight();
	              	mauChu(118 + 10, 6, RED, s[1]);
				break;
			case ENTER:
				 	Normalw();
					return chon;
		}
	} while(1);

}
void select_Lop(int chon)
{
	int x = 1, y = 15 , page = 1;
	clear_screen2();
	clear_screen1();
	char kytu;
	while(1)
	{
		dsL.output_Lop(page);
		if(dsL.slLop > 0){
			HighLight();
			mauChu(x, y + (chon % 20), BLACK, " -> ");
			Normalw(); 
		}
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :if(chon > 0 && chon > (page - 1)*20)  chon = up_down(x, y, chon, UP);
	  			  break;
	  	case DOWN :if(chon + 1 <dsL.slLop && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
					break;
		case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page*20 < dsL.slLop) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case ESC :	SetBGColor(BLACK);
					return giao_vien();
		case INSERT : 	clear_screen5();
						clear_screen4();
						Normalw();
						dsL.insert_Lop();
						clear_screen2();
						break;
		case DEL :		
						clear_screen5();				
						if(dsL.slLop <= 0)break;
						else{
							bool e = del_hoi();
							if(e){
								clear_screen4();
								clear_screen2();
								Normalw();
								if(chon % 20 == 0 ){
									dsL.del_Lop(chon);
									if(page>1 && dsL.slLop % 20 == 0){
										chon--;
										page--;
									}
								}
								else{
									dsL.del_Lop(chon);
									chon--;
								}							
							}
							else 
							{
								clear_screen4();
							}
					}	
					break;
		case HOME : system("cls");
					SetBGColor(BLACK);
					return giao_vien();
	  	case ENTER :if(dsL.slLop <= 0)
	  					break;
	  				else
						return select_SV(chon, 0, 1);
	 	} 
	} 
}
////////////////////////////////

void select_SV(int a, int b, int page)
{
	clear_screen2();
	clear_screen3();
	Normalw();
	int x = 1, y = 15, number;
	char kytu;
	bool e;
	while(1){
		number = dsL.nodesL[a]->Firstsv->slsv;
		dsL.nodesL[a]->Firstsv->outputlist_SV(page);
		if( number > 0){
			HighLight();
			mauChu(x, y + (b % 20), BLACK, " -> ");
			Normalw();
		}
		gotoxy(x + 6, y - 3); cout << "Lop: " << dsL.nodesL[a]->maLop << "          Ten lop: " << dsL.nodesL[a]->maLop;
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {
	    case UP :
				if (b > 0 && b > (page-1)*20) b = up_down(x, y, b, UP);
	  			break;
	  	case DOWN :
		  		if (b + 1 < number && b < (page*20) - 1) b = up_down(x, y, b, DOWN);
	  			break;
	  	case LEFT : if(page > 1) {
						page--;
						b = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page*20 < number ) 
					{
						page++;
						b = (page-1)*20;
						clear_screen2();
					}		
					break;
		case ESC :	
				clear_screen2();
				clear_screen4();
				SetBGColor(BLACK);
				dsL.write_listLop();
				return select_Lop(a);
		case INSERT : 	
					clear_screen4();
					clear_screen5();
					Normalw();
					dsL.add_SV(a);
					clear_screen2();
					clear_screen5();
					break;
		case DEL :	
					if(number <= 0)
							break;
						else{
							if(del_hoi()){
								clear_screen4();
								clear_screen2();
								if(b%20 == 0 ){
									dsL.nodesL[a]->Firstsv->del_SV(b);
									if(page>1 && dsL.nodesL[a]->Firstsv->slsv % 20 == 0){
										b--;
										page--;
									}
								}
								else{
									dsL.nodesL[a]->Firstsv->del_SV(b);
									b--;
								}						
								break;
							}
							else 
							{	
								clear_screen4();
							}
						}
					break;
		case HOME : return giao_vien();
	  } 
	  }
}
///////////////////Mon Hoc//////////
void select_MH(int chon)
{
	int x = 1, page = chon/20 + 1 , y = 15;
	clear_screen1();
	clear_screen3();
	guide_MH();
	string selected;
	MonHoc *a;
	char kytu;
	while(1)
	{
		if(tMH.slmh > 0){
		HighLight();
		mauChu(x, y + (chon % 20), BLACK, " -> ");
		}
		Normalw();
		tMH.LNRkodequy(page);
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :
			if (chon > 0 && chon > (page - 1)*20) chon = up_down(x, y, chon, UP);
	  		break;
	  	case DOWN :
		  	if (chon + 1 <tMH.slmh && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
	  		break;
	  	case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page*20 < tMH.slmh ) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}		
					break;
		case ESC :	system("cls");
					SetBGColor(BLACK);
					return giao_vien();
		case INSERT : 	clear_screen5();
						clear_screen4();
						Normalw();
						tMH.add_MH();
						clear_screen2();
						clear_screen5();
						break;
		case DEL :	
					clear_screen5();
									
					if(tMH.slmh <= 0)
							break;
					else{
						selected = tMH.tree_to_arr(chon);
						if(del_hoi()){
							clear_screen4();
							clear_screen2();
							Normalw();
							if(chon == 0 ){
								tMH.del_MH(selected, tMH.root);
							}
							else{		
								tMH.del_MH(selected, tMH.root);
								chon--;
							}							
						}
						else 
						{
							clear_screen4();
						}
					}	
					break;
		case EDIT: 
					clear_screen5();
					selected = tMH.tree_to_arr(chon);
					a = &tMH.SearchNode_Re(tMH.root, selected)->MH;
					tMH.change_MH(a);
					clear_screen2();
					break;
		case HOME : return giao_vien();
	  	case ENTER :	if(tMH.slmh <= 0) break;
		  				selected = tMH.tree_to_arr(chon);								  	// lnr mangMH[]; chon -> maMH;											
		  				a = &tMH.SearchNode_Re(tMH.root, selected)->MH;				// MonHoc *a = search(maMH);
		  			 	return select_CauHoi(0, chon, a, 1);
		case F1: tMH.Free_listMH(tMH.root);
				clear_screen2();
				break;
	 	} 
	} 
}
void select_CauHoi(int chon, int b, MonHoc *&a, int page)
{
	clear_screen2();
	clear_screen3();
	clear_screen4();
	guide_CH();
	int x = 1, y = 15;
	char kytu;
	while(1) {
		CH.output_CH(page, a->maMonHoc);
		int number = CH.count_CH(a->maMonHoc);
		if( number > 0){
			HighLight();
			mauChu(x, y + (chon % 20), BLACK, " -> ");
		}
		Normalw();
		gotoxy(x + 6, y - 3); cout << "Ma mon hoc: " << a->maMonHoc << "          Ten mon hoc: " << a->tenMonHoc;
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {
	    case UP :if (chon > 0 && chon > (page-1)*20) chon = up_down(x, y, chon, UP);
	    		clear_screen1();
	  			  break;
	  	case DOWN :if (chon + 1 < number && chon < (page*20) - 1)  chon = up_down(x, y, chon, DOWN);
	  				clear_screen1();
	  			  break;
	  	case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page *20 < number) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}	
					break;
		case ESC :
					clear_screen1();
					clear_screen2(); 
					clear_screen4();
					SetBGColor(BLACK);
					CH.write_listCauHoi();
					return select_MH(b);
		case INSERT : 
						clear_screen4();
						Normalw();
						CH.insert_CH(a->maMonHoc);
						CH.sort_CH();
						break;
		case HOME : return giao_vien();
	  	case ENTER  : 	if(number <= 0) break;
	  					else{
							clear_screen1();
		  					CH.output1_CH(chon, a->maMonHoc);
							break; 
						}

	  } 
	  }
}
void select_DiemMH(int chon)
{
	clear_screen2();
	clear_screen1();
	guide_Diem();
	int x = 1, y = 15, page = chon/20 + 1;
	string selected;
	MonHoc *a;
	char kytu;
	while(1)
	{
		if(tMH.slmh > 0){
		HighLight();
		mauChu(x, y + (chon % 20), BLACK, " -> ");
		}
		Normalw();
		tMH.LNRkodequy(page);
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :
			if (chon > 0 && chon > (page - 1)*20) chon = up_down(x, y, chon, UP);
	  		break;
	  	case DOWN :
		  	if (chon + 1 <tMH.slmh && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
	  		break;
	  	case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page*20 < tMH.slmh ) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}		
					break;
		case ESC :	system("cls");
					SetBGColor(BLACK);
					return giao_vien();
		case HOME : return giao_vien();
	  	case ENTER :	
		  				selected = tMH.tree_to_arr(chon);								  											
		  				a = &tMH.SearchNode_Re(tMH.root, selected)->MH;			
		  			 	return select_DiemLop(0, a, 1);
	 	} 
	} 
}
void select_DiemLop(int chon, MonHoc *a, int page)
{
	clear_screen2();
	int x = 1, y = 15;
	char kytu;
	while(1)
	{
		dsL.output_Lop(page);
		if(dsL.slLop > 0){
			HighLight();
			mauChu(x, y + (chon % 20), BLACK, " -> ");
			Normalw(); 
		}
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :if(chon > 0 && chon > (page-1)*20)  chon = up_down(x, y, chon, UP);
	  			  break;
	  	case DOWN :if(chon + 1 <dsL.slLop && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
					break;
		case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page *20 < dsL.slLop) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}		
					break;
		case ESC :
					return select_DiemMH(0);
		case HOME : system("cls");
					SetBGColor(BLACK);
					return giao_vien();
	  	case ENTER : 
					return select_Diem(0, chon, a, 1);
	 	} 
	} 
}
void select_Diem(int b, int nl, MonHoc *a, int page)
{
	clear_screen2();
	int x = 1, y = 15, number;
	char kytu;
	SinhVien *sv;
	while(1)
	{
		number = dsL.nodesL[nl]->Firstsv->slsv;
		gotoxy(x + 6, y - 3); cout << "Ma mon hoc: " << a->maMonHoc << "          Ten mon hoc: " << a->tenMonHoc;
		gotoxy(x + 6, y - 2); cout << "Ma lop: " << dsL.nodesL[nl]->maLop << "              Ten Lop: " << dsL.nodesL[nl]->tenLop;
		dsL.nodesL[nl]->Firstsv->showlist_Diem(a->maMonHoc, page);
		if(number > 0){
			HighLight();
			mauChu(x, y + (b % 20), BLACK, " -> ");
			Normalw(); 
		}
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP : clear_screen4();
				if (b > 0 && b > (page-1)*20) b = up_down(x, y, b, UP);
	  			break;
	  	case DOWN :clear_screen4();
		  		if (b + 1 < number && b < (page*20) - 1) b = up_down(x, y, b, DOWN);
	  			break;
	  	case LEFT : if(page > 1) {
						page--;
						b = (page-1)*20;
						clear_screen2();
						clear_screen4();
					}
					break;
		case RIGHT: if(page *20 < number ) 
					{
						page++;
						b = (page-1)*20;
						clear_screen2();
						clear_screen4();
					}
					break;
		case ESC :	clear_screen4();
					return select_DiemLop(0, a, 1);
		case HOME : system("cls");
					SetBGColor(BLACK);
					return giao_vien();
	  	case ENTER : 
	  				if(dsL.nodesL[nl]->Firstsv->slsv <= 0) break;
	  				else{
		  				sv = dsL.nodesL[nl]->Firstsv->find_tt(b);
		  				
		  				if(sv->FirstDiem->find_Diem(a->maMonHoc) == NULL)
		  				{
		  					mauChu(112, 5, YELLOW, "SINH VIEN NAY CHUA THI!");
		  					break;
						}
						else{
								return show_CHD(sv, a, nl);
						}
					}

	 	} 
	} 
}
void show_listCHD(int x, int y, CauHoi *arr[], int ans[], int num, int page)
{	
	table_CHD();
	for(int i = (page-1)*20; i < page*20 && i < num; i++)
	{
		gotoxy(x, y);
		cout << "Cau " << i+1 <<':';
		gotoxy(x + 8, y);
		string tmp;
		tmp.append(arr[i]->noiDung, 0, 58);
		if(arr[i]->noiDung.length() > 58) tmp.append("... ?");
		cout << tmp;
		gotoxy(x + 78, y);
		if(arr[i]->dapAn == 1) cout << "A";
			else if(arr[i]->dapAn == 2) cout << "B";
				else if(arr[i]->dapAn == 3) cout << "C";
					else if(arr[i]->dapAn == 4) cout << "D";
		gotoxy(x + 91, y); 
		if(ans[i] == 0) cout << "Chua chon";
		else if(ans[i] == 1) cout << "A";
			else if(ans[i] == 2) cout << "B";
				else if(ans[i] == 3) cout << "C";
					else if(ans[i] == 4) cout << "D";
		y++;
	}
	gotoxy(94, 35); cout << "trang: " << page;
}
void show_CHD(SinhVien *sv, MonHoc* a, int nl)
{
	
	clear_screen2();
	DiemThi *dt = sv->FirstDiem->find_Diem(a->maMonHoc);
	int x = 3, y = 15 ,chon = 0, page = 1, num = dt->CHDT.sldt;
	CauHoi *arr[num];
	int ans[num];
	for(int i = 0; i < num; i++)
	{
		arr[i] = CH.find_CH(dt->CHDT.nodesD[i]->id);
		ans[i] = dt->CHDT.nodesD[i]->DAchon;
	}
	char kytu;
	while(1)
	{
		show_listCHD(x + 4, y, arr, ans, dt->CHDT.sldt, page);
		if(num > 0){
			HighLight();
			mauChu(x, y + (chon % 20), BLACK, " -> ");
			Normalw(); 
		}
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :if(chon > 0 && chon > (page-1)*20)  chon = up_down(x, y, chon, UP);
	  			  break;
	  	case DOWN :if(chon + 1 < num && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
					break;
		case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page*20 < num) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}		
					break;
		case ESC :	clear_screen1();
					return select_Diem(0, nl, a, 1);
		case HOME : system("cls");
					SetBGColor(BLACK);
					return giao_vien();
	  	case ENTER : 
	  				clear_screen1();
					arr[chon]->show_EXAM(chon);
					break;
	 	} 
	} 
}
void select_MHDE(int chon)
{
	clear_screen2();
	clear_screen1();
	clear_screen3();
	clear_screen4();
	guide_Diem();
	int x = 1, y = 15, page = chon/20 + 1;
	string selected;
	MonHoc *a;
	char kytu;
	while(1)
	{
		if(tMH.slmh > 0){
		HighLight();
		mauChu(x, y + (chon % 20), BLACK, " -> ");
		}
		Normalw();
		tMH.LNRkodequy(page);
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :
			if (chon > 0 && chon > (page - 1)*20) chon = up_down(x, y, chon, UP);
	  		break;
	  	case DOWN :
		  	if (chon + 1 <tMH.slmh && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
	  		break;
	  	case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page*20 < tMH.slmh ) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}		
					break;
		case ESC :	return giao_vien();
		case HOME: 	return giao_vien();
	  	case ENTER :	selected = tMH.tree_to_arr(chon);								  											
		  				a = &tMH.SearchNode_Re(tMH.root, selected)->MH;			
		  			 	return select_DE(0, 1, a);
	 	} 
	} 
}
void select_DE(int chon, int page, MonHoc *a)
{
	clear_screen1();
	clear_screen2();
	guide_DE();
	int x = 1, y = 15;
	char kytu;
	while(1)
	{
		a->DE.outputlist_DE(page);
		if(a->DE.slde > 0){
			HighLight();
			mauChu(x, y + (chon % 20), BLACK, " -> ");
			Normalw(); 
		}
		gotoxy(x + 6, y - 3); cout << "Ma mon hoc: " << a->maMonHoc << "          Ten mon hoc: " << a->tenMonHoc;
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :if (chon > 0 && chon > (page-1)*20)  chon = up_down(x, y, chon, UP);
	  			  break;
	  	case DOWN :if (chon + 1 <a->DE.slde && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
					break;
		case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page *20 < a->DE.slde) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}		
					break;
		case ESC :	SetBGColor(BLACK);
					return select_MHDE(0);
		case INSERT : 	
						clear_screen4();
						Normalw();
						a->DE.insertlist_DE(CH.count_CH(a->maMonHoc));
						clear_screen2();
						clear_screen5();
						break;
		case DEL :		
					clear_screen5();				
					if(a->DE.slde <= 0)break;
					else{
						bool e = del_hoi();
						if(e){
							clear_screen4();
							clear_screen2();
							Normalw();
							if(chon == 0 ){
								a->DE.del_DE(chon);
								if(page > 1 && a->DE.slde % 20 == 0)
								{
									chon--;
									page--;
								}
							}
							else{
								a->DE.del_DE(chon);
								chon--;
							}							
						}
						else 
						{
							clear_screen4();
						}
					}	
					break;
		case HOME : SetBGColor(BLACK);
					return giao_vien();
	  	case ENTER : 
					break;
	 	} 
	} 
}
/////////////////////////////
void giao_vien()
{
	Nocursortype(0);
	int chon =  MenuGV();
		switch (chon)
		{
			case 1:
				SetBGColor(BLACK);
				clear_screen3();
				guide_Lop();
				return select_Lop(0);
			case 2:
			 	SetBGColor(BLACK);
			 	clear_screen3();
			 	guide_MH();
			 	return select_MH(0);
			case 3: 
				SetBGColor(BLACK);
			 	clear_screen3();
				return select_MHDE(0);	
			case 4: 
				SetBGColor(BLACK);
			 	clear_screen3();	
				return select_DiemMH(0);
			case 5: if(thoat()){
				 		end();
			 			return;
					}
					else return giao_vien();
		}
}
////////////////////////////SINHVIEN////////////////////
bool notifi(string str)
{
	Normalw();
	clear_screenTT();
	mauChu(110, 4, RED, str);
	string s[2] = {" YES ", " EXIT "};
	Normalw();
	bool chon = true;
	for(int i = 0; i < 2; i++)
	{
		mauChu(116 + i*10, 6, RED, s[i]);
	}
	HighLight();
	mauChu(116, 6, RED, s[0]);
	Normalw();
	char key;
	while(1){
		key = getch();
		if(key == 0) key= getch();
		switch (key){
			case LEFT: 
				    chon = true;
					Normal();
	              	mauChu(116 + 10, 6, RED, s[1]);	
	              	HighLight();
	              	mauChu(116, 6, RED, s[0]);
					break;
			case RIGHT:
				    chon = false;
					Normal();
	              	mauChu(116, 6, RED, s[0]);
	              	HighLight();
	              	mauChu(116 + 10, 6, RED, s[1]);
					break;
			case ENTER:
				 	Normalw();
				 	return chon;
		}
	} 
}
void select_MHThi(int chon, SinhVien *sv)
{
	guide_Thi();
	clear_screen2();
	clear_screenTT();
	int x = 1, y = 15, page = chon/20 + 1;
	string selected;
	MonHoc *a;
	char kytu;
	while(1)
	{
		if(tMH.slmh > 0){
		HighLight();
		mauChu(x, y + (chon % 20), BLACK, " -> ");
		}
		Normalw();
		tMH.LNRkodequy(page);
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :
			if (chon > 0 && chon > (page - 1)*20) chon = up_down(x, y, chon, UP);
	  		break;
	  	case DOWN :
		  	if (chon + 1 <tMH.slmh && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
	  		break;
	  	case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page*20 < tMH.slmh ) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}		
					break;
		case ESC :	if(thoat())
					{
						end();
						return;
					}
					else {
						clear_screenTT();
						break;
					}				
	  	case ENTER :	
		  				selected = tMH.tree_to_arr(chon);								  											
		  				a = &tMH.SearchNode_Re(tMH.root, selected)->MH;	
						if(sv->FirstDiem->find_Diem(a->maMonHoc) != NULL)
						{
							 if(notifi("SV DA THI MON NAY! THI TIEP?"))
							 {
							 	return sinh_vien(sv);
							 }
							 else 
							 {
							 	end();
							 	return;
							 }
						}
						else		
		  			 	return select_DETHI(0, a, sv, 1);
	 	} 
	} 
}
void select_DETHI(int chon, MonHoc *a, SinhVien *sv, int page)
{
	clear_screen2();
	clear_screenTT();
	clear_screen3();
	guide_Thi();
	DeThi *d;
	int x = 1, y = 15;
	char kytu;
	while(1)
	{
		gotoxy(110, 5); cout << "Ma MH: " << a->maMonHoc;
		gotoxy(110, 6); cout << "Ten MH: ";
		show_string(a->tenMonHoc, 25, 118, 6);
		a->DE.outputlist_DE(page);
		if(a->DE.slde > 0){
			HighLight();
			mauChu(x, y + (chon % 20), BLACK, " -> ");
			Normalw(); 
		}
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :if (chon > 0 && chon > (page - 1)*20)  chon = up_down(x, y, chon, UP);
	  			  break;
	  	case DOWN :if (chon + 1 <a->DE.slde && chon < (page*20)) chon = up_down(x, y, chon, DOWN);
					break;
		case LEFT : if(page > 1) {
						page--;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case RIGHT: if(page*20 < a->DE.slde) 
					{
						page++;
						chon = (page-1)*20;
						clear_screen2();
					}
					break;
		case ESC :
					clear_screenTT();
					return select_MHThi(0, sv);
	  	case ENTER : 
	  				d = a->DE.find_Num(chon); 
						if(notifi("      BAT DAU LAM BAI?")) {
							clear_screenTT();	
							gotoxy(110, 5); cout << "Ma MH: " << a->maMonHoc;
							gotoxy(110, 6); cout << "Ten MH: ";
							show_string(a->tenMonHoc, 25, 118, 6);
							return lam_bai(d, a, sv) ;
						}
						else {
							end();
							return;
						}
	 	} 
	} 
}

void swap_ab(int &a, int &b)
{
	int c = a; a = b; b = c;
}
int rand_so( int *temp, int number, int limit)
{
	srand(time(NULL));
	for(int i = 0; i < number; i++) temp[i] = i;
	for(int i = 0; i < limit; i++){	
		int j = (rand() % number);		
		swap_ab(temp[i], temp[j]);
	}		
}

void take_EXAM(int *arr, CauHoi *exam[], MonHoc *a, int limit)
{
	int j = 0, num = CH.count_CH(a->maMonHoc);
	CauHoi *arrCH[num];
	for(int i = 0; i < CH.slch; i++)
	{
		if(CH.nodesCH[i]->maMonHoc.compare(a->maMonHoc) == 0)
		{
			arrCH[j] = CH.nodesCH[i];
			j++;
		}
	}
	int temp[num];
	rand_so(temp, num, limit);
	for(int i = 0; i < limit; i++) 
	{	
		exam[i] = arrCH[temp[i]];
		arr[i] = exam[i]->id;
	}
	
}
int chon_DA(Timer &timer)
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
	while (1){
		
			Normalw();
			gotoxy(121, 11); 
			cout << timer.getTimeLeft();
			SetColor(WHITE);
		
		if(kbhit()){
	  	kytu = getch();
	  	switch (kytu) {
	    case LEFT :if (chon+1 >1)
	  			  {
	  		        Normal();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	              	chon--;
	              	HighLight();
	              	mauChu(x + chon*10, y, RED, da[chon]);	
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 < 4)
	  			  {
	  		        Normal();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	              	chon++;
	              	HighLight();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	  			  }
	  			  break;
	  	case ENTER : 
	  				SetBGColor(BLACK);
	  				return chon + 1;
	 	 } 
		}
	  } 

}
void show_debai(DeThi *d, int x, int y, CauHoi *exam[], int page)
{
	table_LB();
	for(int i = (page-1)*20; i < page*20 && i < d->socau; i++)
	{
		gotoxy(x, y);
		cout << "Cau " << i+1 <<':';
		gotoxy(x + 8, y);
		string tmp;
		tmp.append(exam[i]->noiDung, 0, 80);
		if(exam[i]->noiDung.length() > 80) tmp.append("... ?");
		cout << tmp;
		y++;
	}
	gotoxy(94, 35); cout << "trang: " << page;
}
void show_dapan(int ans[], int limit)
{
	int x = 109, y = 15;
	for(int i = 0; i < limit; i++)
	{
		x = x + 8*(i/20);
		y = 15 + (i % 20);
		gotoxy(x, y);
		cout << i + 1 <<".";
		if(ans[i] == 0) cout << "?";
		else if(ans[i] == 1) cout << "A";
			else if(ans[i] == 2) cout << "B";
				else if(ans[i] == 3) cout << "C";
					else if(ans[i] == 4) cout << "D";	
	}
}
void save_Diem(SinhVien *sv, string maMH, float score, int limit, int ans[],int arr[])
{
	sv->FirstDiem->insert_Diem(maMH, score, arr, ans, limit);
}
void show_ketqua(float score, int correct, int limit, SinhVien *sv)
{
	rectangle(35, 3, 37, 5, YELLOW);
	mauChu(45, 4, GREEN, "===KET QUA THI===");
	gotoxy(40, 6); cout << "DIEM: " << score << "    SO CAU DUNG: " << correct << "/" << limit;
	if(notifi("   BAN CO MUON THI TIEP?"))
	{
		clear_screen1();
		clear_screenDA();
		clear_screenTime();
		return select_MHThi(0, sv);
	}
	else 
	{
		end();
		return;
	}
}
void nop_bai(CauHoi *exam[], int ans[], int arr[], MonHoc *a, SinhVien *sv, int limit)
{
	int correct = 0;
	float score = 0.0;
	for(int i = 0; i < limit; i++) if(exam[i]->dapAn == ans[i]) correct++;
	score = correct * (10.0 / limit);
	save_Diem(sv, a->maMonHoc, score, limit, ans, arr);
	return show_ketqua(score, correct, limit, sv);

}
void lam_bai(DeThi *d, MonHoc *a, SinhVien *sv)
{
	int x = 3, y = 15, page = 1, chon = 0;
	clear_screen2();
	int arr[d->socau];
	int ans[d->socau] = {};
	CauHoi *exam[d->socau];
	take_EXAM( arr ,exam, a, d->socau);
	clear_screen2();
	Timer timer(d->thoigian* 60);
	char key;
	while(!timer.timeOut())
	{	
		show_debai(d, x + 5, y, exam, page);
		gotoxy(121, 11); 
		cout << timer.getTimeLeft();
		SetColor(WHITE);
		show_dapan(ans, d->socau);
		HighLight();
		mauChu(x, y + (chon % 20), BLACK, " -> ");
		Normalw();
	  	if (kbhit()) {	
	  	switch (key = getch()) {	
		    case UP :	if(chon > 0 && chon > (page - 1)*20)  chon = up_down(x, y, chon, UP);
	  			  		break;
		  	case DOWN :	if(chon + 1 <d->socau && chon < (page*20) - 1) chon = up_down(x, y, chon, DOWN);
						break;
			case LEFT : if(page > 1) {
							page--;
							chon = (page-1)*20;
							clear_screen2();
						}
						break;
			case RIGHT: if(page*20 < d->socau) 
						{
							page++;
							chon = (page-1)*20;
							clear_screen2();
						}
						break;
		  	case ENTER :
			  			exam[chon]->show_EXAM(chon);
			  			ans[chon] = chon_DA(timer);
			  			clear_screen1();
			  			break;
			case F1 :
						if(notifi("        NOP BAI?"))						
								return nop_bai(exam, ans, arr, a, sv, d->socau);
						else{
							clear_screenTT();
							gotoxy(110, 5); cout << "Ma MH: " << a->maMonHoc;
							gotoxy(110, 6); cout << "Ten MH: ";
							show_string(a->tenMonHoc, 25, 118, 6);
							break;
						}
						
	 				}
	 			}
	}
	return nop_bai(exam, ans, arr, a, sv, d->socau);
}

void sinh_vien(SinhVien *&a)
{
	system("cls");
	Nocursortype(0);
	GiaoDienSV();
	guide_Thi();
	gotoxy(110, 2); cout << "Ma SV: " << a->maSV;
	gotoxy(110, 3); cout << "Ho&Ten: " << a->Ho << " " << a->Ten;
	select_MHThi(0, a);	
}

////////////////////////////DANGNHAP/////////////
void login_fail(){
	Nocursortype(0);
	rectangle(40, 31, 60, 6, GREEN);
 	mauChu(50, 32, GREEN, "Tai khoan hoac mat khau khong chinh xac ");
	mauChu(60, 33, GREEN, "vui long nhap lai!");
	mauChu(48, 35, RED, "ENTER DE NHAP LAI HOAC NHAN BAT KY DE THOAT!");
	char key = getch();
	while(1){
		if(key == ENTER) return login_fun();
		else break;
	}	
}
void show()
{
	system("cls");
	TieuDe();
	DangNhap();
}
void password_login(int x, int y, int width, string &pass)
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
						cout << "*";
						if(a == width){			
							a = 0;
							b++;	
						}
					}
				break;	
		}
	}
 }
bool GiaoVien(string user, string pass)
{
	string u, p;
	ifstream file("DSgv.txt");
	getline(file, u, '@');
	file.ignore();
	getline(file, p, '@');
	file.close();
	
	if(u.compare(user) == 0 && p.compare(pass) == 0) return 1;
	else return 0;
}
void find_user(string user, string pass)
{
	SinhVien *find;
	for(int i = 0; i < dsL.slLop; i++)
	{
		find = dsL.nodesL[i]->Firstsv->find(user);
		if(find != NULL) // la sinh vien
		{
			if(pass.compare(find->password) == 0) return sinh_vien(find);
			else break;
		}
	}
	if(GiaoVien(user, pass)) return giao_vien(); //la giao vien
	return login_fail();
}
void login_fun()
{
	Nocursortype(1);
	string user, pass;
	show();
	begin();
	
	input_check(55, 20, 20, 20, user, 1);
	gotoxy(55, 24);
	password_login(55, 24, 16, pass);
	return find_user(user, pass);
}


