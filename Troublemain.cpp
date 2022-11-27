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
char gai=30,vat=31,gait=17,gaip=16,o=219;
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
void BuildTheWay(){
	for(int i=0;i<33;i++){
		TextColor(rand()%15+1);
		gotoxy(0,i);cout<<o;
		TextColor(rand()%15+1);
		gotoxy(25,i);cout<<o;
		if(i==30)continue;
		TextColor(rand()%15+1);
		gotoxy(5,i);cout<<"|";
		TextColor(rand()%15+1);
		gotoxy(10,i);cout<<"|";
		TextColor(rand()%15+1);
		gotoxy(15,i);cout<<"|";
		TextColor(rand()%15+1);
		gotoxy(20,i);cout<<"|";
	}
	gotoxy(1,29);TextColor(15);
	for(int i=0;i<24;i++){
		cout<<gai;
	}
}
void Vat1(int x,int y){
	TextColor(rand()%15+1);
	gotoxy(x,y);  cout<<"    ";
	gotoxy(x,y+1);cout<<gait<<gai<<gai<<gaip;
	gotoxy(x,y+2);cout<<gait<<"##"<<gaip;
	gotoxy(x,y+3);cout<<gait<<"##"<<gaip;
	gotoxy(x,y+4);cout<<gait<<vat<<vat<<gaip;
}
void Vat2(int x,int y){
	TextColor(rand()%15+1);
	gotoxy(x,y);  cout<<"    ";
	gotoxy(x,y+1);cout<<gait<<gai<<gai<<gaip;
	gotoxy(x,y+2);cout<<gait<<"@@"<<gaip;
	gotoxy(x,y+3);cout<<gait<<"##"<<gaip;
	gotoxy(x,y+4);cout<<gait<<"##"<<gaip;
	gotoxy(x,y+5);cout<<gait<<"@@"<<gaip;
	gotoxy(x,y+6);cout<<gait<<"##"<<gaip;
	gotoxy(x,y+7);cout<<gait<<"##"<<gaip;
	gotoxy(x,y+8);cout<<gait<<"@@"<<gaip;
	gotoxy(x,y+9);cout<<gait<<vat<<vat<<gaip;
}
void Lose(int score){
	gotoxy(10,10);cout<<"±      ±±±    ±±±±  ±±±±";
	gotoxy(10,11);cout<<"±     ±   ±  ±      ±";
	gotoxy(10,12);cout<<"±     ±   ±   ±±±   ±±±±";
	gotoxy(10,13);cout<<"±     ±   ±      ±  ±";
	gotoxy(10,14);cout<<"±±±±   ±±±   ±±±±   ±±±±";
	gotoxy(9,16);cout<<"Your score: "<<score;
}
void Instruction(){
	system("cls");
	gotoxy(1,1);cout<<"You need to dodge the obstacles ahead";
	gotoxy(1,2);cout<<"Press \"A\" to left";
	gotoxy(1,3);cout<<"Press \"D\" to right";
	gotoxy(1,4);cout<<"Press \"W\" to up";
	gotoxy(1,5);cout<<"Press \"S\" to down";
	gotoxy(2,7);cout<<"Press any key to back";
	getch();
}
float menu(){
	int tdy=1;
	for(;;){
		system("cls");
		TextColor(rand()%15+1);
		gotoxy(5,1);cout<<"---------------";
		TextColor(rand()%15+1);
		gotoxy(5,2);cout<<"|   Trouble   |";
		TextColor(rand()%15+1);
		gotoxy(5,3);cout<<"---------------";
		TextColor(rand()%15+1);
		gotoxy(4,4);cout<<"1 - Easy";
		TextColor(rand()%15+1);
		gotoxy(4,5);cout<<"2 - Normal";
		TextColor(rand()%15+1);
		gotoxy(4,6);cout<<"3 - Hard";
		TextColor(rand()%15+1);
		gotoxy(4,7);cout<<"4 - Legendary";
		TextColor(rand()%15+1);
		gotoxy(4,8);cout<<"5 - Exit";
		TextColor(15);
		gotoxy(1,tdy+3);cout<<"=>";
		gotoxy(20,tdy+3);cout<<"<=";
		char c=getch();
		if(c=='W'||c=='w'){
			if(tdy==1)
				tdy=5;
			else
				tdy--;
		}
		if(c=='S'||c=='s'){
			if(tdy==5)
				tdy=1;
			else
				tdy++;
		}
		if(c==' '||c==13){
			system("cls");
			if(tdy==5)
				return 0;
			gotoxy(4,2);cout<<"Press anykey to continue";
			getch();
			gotoxy(4,2);cout<<"                        ";	
			if(tdy==1)
				return 90;
			else if(tdy==2)
				return 70;
			else if(tdy==3)
				return 50;
			else if(tdy==4)
				return 30;
		}
	}
}
void Game(){
	int ViTri=11,VT=20,score=0;
	float TD=0;
	TD=menu();
	if(TD!=0){
		int Dcong;
		if(TD==90)
			Dcong=1;
		else if(TD==70)
			Dcong=2;
		else if(TD==50)
			Dcong=3;
		else
			Dcong=4;
		system("cls");
		BuildTheWay();
		int x[3],y[3],xt[2],yt[2];
		x[0]=rand()%5*5+1;y[0]=1;
		x[1]=rand()%4*5+1;y[1]=10;
		x[2]=rand()%4*5+1;y[2]=22;
		if(x[1]>=11)
			x[1]+=5;
		if(x[2]>=11)
			x[2]+=5;
		gotoxy(33,5);cout<<"Score:";
		gotoxy(30,6);cout<<"Press \"P\" to pause";
		gotoxy(31,7);cout<<"Press Esc to exit";
		for(;;){
			gotoxy(40,5);cout<<score;
			Vat1(x[0],y[0]);
			Vat2(x[1],y[1]);
			Vat1(x[2],y[2]);
			y[0]++;
			y[1]++;
			y[2]++;
			if(y[0]==29){
				gotoxy(x[0],y[0]);cout<<gai<<gai<<gai<<gai;
				gotoxy(x[0],y[0]+1);cout<<"    ";
				gotoxy(x[0],y[0]+2);cout<<"    ";
				gotoxy(x[0],y[0]+3);cout<<"    ";
				y[0]=0;
				x[0]=rand()%5*5+1;
				score+=Dcong;
			}
			if(y[1]==29){
				gotoxy(x[1],y[1]);cout<<gai<<gai<<gai<<gai;
				gotoxy(x[1],y[1]+1);cout<<"    ";
				gotoxy(x[1],y[1]+2);cout<<"    ";
				gotoxy(x[1],y[1]+3);cout<<"    ";
				gotoxy(x[1],y[1]+4);cout<<"    ";
				gotoxy(x[1],y[1]+5);cout<<"    ";
				gotoxy(x[1],y[1]+6);cout<<"    ";
				gotoxy(x[1],y[1]+7);cout<<"    ";
				gotoxy(x[1],y[1]+8);cout<<"    ";
				y[1]=0;
				x[1]=(rand()%5)*5+1;
				score+=Dcong*5;
			}
			if(y[2]==29){
				gotoxy(x[2],y[2]);cout<<gai<<gai<<gai<<gai;
				gotoxy(x[2],y[2]+1);cout<<"    ";
				gotoxy(x[2],y[2]+2);cout<<"    ";
				gotoxy(x[2],y[2]+3);cout<<"    ";
				y[2]=0;
				if(rand()%2==0){
					x[2]=ViTri;
				}
				else
					x[2]=rand()%5*5+1;
				score+=Dcong;
			}
			TextColor(rand()%15+1);
			gotoxy(ViTri,VT);cout<<" __ ";
			gotoxy(ViTri,VT+1);cout<<"/--\\";
			gotoxy(ViTri,VT+2);cout<<"|[]|";
			gotoxy(ViTri,VT+3);cout<<"|  |";
			gotoxy(ViTri,VT+4);cout<<"\\vv/";
			if(kbhit()){
				char c=getch();
				gotoxy(ViTri,VT);cout<<"    ";
				gotoxy(ViTri,VT+1);cout<<"    ";
				gotoxy(ViTri,VT+2);cout<<"    ";
				gotoxy(ViTri,VT+3);cout<<"    ";
				gotoxy(ViTri,VT+4);cout<<"    ";
				if(c=='A'||c=='a'){
					if(ViTri>1){
						ViTri-=5;
					}
				}
				if(c=='D'||c=='d'){
					if(ViTri<17){
						ViTri+=5;
					}
				}
				if(c=='W'||c=='w'){
					if(VT>=10){
						
						VT-=2;
					}
				}
				if(c=='S'||c=='s'){
					if(VT<=22){
						VT+=2;
					}
				}
				if(c=='P'||c=='p'){
					gotoxy(28,7);cout<<"Press anykey to continue";
					getch();
					gotoxy(28,7);cout<<"                        ";
				}
				if(c==27)
					break;
			}
			if(y[0]>=VT-3&&y[0]<=VT+2&&x[0]>=ViTri-3&&x[0]<=ViTri+3){//khi xe [0] dung vao, xe player no tung
				TextColor(4);
				gotoxy(ViTri-1,VT);cout<<" #!* @";
				gotoxy(ViTri-1,VT+1);cout<<"@#%@!";
				gotoxy(ViTri-1,VT+2);cout<<" !*@*!";
				gotoxy(ViTri-1,VT+3);cout<<"@#*!%";
				gotoxy(ViTri-1,VT+4);cout<<"  @# @";
				Lose(score);
				Sleep(5000);
				break;
			}
			if(y[1]>=VT-8&&y[1]<=VT+3&&x[1]>=ViTri-3&&x[1]<=ViTri+3){//khi xe [1] dung vao, xe player no tung
				TextColor(4);
				gotoxy(ViTri-1,VT);cout<<" #!* @";
				gotoxy(ViTri-1,VT+1);cout<<"@#%@!";
				gotoxy(ViTri-1,VT+2);cout<<" !*@*!";
				gotoxy(ViTri-1,VT+3);cout<<"@#*!%";
				gotoxy(ViTri-1,VT+4);cout<<"  @# @";
				Lose(score);
				Sleep(5000);
				break;
			}
			if(y[2]>=VT-3&&y[2]<=VT+2&&x[2]>=ViTri-3&&x[2]<=ViTri+3){//khi xe [2] dung vao, xe player no tung
				TextColor(4);
				gotoxy(ViTri-1,VT);cout<<" #!* @";
				gotoxy(ViTri-1,VT+1);cout<<"@#%@!";
				gotoxy(ViTri-1,VT+2);cout<<" !*@*!";
				gotoxy(ViTri-1,VT+3);cout<<"@#*!%";
				gotoxy(ViTri-1,VT+4);cout<<"  @# @";
				Lose(score);
				Sleep(5000);
				break;
			}
			int TocDo=20;
			if(TD>=20){//Toc do tang tu tu
				TocDo=(int)TD;
				TD-=0.05;
			}
			Sleep(TocDo);
		}
	}
}
int main(int argc, char** argv) {
	DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
	setFontSize(16);
	resizeConsole(450,670);
	srand(time(NULL));
	int tdy=1;
	for(;;){
		system("cls");
		TextColor(rand()%15+1);
		gotoxy(5,1);cout<<"---------------";
		TextColor(rand()%15+1);
		gotoxy(5,2);cout<<"|   Trouble   |";
		TextColor(rand()%15+1);
		gotoxy(5,3);cout<<"---------------";
		TextColor(rand()%15+1);
		gotoxy(4,4);cout<<"1 - Play";
		TextColor(rand()%15+1);
		gotoxy(4,5);cout<<"2 - Instruction";
		TextColor(rand()%15+1);
		gotoxy(4,6);cout<<"3 - Exit";
		TextColor(15);
		gotoxy(1,tdy+3);cout<<"=>";
		gotoxy(20,tdy+3);cout<<"<=";
		char c=getch();
		if(c=='W'||c=='w'){
			if(tdy==1)
				tdy=3;
			else
				tdy--;
		}
		if(c=='S'||c=='s'){
			if(tdy==3)
				tdy=1;
			else
				tdy++;
		}
		if(c==' '||c==13){
			if(tdy==1)
				Game();
			else if(tdy==2)
				Instruction();
			else
				break;
		}
	}
	return 0;
}
