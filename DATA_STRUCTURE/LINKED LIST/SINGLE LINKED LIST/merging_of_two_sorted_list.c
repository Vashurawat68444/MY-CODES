/*
 |---------------------MERGING OF TWO SORTED SINGLE LINK LIST-------------------|
*/
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
struct node* merge(struct node *A, struct node *B)
{
    struct node *temp, *p1, *p2, *p3;
    temp = (struct node*)malloc(sizeof(struct node));
    p1 = A;
    p2 = B;
    p3 = temp;//create for returning head of sorted list
    while(p1 != NULL && p2 != NULL)
    {
        if(p1 -> data < p2 -> data)
        {
            p3 -> next = p1;
            p1 = p1 -> next;
        }
        else{
            p3 -> next = p2;
            p2 = p2 -> next;
        }
        p3 = p3 -> next;
    }
    while(p1 != NULL)
    {
        p3 -> next = p1;
        p1 = p1 -> next;
        p3 = p3 -> next;
    }
    while(p2 != NULL)
    {
        p3 -> next = p2;
        p2 = p2 -> next;
        p3 = p3 -> next;
    }
    return temp -> next;

}
int main()
{
    int size1,size2;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d %d",&size1,&size2);
     printf("ENTER ELEMENT FOR LIST 1 : \n");
    node* head1 = create_LL(size1);
    printf("ENTER ELEMENT FOR LIST 2 : \n");
    node* head2 = create_LL(size2);
    printf("\n");
    traverse(head1);
    printf("\n");
    traverse(head2);
    printf("\n");
    node *head = merge(head1,head2);
    traverse(head);

}
