#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *create_node()
{
    node *temp = (node*)malloc(sizeof(node));
    printf("ENTER DATA IN NODE : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
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
node *reverse_LL(node *head)
{
    node *current=head,*next,*prev=NULL;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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
    node *head;
    int n;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&n);
    head = create_LL(n);
    print_list(head);
    head = reverse_LL(head);
    print_list(head);
}