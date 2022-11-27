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
char c2=205,O=178,c3=209,c1=179;
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
void Win1(){
	gotoxy(5,5);cout<<O<<O<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<O<<O;
	gotoxy(5,6);cout<<"||            ||";
	gotoxy(5,7);cout<<O<<O<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<O<<O;
	TextColor(4);
	gotoxy(7,6);cout<<"Player 1 WIN";
}
void Win2(){
	gotoxy(5,5);cout<<O<<O<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<O<<O;
	gotoxy(5,6);cout<<"||            ||";
	gotoxy(5,7);cout<<O<<O<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<O<<O;
	TextColor(1);
	gotoxy(7,6);cout<<"Player 2 WIN";
}
void start(){
	system("cls");
	gotoxy(10,5);cout<<"Press anykey to start";
	gotoxy(40,3);cout<<"Press \"A\" to drag left";
	gotoxy(40,4);cout<<"Press \"L\" to drag right";
	getch();
	system("cls");
}
void build(){
	TextColor(4);
	for(int y=1;y<6;y++){
		for(int x=1;x<10;x++){
			gotoxy(x,y);cout<<O;
		}
	}
	gotoxy(1,0);cout<<"Player 1";
	TextColor(1);
	for(int y=1;y<6;y++){
		for(int x=31;x<40;x++){
			gotoxy(x,y);cout<<O;
		}
	}
	gotoxy(32,0);cout<<"Player 2";
	TextColor(5);
	for(int x=10;x<=30;x++){
		gotoxy(x,3);cout<<c2;
	}
}
void build2(){
	TextColor(4);
	for(int y=1;y<6;y++){
		for(int x=1;x<10;x++){
			gotoxy(x,y);cout<<O;
		}
	}
	gotoxy(2,0);cout<<"Player";
	TextColor(1);
	for(int y=1;y<6;y++){
		for(int x=31;x<40;x++){
			gotoxy(x,y);cout<<O;
		}
	}
	gotoxy(34,0);cout<<"Robot";
	TextColor(5);
	for(int x=10;x<=30;x++){
		gotoxy(x,3);cout<<c2;
	}
}
void game3N2(){
	start();
	system("color 00");
	build();
	int BR=11;
	for(;;){
		gotoxy(BR+9,3);cout<<c3;
		gotoxy(BR+9,4);cout<<c1;
		gotoxy(BR+9,5);cout<<O;
		gotoxy(11,6);
		char c=getch();
		if(c=='a'||c=='A'){
			BR--;
			gotoxy(BR+10,3);cout<<c2;
			gotoxy(BR+10,4);cout<<" ";
			gotoxy(BR+10,5);cout<<" ";
		}
		else if(c=='l'||c=='L'){
			BR++;
			gotoxy(BR+8,3);cout<<c2;
			gotoxy(BR+8,4);cout<<" ";
			gotoxy(BR+8,5);cout<<" ";
		}
		if(BR==1){
			system("cls");
			for(int i=0;i<100;i++){
				TextColor(rand()%15+1);
				Sleep(50);
				Win1();
			}
			break;
		}
		if(BR==21){
			system("cls");
			for(int i=0;i<100;i++){
				TextColor(rand()%15+1);
				Sleep(50);
				Win2();
			}
			break;
		}
		Sleep(1);
	}
}
void game3N1(){
	int n2;
	for(;;){
		system("cls");
		TextColor(rand()%15+1);
		gotoxy(2,1);cout<<"Please select a level 1 -> 7: ";
		char c3=getche();
		if(c3=='1')
			n2=150;
		else if(c3=='2')
			n2=135;
		else if(c3=='3')
			n2=120;
		else if(c3=='4')
			n2=105;
		else if(c3=='5')
			n2=90;
		else if(c3=='6')
			n2=75;
		else if(c3=='7')
			n2=60;
		if(c3=='1'||c3=='2'||c3=='3'||c3=='4'||c3=='5'|c3=='6'||c3=='7')
			break;
	}
	start();
	system("color 00");
	build2();
	int BR=11;
	gotoxy(43,5);cout<<"Press \"P\" to pause";
	for(;;){
		gotoxy(11,10);
		if(kbhit()){
			char c = getch();
			if( c=='a' || c=='A'){
				BR=BR-2;
				gotoxy(BR+10,3);cout<<c2<<c2;
				gotoxy(BR+10,4);cout<<"  ";
				gotoxy(BR+10,5);cout<<"  ";
			}
			if( c=='p'||c=='P'){
				gotoxy(5,15);cout<<"Press anykey to continue";
				getch();
				gotoxy(5,15);cout<<"                        ";
			}
			if(c==27){
				int tdy=2;
				TextColor(15);
				gotoxy(20,14);cout<<"Do you want to exit?";
				TextColor(4);
				gotoxy(24,15);cout<<"Yes";
				TextColor(2);
				gotoxy(24,16);cout<<"No";
				TextColor(15);
				for(;;){
					gotoxy(21,tdy+14);cout<<"=>";
					gotoxy(29,tdy+14);cout<<"<=";
					char ch=getch();
					if(ch=='w'||ch=='W'||ch=='s'||ch=='S'){
						if(tdy==1){
							gotoxy(21,15);cout<<"  ";
							gotoxy(29,15);cout<<"  ";
							tdy=2;
						}
						else{
							gotoxy(21,16);cout<<"  ";
							gotoxy(29,16);cout<<"  ";
							tdy=1;
						}
					}
					if(ch==13||ch==' '){
						gotoxy(21,tdy+14);cout<<"  ";
						gotoxy(29,tdy+14);cout<<"  ";
						gotoxy(24,15);cout<<"   ";
						gotoxy(24,16);cout<<"  ";
						if(tdy==1)
							tdy=0;
						break;
					}
				}
				if(tdy==0)
					break;
				gotoxy(20,14);cout<<"Press any key to continue";
				getch();
				gotoxy(20,14);cout<<"                         ";
				TextColor(5);
			}
		}
		BR++;
		gotoxy(BR+8,3);cout<<c2;
		gotoxy(BR+8,4);cout<<" ";
		gotoxy(BR+8,5);cout<<" ";
		gotoxy(BR+9,3);cout<<c3;
		gotoxy(BR+9,4);cout<<c1;
		gotoxy(BR+9,5);cout<<O;
		if(BR==1){
			system("cls");
			for(int i=0;i<100;i++){
				TextColor(rand()%15+1);
				Sleep(50);
				Win1();
			}
			break;
		}
		if(BR==21){
			system("cls");
			for(int i=0;i<100;i++){
				TextColor(rand()%15+1);
				Sleep(50);
				Win2();
			}
			break;
		}
		Sleep(n2);
	}
}
int main(int argc, char** argv) {
	DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
	setFontSize(28);
	resizeConsole(1000,500);
	srand(time(NULL));
	int toadoy=1;
	for(int f=0;f==0;){
		system("cls");
		TextColor(rand()%15+1);
		gotoxy(5,2);cout<<O<<O<<c2<<c2<<c2<<O<<O;
		TextColor(rand()%15+1);
		gotoxy(5,3);cout<<"||TUG||";
		TextColor(rand()%15+1);
		gotoxy(5,4);cout<<O<<O<<c2<<c2<<c2<<O<<O;
		TextColor(rand()%15+1);
		gotoxy(4,5);cout<<"1 - Player VS Robot";
		TextColor(rand()%15+1);
		gotoxy(4,6);cout<<"2 - Player VS Player";
		TextColor(rand()%15+1);
		gotoxy(4,7);cout<<"3 - Exit";
		TextColor(15);
		gotoxy(1,toadoy+4);cout<<"=>";
		gotoxy(25,toadoy+4);cout<<"<=";
		char c=getch();
		if(c=='w'||c=='W'){
			if(toadoy==1)
				toadoy=3;
			else
				toadoy--;
		}
		if(c=='s'||c=='S'){
			if(toadoy==3)
				toadoy=1;
			else
				toadoy++;
		}
		if(c==13||c==' '){
			if(toadoy==1)
				game3N1();
			if(toadoy==2)
				game3N2();
			if(toadoy==3)
				c=27;
		}
		if(c==27)
		break;
	}
	return 0;
}
