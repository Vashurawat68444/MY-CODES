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
node* create_LL(int n)
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
    return head;
}
void traverse(node *start)
{
    node* ptr = start;
    printf("ELEMENT OF SINGLEN LINK LIST IS : ");
    while(ptr)
    {
        printf("%d\t",ptr -> data);
        ptr = ptr -> next;
    }
}
node* addbeg(node *head)
{
    printf("NODE TO BE ADDED IN BEGENING !\n");
    node* newnode = create_node();
    newnode->next=head;
    head = newnode;
    traverse(head);
    return head;
}
node* addatend(node* head)
{
    printf("NODE TO BE ADDED IN LAST !\n");
    node* ptr = head;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    node* newnode = create_node();
    ptr -> next = newnode;
    //newnode -> next = NULL;
    traverse(head);
    return head;
}
node* addatpos(node* head, int pos)
{
    node* newnode = create_node();
    node* temp = head;
    for(int i=1; i<pos-1; pos++)
    {
        temp = temp ->next;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
    traverse(head);
    return head;

}
int main()
{
    int size;
    printf("ENTER THE NUMBER OF NODES IN LINK LIST : ");
    scanf("%d",&size);
    node* head = create_LL(size);
    //addbeg(head);
    //traverse(head);
    //addatend(head);
    //addatpos(head,pos);
    
}
