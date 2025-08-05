/*
   I HAVE AN DOUBT IN  THIS CODE ! CLEAR IN LAB;
*/
#include<stdio.h>
#include<stdlib.h>
#define size 10
int q1[size];
int q2[size] ;
int stack[size];
int top = -1 , f1 = -1, f2 = -1 , r1 = -1 , r2 = -1;
void push(int number)   //FIRST PUSH ELEMENT IN Q1.
{
    if(r1 == size-1)
    {
        printf("\n STACK IS FULL NOW!\n");
    }
    else if(f1 == -1 && r1 == -1)
    {
        f1++; r1++;
        q1[r1] = number;
        write_in_q2();   // AFTER EVERY ADDITION REWRITE ALL ELEMENTS OF Q1 IN Q2.
    }
    else{
        r1++;
        q1[r1] = number;
        write_in_q2();   // AFTER EVERY ADDITION REWRITE ALL ELEMENTS OF Q1 IN Q2.
    }
}
void write_in_q2()   // WRITING FUNCTION.
{
    int lim = r1;   //I DECLARE THE LIMIT FOR MAKES CONSTANT OF R1.
    while(lim != -1)
    {
        if(f2 == -1 && r2 == -1)
        {
            f2++; r2++;
            q2[r2] = q1[lim];
            lim--;   //DECREASE LIMIT ONE BY ONE TILL LIM == -1.
        }
        else{
            r2++;
            q2[r2] = q1[lim];
            lim--;   //DECREASE LIMIT ONE BY ONE TILL LIM == -1. 
        }
    }
}
int pop()   // ELEMENT ALWAYS POP FROM QUEUE 2.
{
    int for_return;   //ELEMENT FOR RETURN.
    if(f2 == r2)
    {
        for_return = q2[f2];
        f2 = -1; r2 = -1;
        return for_return;
    }
    else{
        for_return = q2[f2];
        f2++;
        return for_return;
    }
}
void display() // ELEMENT ALWAYS DISPLAY FROM QUEUE 1 BECASUE ONLY THIS QUEUE ACT AS ORIGINAL STACK .
{
    int i = f1;  // I DECLARE KIYA TAKI F1 PR EFFECT N PADE.
    if(i==-1)
    {
        printf("\nYOUR STACK IS EMPTY !\n");
    }
    printf("\nYOUR STACK IS : ");
    while(i > f1)
    {
        printf("%d  ", q1[i]);
    }
    printf("\n");
}
int main()
{
    push(1);
    push(2);
    push(3);
    display();
}