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
       //	x=getmaxx()/2;
       //	y=getmaxy()/2;
      //x= random(10,20);
	for(i=20;i<180;i++)
	{
	     //	delay(100);
		setcolor(i/10);
		circle(i+70,i+70,10);
		line(10,10,100,100);
		delay(200);
		clrscr();
	       //	arc(x,y,0,180,i-10);
	}
	circle(i+70,i+70,50);
	line(199,299,900,299);
	delay(200);
	for(j=20;j<180;j++)
	{
	     //	delay(100);
		setcolor(i/10);
		circle(i,i,50);
		i = i-1;
	       //	line(10,10,100,100);
		delay(50);
		clrscr();
	       //	arc(x,y,0,180,i-10);
	}
	circle(i-70,i-70,50);
	line(199,299,900,299);

getch();
}
