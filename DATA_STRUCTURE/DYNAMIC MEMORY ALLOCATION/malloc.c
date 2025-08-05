#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    printf("enter the number of integer for allocation : ");
    scanf("%d",&n);
    int *p = (int *)malloc(n*sizeof(int));
    if(p==NULL)
    {
        printf("MEMORY IS NOT AVAILABLE !");
        exit(1);
    }
    printf("ENTER YOUR VALUES IN DYNAMIC MEMORY : ");
    for(i=0; i<n; i++)
    {
       scanf("%d",p+i);
    }
    for(i=0; i<n; i++)
    {
        printf("%d\n",(*(p+i))*2);
    }
}