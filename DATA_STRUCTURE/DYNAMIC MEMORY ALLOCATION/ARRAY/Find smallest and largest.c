#include<stdio.h>
void largest(int arr[], int UB)
{
    int largest = arr[0];
    for(int i=0; i<=UB; i++)
    {
        if(largest<arr[i])
        {
            largest = arr[i];
        }
    }
    printf("Largest number is : %d\n", largest);
}
void smallest(int arr[], int UB)
{
    int smallest=arr[0];
    for(int i=0; i<=UB; i++)
    {
        if (smallest>arr[i])
        {
            smallest = arr[i];
        }
    }
    printf("Smallest Number is : %d", smallest);
}
int main()
{
    int arr[]= {1,2,3,4,5,6};
    largest(arr,5);
    smallest(arr,5);
}