//WELCOME TO TURBO C++ ON WINDOWS NOW RUN YOUR FIRST PROGRAM...!!!!

//Downloaded From www.turboc8.com coded by Yogendra Singh.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
clrscr();
int gdriver = DETECT,gmode;
int x,y,i,j;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	for(i=40;i<300;i++)
	{
		delay(50);
		setcolor(i/10);
		arc(x,y,0,360,i-10);
	}
getch();
}