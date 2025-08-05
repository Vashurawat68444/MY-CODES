#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *create_node()
{
    node* temp = (node*)malloc(sizeof(node));
    printf("ENTER DATA IN NODE : ");
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
void print_middle(node *head,int n)
{
    node *temp = head;
    for(int i=0; i<(n/2); i++)
    {
        temp = temp->next;
    }
    printf("YOUR MIDDLE VALUE IS : %d",temp->data);

}
void print_list(node *head)
{
    node *temp = head;
    while(temp)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}
int main()
{
    int n;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&n);
    node *head = create_LL(n);
    print_list(head);
    print_middle(head,n);
}