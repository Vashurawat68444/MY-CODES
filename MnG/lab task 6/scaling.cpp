#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<math.h>
int gd = DETECT, gm;
int n , x[100] ,  y[100] ,i ;
float sfx, sfy;
void draw()
{
    for(i=0; i<n; i++)
    {
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
    }
}
void scale()
{
    for(i=0 ; i<n; i++)
    {
        x[i] = x[0] + (int)(float)(x[i] - x[0]*sfx);
        y[i] = y[0] + (int)(float)(y[i] - x[0]*sfy);
    }
}
int main()
{   
    printf("ENTER NO OF SIDE : ");
    scanf("%d",&n);
    printf("ENTER CORDINATE(X,Y) FOR ALL VERTEX : ");
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        // scanf("%d",&y[i]);
    }
    printf("ENTER OF SCALING FACTIOR sfx AND sfy : ");
    scanf("%d %d",&sfx,&sfy);

    initgraph(&gd,&gm,(char*)"");
    cleardevice();
    setcolor(RED);
    draw();
    scale();
    setcolor(YELLOW);
    draw();
    getch();
    closegraph();
    return 0;
}