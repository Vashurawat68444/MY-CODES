/*
   <-------------------------------COUNTING-------------------------------->
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
    int count=0;
    printf("COUNT OF LINK LIST IS : ");
    while(ptr!=tell)
    {
        // printf("%d  ",ptr -> data);
        count++;
        ptr = ptr -> next;
    }
//    printf("%d  ",tell->data);
   count++;
   printf("%d",count);

}
int main()
{
    int size;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&size);               
    node* tell = create_LL(size);
    traverse(tell);
}
