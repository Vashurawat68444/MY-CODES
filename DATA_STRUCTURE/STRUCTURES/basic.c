#include<stdio.h>
#include<string.h>
int main()
{
    typedef struct student
    {
        char name[20];
        int age;
        int roll_number;
    }stud;
    stud s1,s2;
    printf("ENTER DETAIL OF S1 ------\n");
    printf("ENTER NAME OF S1 : ");
    gets(s1.name);
    printf("ENTER AGE OF S1 : ");
    scanf("%d",&s1.age);
    printf("ENTER ROLL NUMBER OF S1 : ");
    scanf("%d",&s1.roll_number);
   
    printf("ENTER DETAIL OF S2 ------\n");
    printf("ENTER NAME OF S2 : ");
    gets(s2.name);
    printf("ENTER AGE OF S2 : ");
    scanf("%d",&s2.age);
    printf("ENTER ROLL NUMBER OF S2 : ");
    scanf("%d",&s2.roll_number);
    
    printf("detail of s1 ---\n");
    puts(s1.name);
    printf("AGE : %d\n",s1.age);
    printf("ROLL NUMBER : %d\n",s1.roll_number);

    printf("detail of s2 ---\n");
    puts(s2.name);
    printf("AGE : %d\n",s2.age);
    printf("ROLL NUMBER : %d\n",s2.roll_number);

}