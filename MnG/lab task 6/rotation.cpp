#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void rectangle_rotate(int cx, int cy, int w, int h, int angle=0)
{
    double theta = (double)(angle%180)*M_PI/180;
    int dx = w/2;
    int dy = h/2;
    int point[8]={
        (-dx*cos(theta) - dy*sin(theta) + cx),
        (-dx*sin(theta) + dy*cos(theta) + cy),
        (dx*cos(theta) - dy*sin(theta) + cx),
        (dx*sin(theta) + dy*cos(theta) + cy),
        (dx*cos(theta) + dy*sin(theta) + cx),
        (dx*sin(theta) - dy*cos(theta) + cy),
        (-dx*cos(theta) + dy*sin(theta) + cx),
        (-dx*sin(theta) - dy*cos(theta) + cy)
    };
    for(int i=0; i<8; i+=2)
    {
        line(point[i], point[i+1], point[(i+2)%8],point[(i+3)%8]);
    }
}
int main()
{
    int gd = DETECT, gm;
    int angle;
    printf("ENTER THE ANGLE FOR ROTATION : ");
    scanf("%d",&angle);
    initgraph(&gd ,&gm , (char*)"");
    rectangle_rotate(200,200,100,100,angle);
    getch();
    closegraph();
    return 0;
}