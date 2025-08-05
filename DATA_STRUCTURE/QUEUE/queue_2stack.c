/*
   DOUBT IN THIS QUESTION;
*/
#include<stdio.h>
#define size 10
int s1[size];
int s2[size];
int t1 = -1;
int t2 = -1;

void enqueue(int number)
{
    t1++;
    if (t1 == 10)
    {
        printf("\nSTACK IS FULL\n");
    }
    else
    {
        s1[t1] = number;
        write_in_s2();
    }
}
void write_in_s2()
{
    int lim = t1;
    while( lim != -1 )
    {
        t2++;
        if(t2 == 10)
        {
            printf("\nSTACK IS FULL.\n");
        }
        else{
            s2[t2] = s1[lim];
            lim--;
        }
    }
}
int pop()
{
    int for_return;
    for_return = s2[t2];
    t2--;
    return for_return;
}
void display()
{
    int i = 0;
    printf("\nYOUR STACK IS : ");
    while( i <= t1 )
    {
        printf("%d  ",s1[i]);
        i++;
    }
}
int main()
{
    push(10);
    push(20);
    push(20);
}