/*
  --------------DOUBT IN IT---------------
*/
#include<stdio.h>
#include<string.h>
#define size 10
int stack[size];
int top = -1;
void push(char input)
{
    top++;
    stack[top] = input;
}
char pop()
{
    if(top == -1)
    {
        printf("\nYOUR STACK IS EMPTY !\n");
    }else{
        char popped_element = stack[top];
        top--;
        return popped_element;
    }
}
int pair_matching(char charecter_1, char charecter_2)
{
    if((charecter_1='(') && (charecter_2=')'))
    return 1;
    if((charecter_1='[') && (charecter_2=']'))
    return 1;
    if((charecter_1='{') && (charecter_2='}'))
    return 1;
}
void check_balencing(char arr[])
{
    int i=0; int flag=0; char popped_element;
    while(i!=10)
    {
        if((arr[i]='(') || (arr[i]='{') || (arr[i]='['))
        {
            push(arr[i]);
        }
        else if((arr[i]=')') || (arr[i]='}') || (arr[i]=']'))
        {
           flag = pair_matching(stack[top],arr[i]);
           if(flag==1)
           {
           printf("\npair '%c' and '%c' was matched\n",stack[top],arr[i]);
           popped_element = pop();
           }
           else
           printf("\npair was not matched\n");
        }
        i++;
    }
    if(top == -1)
    printf("\n EXPRESSION WAS BALENCED \n");
    else{
        printf("\n EXPRESSION WAS UNBALENCED \n");
    }
}
int main()
{
    char arr[10]; 
    printf("YOUR EXPRESSION IS : ");
    gets(arr);
    printf("YOUR EXPRESSION IS IN ARRAY NOW : ");
    puts(arr);   
    check_balencing(arr);
}