/*
  |--------------CREATION OF MATTRIX BY USING DYNAMIC MEMORY ALLOCATION----------------|
*/
#include<stdio.h>
#include<stdlib.h>
void saddel_point(int *arr, int row, int column)
{
    int f=0, max,min,i,j,k,c;
    for(i=0; i<row; i++)
    {
        min =arr[i*column];
        c=0;
        for(j=0; j<column; j++)
        {
            if(arr[i*column + j]<min)
            {
                min = arr[i*column + j];
                c = j;
            }
        }

        max = 0;
        for(k=0; k<column; k++)
        {
            if(arr[k*column + c]>max)
            {
                max=arr[k*column+c];
            }
        }
        if(max==min)
        {
            printf("saddel pinot is : %d",max);
            f=1;
        }
    }
    if(f==0)
    {
        printf("NO SADDEL POINT !");
    }

}
int main()
{
    int row,column;
    printf("ENTER ROW AND COLUMN : ");
    scanf("%d %d",&row , &column);
    int *ptr = (int*)malloc((row*column)*sizeof(int));

    for(int i=0; i<(row*column); i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("YOUR MATRIX IS : \n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d  ",ptr[i*column + j]);
        }
        printf("\n");
    }
    saddel_point(ptr,row,column);
}
