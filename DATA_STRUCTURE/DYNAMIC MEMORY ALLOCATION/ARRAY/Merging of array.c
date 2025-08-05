#include<stdio.h>
void merge_array(int arr1[], int x1, int arr2[], int x2, int arr3[], int x3)
{
    for (int i=0; i<x1; i++)
    {
        arr3[i] = arr1[i];
    }
    for (int i=x1; i<x3; i++)
    {
        arr3[i] = arr2[i-x1];
    }
    printf("Merg array is : ");
    for (int i=0; i<x3; i++)
    {
        printf("%d\t",arr3[i]);
    }
}
int main()
{
   int x, y;
   printf("Enter the no of element for arr1 and arr2 : ");
   scanf("%d %d", &x, &y);
   int arr1[x], arr2[y], arr3[x+y];
   for (int i=0; i<x; i++)
   {
       printf("Enter the element for arr1 at index %d : ",i);
       scanf("%d",&arr1[i]);
   }
   for (int i=0; i<y; i++)
   {
       printf("Enter the element for arr2 at index %d : ",i);
       scanf("%d",&arr2[i]);
   }
   merge_array(arr1,x,arr2,y,arr3,x+y);
}