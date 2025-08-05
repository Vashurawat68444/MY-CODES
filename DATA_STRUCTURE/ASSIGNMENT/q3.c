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
void print_LL(node *head)
{
    while(head)
    {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
node *delete_last_occurence(node *head,int key)
{
    node *temp,*for_rem,*for_free;
    temp = head;
    while(temp->next)
    {
        if(temp->next->data == key)
        {
            for_rem = temp;
        }
        temp = temp->next;
    }
    for_free = for_rem->next;
    for_rem->next = for_rem->next->next;
    free(for_free);
    return head;
}
int main()
{
    int n,key;
    printf("ENTER NUMBER OF NODE : ");
    scanf("%d",&n);
    node *head = create_LL(n);
    print_LL(head);
    printf("ENTER KEY FOR DELETION : ");
    scanf("%d",&key);
    head = delete_last_occurence(head,key);
    print_LL(head);
}