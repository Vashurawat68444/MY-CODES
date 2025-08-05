#include<stdio.h>
#define size 5
int stack[size];
int top = -1;
void push(int num)
{
    if(top == size-1)
    {
        printf("YOUR STACK IS FULL !\n");
    }else{
    top++;
    stack[top] = num;
    }
}
int pop()
{
    if(top == -1)
    {
        printf("     YOUR STACK IS EMPTY !\n");
    }else{
    int popped_element = stack[top];
    top--;
    return popped_element;
    }
}
int main()
{
    char c;
    int number; // it is var for push.
    printf("<------------MENU------------->\n");
    printf("       ENTER A : PUSH \n");
    printf("       ENTER B : POP \n");
    printf("       ENTER C : EXIT \n");
    printf("---------------------------------\n");
    do
    {
        printf("     ENTER YOUR INPUT : ");
        scanf(" %c",&c);
        if(c=='A')
        {
           printf("    ENTER NUMBER FOR PUSH : ");
           scanf("%d",&number);
           push(number);
        }
        if(c == 'B')
        {
          int popped_element = pop();
          printf("     POP ELEMENT IS : %d\n",popped_element);
        }
    }while(c != 'C');
}