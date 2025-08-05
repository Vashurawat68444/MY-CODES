#include<stdio.h>
void reverse(int arr[],int size)
{
    int temp;
    for(int i=0; i<size/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-i-1] = temp;
    }
}
void print_array(int arr[],int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void sub(int arr1[],int size1,int arr2[],int size2)
{
    reverse(arr1,size1);
    print_array(arr1,size1);
    reverse(arr2,size2);
    print_array(arr2,size2);
    int i,k;
    for(i=0; i<size2; i++)
    {
        if(arr1[i] >= arr2[i]){
            arr1[i] = arr1[i] - arr2[i];
        }
        else{
            k=i+1;
            while(arr1[k] == 0)
            {
                arr1[k++] = 9;
            } 
            arr1[i] = 10 + arr1[i];
            arr1[k]--;
            arr1[i] = arr1[i] - arr2[i];
        }
    }
    reverse(arr1,size1);
    print_array(arr1,size1);
}
int main()
{
    int a[3] = {5,0,0};
    int b[2] = {8,2};
    sub(a,3,b,2);
}