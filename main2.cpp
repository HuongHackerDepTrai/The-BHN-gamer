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
char g1=201,g2=187,g3=188,g4=200,gc1=203,gc2=204,c1=186,c2=205;
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
void YouWin(int move,int phut,int giay){
	gotoxy(9,16);cout<<"Press anykey to back";
	for(;;){
		TextColor(rand()%15+1);
		gotoxy(10,7); cout<<" ����   ���   �      �   �  �����  ���";
		TextColor(rand()%15+1);
		gotoxy(10,8); cout<<"�      �   �  �      �   �  �      �  �";
		TextColor(rand()%15+1);
		gotoxy(10,9); cout<<" ���   �   �  �       � �   �����  �  �";
		TextColor(rand()%15+1);
		gotoxy(10,10);cout<<"    �  �   �  �       � �   �      �  �";
		TextColor(rand()%15+1);
		gotoxy(10,11);cout<<"����    ���   �����    �    �����  ���";
		gotoxy(10,12);cout<<"Congratulations! You solved this puzzle in "<<move<<" moves.";
		gotoxy(7,14);cout<<"Time: ";
	    if(phut<10)
	    	cout<<"00";
	    else if(phut<100)
	    	cout<<"0";
	    cout<<phut<<" : ";
	    if(giay<10)
	    	cout<<"0";
	    cout<<giay;
		char c=NULL;
		if(kbhit()){
			c=getche();
		}
		if(c!=NULL)
			break;
		Sleep(50);
	}
	
}
void Instructions(){
	system("cls");
	TextColor(15);
	gotoxy(7,2);cout<<"Press \"W\" to up";
	gotoxy(7,3);cout<<"Press \"S\" to down";
	gotoxy(7,4);cout<<"Press \"A\" to left";
	gotoxy(7,5);cout<<"Press \"D\" to right";
	gotoxy(7,6);cout<<"Press Esc to exit";
	gotoxy(7,8);cout<<"Press anykey to back...";
	getch();
}
void Game1() {
	//Slide puzzle
	int move=0,toadoy=1;
	for(int re=0;re==0;){
		int i,temp=1,x,y;
		system("color 00");
		for(;;){
			system("cls");
			TextColor(rand()%15+1);
			gotoxy(8,1);cout<<"Slide puzzle x * y:"<<endl;
			TextColor(rand()%15+1);
			gotoxy(7,2);cout<<"1 - 3 x 3 - easy";
			TextColor(rand()%15+1);
			gotoxy(7,3);cout<<"2 - 4 x 4 - normal";
			TextColor(rand()%15+1);
			gotoxy(7,4);cout<<"3 - 5 x 5 - hard";
			TextColor(rand()%15+1);
			gotoxy(7,5);cout<<"4 - 6 x 6 - legendary";
			TextColor(rand()%15+1);
			gotoxy(7,6);cout<<"5 - Exit";
			TextColor(15);
			gotoxy(4,toadoy+1);cout<<"=>";
			gotoxy(30,toadoy+1);cout<<"<=";
			char c=getch();
			if(c=='W'||c=='w'){
				if(toadoy==1)
					toadoy=5;
				else
					toadoy--;
			}
			if(c=='S'||c=='s'){
				if(toadoy==5)
					toadoy=1;
				else
					toadoy++;
			}
			if(c==13||c==' '){
				if(toadoy==1)
					i=3;
				else if(toadoy==2)
					i=4;
				else if(toadoy==3)
					i=5;
				else if(toadoy==4)
					i=6;
				else if(toadoy==5)
					re=1;
				break;
			}
			if(c==27){
				re=1;
				break;
			}
		}
		if(re==0){
			x=i-1;y=x;
			int G1[i][i];
			for ( int i1 = 0 ; i1 < i ; i1++ ){
				for ( int i2 = 0 ; i2 < i ; i2++ ){
					G1[i1][i2]=temp;
					temp++;
				}
			}
			for ( int j = 0 ; j < 10000 ; j++ ){
				int temp2=rand()%4;
				TextColor(rand()%15+1);
				if(temp2==0){
					if(y-1>=0){
						int temp2=G1[y][x];
						G1[y][x]=G1[y-1][x];
						G1[y-1][x]=temp2;y--;
					}
				}
				if(temp2==1){
					if(y+1!=i){
						int temp2=G1[y][x];
						G1[y][x]=G1[y+1][x];
						G1[y+1][x]=temp2;y++;
					}
				}
				if(temp2==2){
					if(x-1>=0){
						int temp2=G1[y][x];
						G1[y][x]=G1[y][x-1];
						G1[y][x-1]=temp2;x--;
					}
				}
				else{
					if(x+1!=i){
						int temp2=G1[y][x];
						G1[y][x]=G1[y][x+1];
						G1[y][x+1]=temp2;x++;
					}
				}
			}
			system("color 0F");
			int gio,phut,giay;
			clock_t start, end;
	        double time_use;
	   		start = clock();
			for ( ; ; ){
				system("cls");
				TextColor(rand()%15+1);
				gotoxy(10,20);cout<<"Press Esc to exit";
				for ( int i1 = 0 ; i1 < i ; i1++ ){
					gotoxy(8,i1*2+4);
					for ( int i2 = 0 ; i2 < i ; i2++ ){
						cout<<G1[i1][i2]<<"\t";
					}
				}
				gotoxy(x*8+8,y*2+4);cout<<"  ";
				char c=getch();
				if(c=='w'||c=='W'){
					if(y-1>=0){
						int temp2=G1[y][x];
						G1[y][x]=G1[y-1][x];
						G1[y-1][x]=temp2;y--;
						move++;
					}
				}
				if(c=='s'||c=='S'){
					if(y+1!=i){
						int temp2=G1[y][x];
						G1[y][x]=G1[y+1][x];
						G1[y+1][x]=temp2;y++;
						move++;
					}
				}
				if(c=='a'||c=='A'){
					if(x-1>=0){
						int temp2=G1[y][x];
						G1[y][x]=G1[y][x-1];
						G1[y][x-1]=temp2;x--;
						move++;
					}
				}
				if(c=='d'||c=='D'){
					if(x+1!=i){
						int temp2=G1[y][x];
						G1[y][x]=G1[y][x+1];
						G1[y][x+1]=temp2;x++;
						move++;
					}
				}
				temp=1;
				bool Win=true;
				for(int i1=0;i1<i;i1++){
					for(int i2=0;i2<i;i2++){
						if(G1[i1][i2]!=temp){
							Win=false;
							i1=i;i2=i;
						}
						temp++;
					}
				}
				if(Win==true){
					end = clock();
				    time_use = (double)(end - start)/1000;
				    int temp=(int) time_use/60;
				    int temp3=(int) time_use;
				    giay=temp3%60;
				    phut=temp;
					YouWin(move,phut,giay);
					move=0;
					break;
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
				}
			}
		}
	}
}
void Gmain(){
	DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
	setFontSize(20);
	resizeConsole(600,500);
	int Y=1;
	for(;;){
		system("cls");
		TextColor(rand()%15+1);
		gotoxy(8,1);cout<<"Slide puzzle";
		TextColor(rand()%15+1);
		gotoxy(7,2);cout<<"1 - Play";
		TextColor(rand()%15+1);
		gotoxy(7,3);cout<<"2 - Instructions";
		TextColor(rand()%15+1);
		gotoxy(7,4);cout<<"3 - Exit";
		TextColor(15);
		gotoxy(3,Y+1);cout<<"=>";
		gotoxy(25,Y+1);cout<<"<=";
		char c=getch();
		if(c=='W'||c=='w'){
			if(Y==1)
				Y=3;
			else
				Y--;
		}
		if(c=='S'||c=='s'){
			if(Y==3)
				Y=1;
			else
				Y++;
		}
		if(c==13||c==' '){
			if(Y==1)
				Game1();
			else if(Y==2)
				Instructions();
			else
				c=27;
		}
		if(c==27)
			break;
	}
}
int main(int argc, char** argv) {
	srand(time(NULL));
	Gmain();
	return 0;
}
