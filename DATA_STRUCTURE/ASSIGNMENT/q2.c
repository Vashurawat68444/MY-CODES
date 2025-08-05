#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *create_node()
{
    node *temp = (node*)malloc(sizeof(node));
    printf("ENTER YOUT DATA IN NODE : ");
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
    node *temp = head;
    while(temp)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
node *delete_duplicate(node *head)
{
    node *ptr1 = head,*ptr2,*ptr3;
    while(ptr1)
    {
        ptr2 = ptr1;
        ptr3 = ptr2->next;
        while(ptr3) 
        {
            if(ptr1->data == ptr3->data)
            {
                node *for_free = ptr3;
                ptr3 = ptr3->next;
                ptr2->next = ptr3;
                free(for_free);
            }else{
                ptr2 = ptr3;
                ptr3 = ptr3->next;
            }
        }

        ptr1 = ptr1->next;
    }
    return head;
}
int main()
{
    int n;
    node *head;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&n);
    head = create_LL(n);
    print_LL(head);
    head = delete_duplicate(head);
    print_LL(head);
}