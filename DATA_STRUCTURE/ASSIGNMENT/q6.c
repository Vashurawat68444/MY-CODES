#include<stdio.h>
void print_array(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
void buble_sort(int arr[],int n)
{
    int count=0;
    printf("OUTPUT IS : ");
    for(int i=0; i<n-1; i++)
    { int flag=0;
        int max=arr[i];
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                printf("(%d,%d)",arr[j],arr[i]);
                count++;
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
    printf("\ncount = %d\n",count);
    print_array(arr,n);
}
int main()
{
    int array[5] = {2,4,1,3,5};
    buble_sort(array,5);
}