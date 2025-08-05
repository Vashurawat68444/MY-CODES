#include<stdio.h>
int main()
{
    int arr[100];
    int x, input, index;
    printf("ENTER NUMBER OF INPUTS : ");
    scanf("%d",&x);
    for(int i=0; i<x; i++)
    {
        printf("ENTER ELEMENTS IN ARRAY AT INDEX %d : ",i);
        scanf("%d",&arr[i]);
    }
    printf("ENTER INPUT AND INDEX FOR INSERTION : ");
    scanf("%d %d",&input, &index);
    for(int i = x -1; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = input;
    printf("    ELEMENTS OF FINAL ARRAY AFTER INSERTION   \n");
    for(int i=0; i<x+1; i++)
    {
        printf("ELEMENTS AT INDEX %d : %d \n",i,arr[i]);
    }
}