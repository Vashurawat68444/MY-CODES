#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *create_node()
{
    node *temp = (node*)malloc(sizeof(node));
    printf("ENTER DATA IN YOUR NODE : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}
node *create_LL(int n)
{
    node *temp,*newnode,*head;
    temp = create_node();
    head = temp;
    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}
node *rotate_LL(node *head,int key)
{
    node *temp = head;
    for(int i=1; i<key; i++)
    {
        temp = temp->next;
    }
    node *newhead = temp->next;
    temp->next = NULL;
    temp = newhead;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = head;
    return newhead;
}
void print_list(node *head)
{
    while(head)
    {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    int n,key;
    printf("ENTER NUMBER NODE : ");
    scanf("%d",&n);
    node *head = create_LL(n);
    print_list(head);
    printf("ENTER THE KEY FOR ROTATE THE LINK LIST : ");
    scanf("%d",&key);
    node * newhead = rotate_LL(head,key);
    print_list(newhead);
}