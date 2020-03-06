#include<stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
class game{
	public:
	char name[50];
   
	public:
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void getup()
{
    system("cls");
    gotoxy(1,2);
    cout<<"Press X to Exit, Press Space to Jump";
    gotoxy(62,2);
    cout<<"SCORE : ";
    gotoxy(1,25);
    for(int x=0;x<79;x++)
    cout<<"-";          //straight line
}
 
int t,speed=40;
void ds(int jump=0)
{
    static int a=1;
 
    if(jump==0)
        t=0;
    else if(jump==2)
        t--;
    else t++;
    gotoxy(2,15-t);
    printf("                 ");
    gotoxy(2,16-t);
    printf("   000     000   ");
    gotoxy(2,17-t);
    printf("    000   000    ");
    gotoxy(2,18-t);
    printf("     000 000     ");
    gotoxy(2,19-t);
    printf("      000000     ");
    gotoxy(2,20-t);
	printf("     000 000     ");   
    gotoxy(2,21-t);
    printf("    000   000    ");
    gotoxy(2,22-t);
    printf("   000     000   ");
    gotoxy(2,23-t);
    if(jump==1 || jump==2){
    printf("   |||     |||   ");
    gotoxy(2,24-t);
    printf("    ||   ||      ");
    }else if(a==1)
    {
    printf("    ||||  |||    ");
    gotoxy(2,24-t);
    printf("      ||         ");
    a=2;
    }
    else if(a==2)
    {
    printf("     ||| ||      ");
    gotoxy(2,24-t);
    printf("          ||     ");
    a=1;
    }
    gotoxy(2,25-t);
    if(jump!=0){
        printf("                ");
    }
    else
    {
         
        cout<<"_________________";
    }
    delay(speed);
}
void obj()
{
    static int x=0,scr=0;
    if(x==56 && t<4)
    {
    scr=0;
    speed=40;
    gotoxy(36,8);
    cout<<"Game Over";
    getch();
    gotoxy(36,8);
    cout<<"         ";
    }
    
    gotoxy(74-x,17);
    cout<<"  --   ";
    gotoxy(74-x,18);
    cout<<"  00   ";
    gotoxy(74-x,19);
    cout<<" 0000  ";
    //x++;
    gotoxy(74-x,20);
    cout<<"0 00 0 ";
    gotoxy(74-x,21);
    cout<<"0000000 ";
    gotoxy(74-x,22);
    cout<<"00  00 ";
    gotoxy(74-x,23);
    cout<<"  00   ";
    gotoxy(74-x,24);
    cout<<"  00 " ;
    x++;
    if(x==73)
    {
    x=0;
    scr++;
    gotoxy(70,2);
    cout<<"     ";
    gotoxy(70,2);
   cout<<scr;
    if(speed>20)
        speed--;
    }
}
};
int main()
{    game g;
     g.gotoxy(40,10);
     cout<<"WELCOME TO THE GAME OF BUMBLE BEE!"<<endl;
      g.gotoxy(41,13);
     cout<<"CROSS AS MANY HURDLES AS POSSIBLE "<<endl;
     g.gotoxy(42,15);
     cout<<"WHAT IS YOUR NAME?"<<endl;
     g.gotoxy(46,18);
     
      cin>>g.name;
      getch();
      system("cls");
    
      cout<<"ALL THE BEST"<<g.name<<endl;
    system("mode con: lines=29 cols=82");
    char ch;
    int i;
    g.getup();
    while(true)
    {
        while(!kbhit())
        {
            g.ds();
            g.obj();
        }
        ch=getch();
        if(ch==' ')
        {
            for(i=0;i<10;i++)
            {
            g.ds(1);
            g.obj();
            }
            for(i=0;i<10;i++)
            {
            g.ds(2);
            g.obj();
            }
        }
        else if (ch=='x')
            return(0);
    } 
     
}
