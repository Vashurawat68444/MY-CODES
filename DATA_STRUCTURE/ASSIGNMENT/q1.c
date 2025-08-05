#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char name[10],building_name;
    int emp_id,cabin_no,bonous_salery;
    struct node *next;
}employe;
struct node* create_node()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node)); 
    printf("ENTER NAME : ");
    gets(temp->name);   
    printf("BUILDING NAME, ID, CABIN NUMBER, BONOUS SALERY : ");
    scanf(" %c %d %d %d",&temp->building_name, &temp->emp_id, &temp->cabin_no, &temp->bonous_salery);
    
    temp->next = NULL;
    return temp;
}
struct node* create_LL(int n)
{
    struct node *temp,*head,*newnode;
    temp = create_node();
    head = temp;

    for(int i=0; i<n-1; i++)
    {
        newnode = create_node();
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}
int main()
{
    printf("NOW WE ARE STORING DATA OF EMPLOYE \n");
    int n;
    printf("ENTER NUMBER OF EMPLOYE : ");
    scanf("%d",&n);
    struct node *head = create_LL(n);
}