#include<stdio.h>
void print_array(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int *x, int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
int partition(int arr[],int low, int high)
{
    int i=low-1;
    int pivot = arr[high];
    for(int j=low; j<high; j++)
    {
        if(arr[j]<pivot){
        i++;
        swap(&arr[i],&arr[j]);
        //int temp = arr[i];
        //arr[i] = arr[j];
        //arr[j] = temp;
        }
    }
    i++;
    swap(&pivot,&arr[i]);
    //int temp = arr[i];
    //arr[i] = pivot;
    //arr[high] = temp;
    return i;
}
void quick_sort(int arr[],int low, int high)
{
   if(low<high)
   {
     int k = partition(arr,low,high);
     quick_sort(arr,low,k-1);
     quick_sort(arr,k+1,high);
   }
  // print_array(arr,high+1);
}
int main()
{
    int x;
   
    printf("ENTER NUMBER OF ELEMENT IN ARRAY : ");
    scanf("%d",&x);
    int arr[x];
    for(int i=0;i<x;i++)
    {
        printf("ENTER ELEMENT AT INDEX %d : ",i);
        scanf("%d",&arr[i]);
    }
   // buble_sort(arr,x);
   // insertion_sort(arr,x);
   // selection_sort(arr,x);
   quick_sort(arr,0,x-1);
    print_array(arr,x);   
}