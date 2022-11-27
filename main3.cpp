#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <dos.h> 
#include <windows.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HWND hWnd = GetConsoleWindow();
HMENU hMenu = GetSystemMenu(hWnd, false);
COORD CursorPosition;
char g1=201,g2=187,g3=188,g4=200,c1=186,c2=205,gc1=204,gc2=203,Ovuong=219,O=178;
void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void TextColor(int x){
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
void resizeConsole(int width, int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 10, 10, width, height, TRUE);
}
void setFontSize(int FontSize){
	CONSOLE_FONT_INFOEX info = {0};
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}
void P1Win(){
	gotoxy(2,7); cout<<"±±±±     ±     ±   ±   ±  ±  ±±  ±";
	gotoxy(2,8); cout<<"±   ±   ±±     ±   ±   ±  ±  ± ± ±";
	gotoxy(2,9); cout<<"±±±±   ± ±      ± ± ± ±   ±  ± ± ±";
	gotoxy(2,10);cout<<"±        ±      ± ± ± ±   ±  ± ± ±";
	gotoxy(2,11);cout<<"±        ±       ±   ±    ±  ±  ±±";
}
void P2Win(){
	gotoxy(2,7); cout<<"±±±±    ±±±     ±   ±   ±  ±  ±±  ±";
	gotoxy(2,8); cout<<"±   ±  ±   ±    ±   ±   ±  ±  ± ± ±";
	gotoxy(2,9); cout<<"±±±±     ±±      ± ± ± ±   ±  ± ± ±";
	gotoxy(2,10);cout<<"±       ±        ± ± ± ±   ±  ± ± ±";
	gotoxy(2,11);cout<<"±      ±±±±±      ±   ±    ±  ±  ±±";
}
void Build(char G2[30][30]){
	gotoxy(0,0);
	int MS=136;
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			TextColor(MS);
			cout<<Ovuong<<Ovuong;
			if(MS==0)
				MS=136;
			else
				MS=0;
		}
		if(MS==136)
				MS=0;
			else
				MS=136;
		cout<<endl;
	}
	TextColor(15);
	for(int i=0;i<31;i++){
		gotoxy(60,i);cout<<Ovuong<<Ovuong;
	}
	gotoxy(0,30);
	for(int i=0;i<61;i++){
		cout<<Ovuong;
	}
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			G2[i][j]=' ';
		}
	}
}
bool CheckKQ(int x,int y,int XO,char G[30][30]){
	int W=0;char xo;
	if(XO==0)
		xo='O';
	else
		xo='X';
	//Check 1
	for(int i=0;i<5;i++){
		if(x-i<0)
			break;
		else{
			if(G[y][x-i]==xo)
				W++;
			else
				i=5;
		}
	}
	for(int i=1;i<5;i++){
		if(x+i>=30)
			break;
		else{
			if(G[y][x+i]==xo)
				W++;
			else
				i=5;
		}
	}
	if(W>=5){
		return true;
	}
	W=0;
	//check 2
	for(int i=0;i<5;i++){
		if(x-i<0&&y-i<0)
			break;
		else{
			if(G[y-i][x-i]==xo)
				W++;
			else
				i=5;
		}
	}
	for(int i=1;i<5;i++){
		if(x+i>=30&&y+i>30)
			break;
		else{
			if(G[y+i][x+i]==xo)
				W++;
			else
				i=5;
		}
	}
	if(W>=5){
		return true;
	}
	W=0;
	//check 3
	for(int i=0;i<5;i++){
		if(y-i<0)
			break;
		else{
			if(G[y-i][x]==xo)
				W++;
			else
				i=5;
		}
	}
	for(int i=1;i<5;i++){
		if(y+i>=30)
			break;
		else{
			if(G[y+i][x]==xo)
				W++;
			else
				i=5;
		}
	}
	if(W>=5){
		return true;
	}
	W=0;
	//check 4
	for(int i=0;i<5;i++){
		if(x-i<0&&y+i>=30)
			break;
		else{
			if(G[y+i][x-i]==xo)
				W++;
			else
				i=5;
		}
	}
	for(int i=1;i<5;i++){
		if(x+i>=30&&y-i<0)
			break;
		else{
			if(G[y-i][x+i]==xo)
				W++;
			else
				i=5;
		}
	}
	if(W>=5){
		return true;
	}
	return false;
}
void Game2(){
	system("cls");
	srand(time(NULL));
	int x=14,y=14,XO=0;
	TextColor(15);
	gotoxy(65,1);cout<<"Press \"W\"to up";
	gotoxy(65,2);cout<<"Press \"S\"to down";
	gotoxy(65,3);cout<<"Press \"A\"to left";
	gotoxy(65,4);cout<<"Press \"D\"to right";
	gotoxy(65,5);cout<<"Press Esc to exit";
	gotoxy(65,6);cout<<"Press enter or space to print    or";
	TextColor(1);
	gotoxy(95,6);cout<<Ovuong<<Ovuong;
	TextColor(4);
	
	gotoxy(101,6);cout<<Ovuong<<Ovuong;
	char G2[30][30];
	Build(G2);
	int m=136;
	for(;;){
		TextColor(15);
		gotoxy(x*2,y);cout<<O<<O;
		gotoxy(63,3);
		if(XO==0){
			TextColor(1);
			gotoxy(65,12);cout<<"    ";
			gotoxy(65,13);cout<<"    ";
			gotoxy(65,14);cout<<"    ";
			gotoxy(65,8);cout<<"/--\\";
			gotoxy(65,9);cout<<"|  |";
			gotoxy(65,10);cout<<"\\--/";
			TextColor(15);
			gotoxy(66,9);cout<<"P1";
			TextColor(4);
			gotoxy(66,13);cout<<"P2";
		}
		else{
			TextColor(4);
			gotoxy(65,8);cout<<"    ";
			gotoxy(65,9);cout<<"    ";
			gotoxy(65,10);cout<<"    ";
			gotoxy(65,12);cout<<"/--\\";
			gotoxy(65,13);cout<<"|  |";
			gotoxy(65,14);cout<<"\\--/";
			TextColor(15);
			gotoxy(66,13);cout<<"P2";
			TextColor(1);
			gotoxy(66,9);cout<<"P1";
			
		}
		gotoxy(63,0);
		char c=getch();
		TextColor(m);
		if(m==136)
			m=0;
		else
			m=136;
		if(c=='w'||c=='W'){
			if(y==0){
				y=29;
				gotoxy(x*2,0);
				if(G2[0][x]=='X'){
					TextColor(1);
					cout<<Ovuong<<Ovuong;
				}
				else if(G2[0][x]=='O'){
					TextColor(4);
					cout<<Ovuong<<Ovuong;
				}
				else{
					cout<<"  ";
				}
			}
			else{
				y--;
				gotoxy(x*2,y+1);
				if(G2[y+1][x]=='X'){
					TextColor(1);
					cout<<Ovuong<<Ovuong;
				}
				else if(G2[y+1][x]=='O'){
					TextColor(4);
					cout<<Ovuong<<Ovuong;
				}
				else{
					cout<<"  ";
				}
			}
		}
		if(c=='s'||c=='S'){
			if(y==29){
				y=0;
				gotoxy(x*2,29);
				if(G2[29][x]=='X'){
					TextColor(1);
					cout<<Ovuong<<Ovuong;
				}
				else if(G2[29][x]=='O'){
					TextColor(4);
					cout<<Ovuong<<Ovuong;
				}
				else{
					cout<<"  ";
				}
			}
			else{
				y++;
				gotoxy(x*2,y-1);
				if(G2[y-1][x]=='X'){
					TextColor(1);
					cout<<Ovuong<<Ovuong;
				}
				else if(G2[y-1][x]=='O'){
					TextColor(4);
					cout<<Ovuong<<Ovuong;
				}
				else{
					cout<<"  ";
				}
			}
		}
		if(c=='a'||c=='A'){
			if(x==0){
				x=29;
				gotoxy(0,y);
				if(G2[y][0]=='X'){
					TextColor(1);
					cout<<Ovuong<<Ovuong;
				}
				else if(G2[y][0]=='O'){
					TextColor(4);
					cout<<Ovuong<<Ovuong;
				}
				else{
					cout<<"  ";
				}
			}
			else{
				x--;
				gotoxy((x+1)*2,y);
				if(G2[y][x+1]=='X'){
					TextColor(1);
					cout<<Ovuong<<Ovuong;
				}
				else if(G2[y][x+1]=='O'){
					TextColor(4);
					cout<<Ovuong<<Ovuong;
				}
				else{
					cout<<"  ";
				}
			}
		}
		if(c=='d'||c=='D'){
			if(x==29){
				x=0;
				gotoxy(58,y);
				if(G2[y][29]=='X'){
					TextColor(1);
					cout<<Ovuong<<Ovuong;
				}
				else if(G2[y][29]=='O'){
					TextColor(4);
					cout<<Ovuong<<Ovuong;
				}
				else{
					cout<<"  ";
				}
			}
			else{
				x++;
				gotoxy((x-1)*2,y);
				if(G2[y][x-1]=='X'){
					TextColor(1);
					cout<<Ovuong<<Ovuong;
				}
				else if(G2[y][x-1]=='O'){
					TextColor(4);
					cout<<Ovuong<<Ovuong;
				}
				else{
					cout<<"  ";
				}
			}
		}
		if(c==' '||c==13){
			if(G2[y][x]==' ')
			{
				if(XO==0){
					G2[y][x]='X';
					XO=1;
					if(m==136)
						m=0;
					else
						m=136;
				}
				else{
					G2[y][x]='O';
					XO=0;
					if(m==136)
						m=0;
					else
						m=136;
				}
			}
			else{
				if(m==136)
					m=0;
				else
					m=136;
			}
		}
		if(c==27){
			int tdy=2;
			TextColor(15);
			gotoxy(64,14);cout<<"Do you want to exit?";
			TextColor(4);
			gotoxy(68,15);cout<<"Yes";
			TextColor(2);
			gotoxy(68,16);cout<<"No";
			TextColor(15);
			for(;;){
				gotoxy(65,tdy+14);cout<<"=>";
				gotoxy(74,tdy+14);cout<<"<=";
				char ch=getch();
				if(ch=='w'||ch=='W'||ch=='s'||ch=='S'){
					if(tdy==1){
						gotoxy(65,15);cout<<"  ";
						gotoxy(74,15);cout<<"  ";
						tdy=2;
					}
					else{
						gotoxy(65,16);cout<<"  ";
						gotoxy(74,16);cout<<"  ";
						tdy=1;
					}
				}
				if(ch==13||ch==' '){
					gotoxy(65,tdy+14);cout<<"  ";
					gotoxy(74,tdy+14);cout<<"  ";
					gotoxy(64,14);cout<<"                               ";
					gotoxy(68,15);cout<<"   ";
					gotoxy(68,16);cout<<"  ";
					if(tdy==1)
						tdy=0;
					break;
				}
			}
			if(tdy==0){
				system("cls");
				system("color 0F");
				break;
			}
			if(m==136)
				m=0;
			else
				m=136;
		}
		bool KQ=CheckKQ(x,y,XO,G2);
		if(KQ==true){
			system("cls");
			system("color 0F");
			if(XO==0){
				for(int ii=0;ii<100;ii++){
					int n=rand()%15+1;
					TextColor(n);
					P2Win();
					Sleep(50);
				}
			}
			else if(XO==1){
				for(int ii=0;ii<100;ii++){
					int n=rand()%15+1;
					TextColor(n);
					P1Win();
					Sleep(50);
				}
			}
			system("color 0F");
			break;
		}
	}
}
int main(int argc, char** argv) {
	DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
	setFontSize(20);
	resizeConsole(1000,660);
	Game2();
	return 0;
}
