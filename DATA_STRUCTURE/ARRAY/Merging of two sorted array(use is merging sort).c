#include<stdio.h>
void print_array(int arr[], int x)
{
   for( int i=0; i<x; i++)
   {
       printf("%d\t",arr[i]);
   }
}
void merge_array(int arr1[], int x1, int arr2[], int  x2, int arr3[], int x3)
{
    int i=0,j=0;
    int k=0;
    while(i<x1 && j<x2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
           arr3[k]=arr2[j];
           j++; k++;
        }
    }
    while(i==x1 && j<x2)
    {
       
       arr3[k]=arr2[j];
       j++; k++;
    }
    while(j==x2 && i<x1)
    {
        
           arr3[k]=arr1[i];
        i++; k++;
    }
    printf("YOUR SORTED ARRAY IS : ");
    print_array(arr3,k);
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