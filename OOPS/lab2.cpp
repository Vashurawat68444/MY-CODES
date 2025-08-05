#include<stdio.h>
void fun()
{
    static int x = 0;
    printf("%d",x);
    x++;
}
int main()
{
    fun();
    fun();
    fun();
}