#include<stdio.h>
int binary_search(int arr[], int x, int input)
{
    int LB = 0, UB = x-1;
    int mid = (LB +UB)/2;
    while(arr[mid] != input && LB<=UB)
    {
        if(arr[mid]>input)
        UB=mid-1;
        else 
        LB=mid+1;
        mid=(UB+LB)/2;
    }
    if(arr[mid]==input)
    return mid;
    else return LB-1;
}
int main()
{
    printf("input Array should be in Ascending order \n\n");
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
    
    index = binary_search(arr,x,input);
    printf("Index in array for given input : %d",index);
}

