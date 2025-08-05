#include<stdio.h>
#include<string.h>
#define size 10
char stack[size];
int top = -1;
void push(char arr[]) // push operation of stsck 
{
    int n = strlen(arr);
    for(int i=0; i<n; i++)
    {
        top++;
        stack[top] = arr[i];
    }
}
char reverse() // its just a pop operation of stack
{
    printf("YOUR REVERSED STACK : ");
    while(top!=-1)
    {
        printf("%c",stack[top]);
        top--;
    }
}
int main()
{
    char arr[10];
   printf("ENTER YOUR STRING : ");
   gets(arr);
   printf("STRING IS : ");
   puts(arr);
   push(arr);
   printf("YOUR STRING LENGTH IS : %d\n",top);
   reverse();
}