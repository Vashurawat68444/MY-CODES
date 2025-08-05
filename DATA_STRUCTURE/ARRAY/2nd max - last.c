#include<stdio.h>
void difference (int arr[], int UB)
{
    int max1 = arr[0];
    int difference;
    int max2 = arr[0];
    for(int i=1; i<=UB; i++)
    {
        if(max1<arr[i])
        {
            max1 = arr[i];
        }
    }
    
    for (int i=1; i<=UB; i++)
    {
        if( max2<=max1 && max2<arr[i] && arr[i] != max1)
            max2  = arr[i];
    }
    printf("second largest is : %d\n", max2);
    printf("last number is : %d\n",arr[UB]);
    if (max2>arr[UB])
    difference = max2 - arr[UB];
    else
    difference = arr[UB] - max2;
    printf("difference between second largest and last number of array : %d", difference);
}

int main()
{
    int arr[]= {1,2,3,8,5,6,12,89,35,7};
    difference(arr,9);

}