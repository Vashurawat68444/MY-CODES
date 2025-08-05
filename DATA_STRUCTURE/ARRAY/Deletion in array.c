#include<stdio.h>
void deletion(int arr[], int x, int index)
{
    for (int i=index; i<=x; i++)
    {
        arr[i] = arr[i+1];

    }
}
int main()
{
    int index;
    scanf("%d",&index);
    int arr[] = {1,2,3,4};
    deletion(arr,3,index);
    for(int i = 0 ; i<=2; i++)
        printf("%d : %d\n",i,arr[i]);
}