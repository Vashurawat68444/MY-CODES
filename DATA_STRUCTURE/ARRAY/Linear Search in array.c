#include<stdio.h>
int linear_search(int arr[], int x, int input)
{
    int i;
    for (i=0; i<x; i++)
    {
        if(arr[i]==input)
        break;
    }
    if(arr[i]==input)
    return i;
    else 
    return -1;
}
int main()
{
    //printf("input Array should be in Ascending order \n\n");
    int x,input,index;
    printf("Enter the no. of element in array : ");
    scanf("%d",&x);
    int arr[x];
    for (int i=0; i<x; i++)
    {
        printf("Enter elements at index %d : ",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter input which you want to search : ");
    scanf("%d",&input);
    
    index = linear_search(arr,x,input);
    printf("Index in array for given input : %d",index);
}

    