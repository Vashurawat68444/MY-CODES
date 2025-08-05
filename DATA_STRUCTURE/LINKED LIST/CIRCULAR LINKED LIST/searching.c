/*
   <------------------------------------------SEARCHING------------------------------------------------>
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
   printf("%d \n",tell->data);
}
int searching(struct node *tell,int input)
{
    int index=1;
    struct node *temp = tell->next;
    while(temp->data!=input && temp!=tell)
    {
        index++;
        temp=temp->next;
    }
    if(temp->data==input)
    {
        return index;
    }else
    return 0;
}
int main()
{
    int size,position;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&size);
    node* tell = create_LL(size);
    traverse(tell);
    int input,index;
    printf("ENTER INPUT FOR SEARCH IN LINK LIST : ");
    scanf("%d",&input);
    index = searching(tell,input);
    if(index==0)
    {
        printf("YOUR ELEMENT WAS NOT FOUND !");
    }else
    {
        printf("YOUR INDEX IS : %d",index);
    }
}
