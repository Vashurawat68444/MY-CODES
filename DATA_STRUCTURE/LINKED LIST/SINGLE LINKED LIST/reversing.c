/*
  |------------REVERSING CODE--------------------|
*/
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* create_node()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node*));
    printf("ENTER DATA : ");
    scanf("%d",&ptr -> data);
    ptr -> next = NULL;
    return ptr; 
}
struct node* create_LL(int n)
{
    if(n==0){
        printf("EMPTY LIST !");
    }else{
    struct node *newnode = create_node();
    struct node *head = newnode;
    struct node *temp = newnode;
    
    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp -> next = newnode;
        temp = temp -> next;
    }
    return head;
    }
}
void traverse(struct node *start)
{
    struct node *ptr = start;
    printf("REVERSE LINK LIST IS : ");
    while(ptr)
    {
        printf("  %d  ",ptr->data);
        ptr = ptr -> next;
    }
}
struct node* reverse(struct node *start)
{
    struct node *current, *next, *prev = NULL;
    current = start;
    while(current)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
    

}

int main()
{
    struct node *head;
    int n;
    printf("ENTER NUMBER OF NODES IN LINK LIST : ");
    scanf("%d",&n);
    head = create_LL(n);
    head = reverse(head);
    traverse(head);
}