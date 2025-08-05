#include<stdio.h>
void merge_sort(int arr[], int LB, int UB)
{
    if(LB<UB)
    {
        int mid = (UB+LB)/2;
        merge_sort(arr,LB,mid);
        merge_sort(arr,mid+1,UB);
        merge(arr,LB,mid,UB);
    }
    //print_array(arr,UB-LB+1);
}
void merge(int arr[], int LB, int mid, int UB)
{

    int n1 = mid-LB+1;
    int n2 = UB-mid;
    int  list1[n1];
    int list2[n2];
    for(int i=0; i<n1; i++)
    {
        list1[i]=arr[LB+1];
    }
    for(int j=0; j<n2; j++)
    {
        list2[j]=arr[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=LB;
    while(i<n1 && j<n2)
    {
        if(list1[i]<=list2[j])
        {
            arr[k]=list1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=list2[j];
            j++;
            k++;
        }
    }
    while( j<n2)
    {
        arr[k]=list2[j];
        j++;
        k++;
    }
    while(i<n1)
    {
        arr[k]=list1[i];
        i++;
        k++;
    }

}
void print_array(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main()
{
    int x;
    printf("Enter the no of element in arr : ");
    scanf("%d %d", &x);
    int arr[x];
    for (int i=0; i<x; i++)
    {
        printf("Enter the element for arr at index %d : ",i);
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,x-1);
    printf("Your sorted array is ; ");
}