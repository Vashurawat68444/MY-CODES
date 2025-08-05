#include<stdio.h>
#include<stdlib.h>
int main()
{
     int **mat;
    int row, column, i, j;
    printf("ENTER ROW : ");
    scanf("%d",&row);
     printf("ENTER COLUMN : ");
    scanf("%d",&column);
    mat = (int **)malloc(row * sizeof(int*));
    for(i=0; i<row; ++i)
    {
        mat[i] = (int *)malloc(column * sizeof(int));
    }
    for(i=0; i<row; ++i)
    {
        for(j=0; j<column; ++j)
        {
            printf("Type a number for <line: %d, column: %d>\t", i+1, j+1);
            scanf("%d",&mat[i][j] );
        }
    }
    printf("YOUR MATRIX IS : ");
    for(i=0; i<row; ++i)
    {
        for(j=0; j<column; ++j);
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
    }