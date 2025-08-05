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
    if(n==0){
        printf("YOUR LINKED LIST WAS EMPTY!");
    }
    else{
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
int main()
{
    int size;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&size);
    node* head = create_LL(size);
    traverse(head);
}
