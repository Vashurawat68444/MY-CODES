/*
   -------- FOR FINDING MIDDLE VALUE IN LINKED LIST-----------
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *create_node()
{
   struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("ENTER DATA : ");
    scanf("%d",&temp -> data);
    temp -> next = NULL;
    return temp;
}
struct node* create_LL(int n)
{
    if(n==0){
        printf("YOUR LINKED LIST IS EMPTY!");
    }else{
   struct node* head = create_node();
   struct node* temp = head;
   struct node* newnode;
    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp -> next = newnode;
        temp = temp -> next;
    }
    return head;
    }
}
struct node* mid(struct node *start)
{
    struct node *A, *B;
    A = start;
    B = start;
    while(A -> next != NULL && A -> next -> next != NULL)
    {
        A = A -> next -> next;
        B = B -> next;
    }
    return B;
}
int main()
{
    int size;
    printf("NUMBER OF NODES IN LINKED LIST : ");
    scanf("%d",&size);
    struct node* head = create_LL(size);
    struct node* middle;
    middle = mid(head);
    printf("MIDDLE VALUE IS : %d",middle -> data);
}
 