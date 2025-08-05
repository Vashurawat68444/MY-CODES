#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int gd = DETECT, gm;
int n, xs[100], ys[100],i,tx,ty;

void draw()
{
    for(int i=0; i<n; i++)
    {
        line(xs[i],ys[i],xs[(i+1)%n],ys[(i+1)%n]);
    }
}
void translate()
{
    for(int i=0; i<n; i++)
    {
        xs[i] += tx;
        ys[i] += ty;
    }
}
int main()
{   
    printf("ENTER THE NUMBER SIDES : ");
    scanf("%d",&n);
    printf("ENTER THE CORDINATES FOR ALL VERTICES : ");
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&xs[i],&ys[i]);
    }
    printf("ENTER THE TRANSNLATION FACTOR IN X AND Y DIRECTION : ");
    scanf("%d %d",&tx,&ty);
    initgraph(&gd, &gm, (char*)"");

    setcolor(BLUE);
    draw();

    translate();

    setcolor(YELLOW);
    draw();

    getch();
    closegraph();
    return 0;
}