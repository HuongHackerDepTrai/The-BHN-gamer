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
char c1=186,c2=205,cg1=203,cg2=202,O=254,c=219;
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
void WIN(){
	gotoxy(10,11);cout<<"�   �   ���   �   �      �   �   �  �  ��  �";
	gotoxy(10,12);cout<<" � �   �   �  �   �      �   �   �  �  � � �";
	gotoxy(10,13);cout<<"  �    �   �  �   �       � � � �   �  � � �";
	gotoxy(10,14);cout<<"  �    �   �  �   �       � � � �   �  � � �";
	gotoxy(10,15);cout<<"  �     ���    ���         �   �    �  �  ��";
}
void LOSE(){
	gotoxy(10,11);cout<<"�   �   ���   �   �      �     ���    ����  �����";
	gotoxy(10,12);cout<<" � �   �   �  �   �      �    �   �  �      �";
	gotoxy(10,13);cout<<"  �    �   �  �   �      �    �   �   ���   �����";
	gotoxy(10,14);cout<<"  �    �   �  �   �      �    �   �      �  �";
	gotoxy(10,15);cout<<"  �     ���    ���       ����  ���   ����   �����";
}
int Build(char G[7][71]){
	for(int i=0;i<7;i++){
		for(int j=0;j<71;j++){
			if(i%2==0){
				G[i][j]=c2;
			}
			else
				G[i][j]=' ';
		}
	}
	for(int i=1;i<71;i++){
		if(i%2==1){
			int n=rand()%3*2+1;
			if(n==3){
				if(rand()%2==0){
					G[n][i]=c1;
					G[n+1][i]=cg2;
					G[n-1][i]=cg1;
				}
			}
			else if(n==1||n==5){
				if(rand()%2==0){
					G[1][i]=c1;
					G[2][i]=cg2;
					G[0][i]=cg1;
				}
				if(rand()%2==0){
					G[5][i]=c1;
					G[6][i]=cg2;
					G[4][i]=cg1;
				}
			}
		}
	}
	for(int i=0;i<7;i++){
		gotoxy(10,i+3);
		for(int j=0;j<71;j++){
			TextColor(rand()%15+1);
			cout<<G[i][j];
		}
	}
	gotoxy(8,3);cout<<1;
	gotoxy(8,5);cout<<2;
	gotoxy(8,7);cout<<3;
	gotoxy(8,9);cout<<4;
	int n=rand()%4;
	gotoxy(83,3);
	if(n==0)cout<<"Win";
	else cout<<"Lose";
	gotoxy(83,5);
	if(n==1)cout<<"Win";
	else cout<<"Lose";
	gotoxy(83,7);
	if(n==2)cout<<"Win";
	else cout<<"Lose";
	gotoxy(83,9);
	if(n==3)cout<<"Win";
	else cout<<"Lose";
	int j=n*2;
	for(int i=70;i>=0;i--){
		if(G[j][i]==cg2){
			j=j-2;
		}
		else if(G[j][i]==cg1){
			j=j+2;
		}
	}
	return j/2+1;
}
void Game(){
	system("cls");
	char G[7][71];
	int win;
	int P;
	win=Build(G);
	char choose=' ';
	int t=11;
	gotoxy(7,15);cout<<"Press Esc to exit";
	gotoxy(3,10);cout<<"Choose your way by pressing the number";
	for(int i=0;i<=200;i++){
		gotoxy(30,20);cout<<"Time: "<<t<<" ";
		if(kbhit()){
			choose=getch();
			if(choose=='1'||choose=='2'||choose=='3'||choose=='4'||choose==27){
				break;
			}
		}
		if(i%20==0)
			t--;
		Sleep(40);
	}
	gotoxy(7,15);cout<<"                 ";
	gotoxy(3,10);cout<<"                                      ";
	if(choose!=27){
		if(t==0){
			gotoxy(30,20);cout<<"Time out!!!";
			Sleep(2000);
			gotoxy(30,20);cout<<"           ";
		}
		if(choose=='1')
			P=1;
		else if(choose=='2')
			P=2;
		else if(choose=='3')
			P=3;
		else if(choose=='4')
			P=4;
		else
			P=rand()%4+1;
		gotoxy(1,(P-1)*2+3);cout<<"You =>";
		int temp=(P-1)*2;
		int temp2;
		if(P!=win){
			temp2=(win-1)*2;
		}
		else if(P==win){
			for(;;){
				temp2=rand()%4+1;
				if(temp2!=win)
					break;
			}
			temp2=(temp2-1)*2;
		}
		int MS=rand()%14+1;
		for(int i=0;i<71;i++){
			//Robot
			TextColor(MS);
			gotoxy(i+10,temp2+3);
			cout<<O;
			if(G[temp2][i]==cg1){
				gotoxy(i+10,temp2+3);cout<<c;
				gotoxy(i+10,temp2+4);cout<<c;
				gotoxy(i+10,temp2+5);cout<<c;
				temp2+=2;
			}
			else if(G[temp2][i]==cg2){
				gotoxy(i+10,temp2+1);cout<<c;
				gotoxy(i+10,temp2+2);cout<<c;
				gotoxy(i+10,temp2+3);cout<<c;
				temp2-=2;
			}
			//Player
			TextColor(15);
			gotoxy(i+10,temp+3);
			cout<<O;
			if(G[temp][i]==cg1){
				gotoxy(i+10,temp+3);cout<<c;
				gotoxy(i+10,temp+4);cout<<c;
				gotoxy(i+10,temp+5);cout<<c;
				temp+=2;
			}
			else if(G[temp][i]==cg2){
				gotoxy(i+10,temp+1);cout<<c;
				gotoxy(i+10,temp+2);cout<<c;
				gotoxy(i+10,temp+3);cout<<c;
				temp-=2;
			}
			Sleep(80);
		}
		gotoxy(88,temp+3);cout<<"<= You";
		if(P==win){
			for(int i=0;i<100;i++){
				TextColor(rand()%15+1);
				WIN();
				Sleep(50);
			}
		}
		else if(P!=win){
			TextColor(15);
			for(int i=0;i<100;i++){
				TextColor(8);
				LOSE();
				Sleep(50);
			}
		}
	}
}
int main(int argc, char** argv) {
	DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
	setFontSize(20);
	resizeConsole(1000,500);
	srand(time(NULL));
	Game();
	return 0;
}
