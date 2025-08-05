#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* create_node()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA IN NODE : ");
    scanf("%d",&ptr -> data);
    ptr -> next =NULL;
    return ptr;
}
struct node* create_LL(int n)
{
    struct node *temp, *newnode, *head;
    newnode = create_node();
    temp = newnode;
    head = newnode;
    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp -> next = newnode;
        temp = temp -> next;
    }
    return head;
}
void counting(struct node *start)
{
    struct node *ptr = start;
    if(ptr==NULL)
    {
        printf("YOUR LINKED IS EMPTY !");
        exit(1);
    }
    int count=0;
    while(ptr)
    {
        count++;
        ptr = ptr -> next;
    }
       printf("NODES IN LINKED LIST : %d",count);
}
int main()
{
    int n;
    printf("ENTER NUMBER OF NODES IN LINKED LIST : ");
    scanf("%d",&n);
    struct node *head = create_LL(n);
    counting(head);
}