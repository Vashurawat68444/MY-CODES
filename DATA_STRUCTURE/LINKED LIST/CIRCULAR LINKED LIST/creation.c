/*
   <------------CREATION OF CIRCULAR LINK LIST----------->
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
node *create_node()
{
    node *temp;
    temp = (node*)malloc(sizeof(node));

    printf("ENTER DATA : ");
    scanf("%d",&temp -> data);
    temp -> next = NULL;
    return temp;
}
node* create_LL(int n)   //its return tell pointer means address of last node!
{
    node* head = create_node();
    node* temp = head;
    node* newnode;
    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp -> next = newnode;
        temp = temp -> next;
    }
    temp -> next = head;
    return temp;
}
void traverse(node *tell)
{
    node* ptr = tell->next;
    printf("ELEMENT OF LINK LIST IS : ");
    while(ptr!=tell)
    {
        printf("%d  ",ptr -> data);
        ptr = ptr -> next;
    }
   printf("%d  ",tell->data);
}
int main()
{
    node* tell = create_LL(5);
    traverse(tell);
}
