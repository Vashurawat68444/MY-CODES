#include<stdio.h>
int main()
{
    int num1,num2;
    printf("ENTER SIZE OF ARRAY 1 AND 2 RESPECTIVELY : ");
    scanf("%d %d",&num1,&num2);
    int arr1[num1];
    int arr2[num2];
    for(int i=0; i<num1; i++)
    {
        printf("ENTER DATA FOR ARRAY 1 : ");
        scanf("%d",&arr1[i]);
    }
    for(int i=0; i<num2; i++)
    {
        printf("ENTER DATA FOR ARRAY 2 : ");
        scanf("%d",&arr2[i]);
    }
    printf("INTERSECTION OUTPUT IS : ");
    for(int i=0; i<num1; i++)
    {
        for(int j=0; j<num2; j++)
        {
            if(arr1[i] == arr2[j])
            {
                printf("%d  ",arr1[i]);
            }
        }
    }
}