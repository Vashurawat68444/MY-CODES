#include<stdio.h>
void insertion(int arr[], int x, int index, int input)
{
    for (int i=4; i>=index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=input;

}
int main()
{
    int index,input;
    int arr[]= {1,2,3,4,5};
    printf("enter index and input for insertion : ");
    scanf("%d %d",&index,&input);
    insertion(arr,4,index,input);
    for (int i=0; i<=5; i++)
    {
        printf("%d : %d\n", i, arr[i]);
    }
}