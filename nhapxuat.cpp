#include "nhapxuat.h"
void input_check(int x, int y, int max, int width, string &data, bool id)
{
	int a = data.length() % width, b = data.length() / width;
	char key;
	int check;
	string result = data;
	show_string(result, width, x, y);
	while(1)
	{
		key = getch();
		if (key==0) key = getch();
		switch(key)
		{
			case ENTER :
				data = result;
				return;
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
					if(result.length() != max)
					{	
						if(id && key >= 'a' && key <= 'z')
							key = key - 32;
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
void show_string(string str, int max, int x, int y)
{
	int k = 0;
	int len = str.length();
	int start;
	int end;
	while (true)
	{
		gotoxy(x, k + y);
		start = max * k;
		end = min(max, len - start);
		cout << str.substr(start, end);
		if (end < max) break;
		++k;
	}
}
