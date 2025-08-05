#include<stdio.h>
int main()
{
    typedef struct information
    {
       char Fathers_name[20];
       char Costumer_name[20];
       int Year_of_birth;
    }info;
    info c1,c2;
    printf("ENTER DETAIL OF CLIENT 1 ----\n");
    printf("Enter father's name : ");
    gets(c1.Fathers_name);
    printf("Enter coustumer name : ");
    gets(c1.Costumer_name);
    printf("Enter year of birth : ");
    scanf("%d",&c1.Year_of_birth);

    printf("detail of c1 ----\n");
    printf("father name is : %s \n",c1.Fathers_name);
    printf("costumer name : %s \n",c1.Costumer_name);
    printf("year of birth : %d \n",c1.Year_of_birth);

    printf("ENTER DETAIL OF CLIENT 2 ----\n");
    printf("Enter father's name : ");
    gets(c2.Fathers_name);
    printf("Enter coustumer name : ");
    gets(c2.Costumer_name);
    printf("Enter year of birth : ");
    scanf("%d",&c2.Year_of_birth);

    printf("detail of c1 ----\n");
    printf("father name is : %s \n",c2.Fathers_name);
    printf("costumer name : %s \n",c2.Costumer_name);
    printf("year of birth : %d \n",c2.Year_of_birth);
}