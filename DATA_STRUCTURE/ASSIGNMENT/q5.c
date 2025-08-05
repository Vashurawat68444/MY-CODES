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
    printf("ENTER DATA : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}
node *create_LL(int n)
{
    node *temp,*head,*newnode;
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
void print_LL(node *head)
{
    while(head)
    {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void sort_LL(node *head)
{
    node* ptr = head;
    int count[3] = {0,1,2};
    while(ptr)
    {
        count[ptr->data]++;
        ptr = ptr->next;
    }
    int i=0;
    ptr = head;
    while(ptr)
    {
        if(count[i]==0)
        {
            i++;
        }
        else{
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}
int main()
{
    int n;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&n);
    node *head = create_LL(n);
    print_LL(head);
    sort_LL(head);
    print_LL(head);
}
