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
        printf("%d",arr[i]);
    }
    // printf("\n");
}
void sub(int arr1[],int size1,int arr2[],int size2)
{
    reverse(arr1,size1);
    // print_array(arr1,size1);
    reverse(arr2,size2);
    // print_array(arr2,size2);
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
    reverse(arr2,size2);
    // print_array(arr1,size1);
}
void div(int arr1[],int size1,int arr2[],int size2)
{
    int i = 0;
    while(i >= 0)
    {
        int k = 0;
        int flag = 0;
        // print_array(arr1,size1); printf(" - "); print_array(arr2,size2); printf(" = ");
        sub(arr1,size1,arr2,size2);
        // print_array(arr1,size1);
        // printf("\n");
        i++;
        while(k<size1)
        {
            if(arr1[k] != 0)
              flag = 1;
            k++;
            if(flag == 1)
              break;
        }
        if(flag == 0)
          break;
    }
    printf("%d",i);
}
int main()
{
    int a[5] = {5,5,5,5,0};
    int b[2] = {5,0};
    div(a,5,b,2);
    // sub(a,3,b,2);
}