#include<graphics.h>

int main()
{
    int gd=DETECT , gm;
    initgraph(&gd,&gm,(char*)"");
    line(100,200,500,200);
    getch();
    closegraph();
    return 0;
}