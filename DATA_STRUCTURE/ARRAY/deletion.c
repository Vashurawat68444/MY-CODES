#include<stdio.h>
int main()
{
    int index, n;
    printf("ENTER INDEX AND SIZE OF ARRAY : ");
    scanf("%d %d",&index, &n);
    int arr[n];  //inddex for deletion
    for(int i=0; i<n; i++)
    {
        printf("ENTER ELEMENT AT INDEX %d : ",i);
        scanf("%d",&arr[i]);
    }
    for(int i=index; i<n; i++)
    {
        arr[i] = arr[i+1];
    }
    for(int i=0; i<n-1; i++)
    {
        printf("ELEMENT AT INDEX %d : %d\n",i,arr[i]);

    }
}