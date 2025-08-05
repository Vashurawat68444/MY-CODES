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
struct node* merge_sort(struct node *start)
{
    struct node *head1,*head2,*head,*middle;
    if(start -> next == NULL || start == NULL)
    {
       return head;
    }
    else{
   
    head1 = start;
    middle = mid(head1);
    head2 = middle->next;
    middle->next=NULL;
    head1 = merge_sort(head1);
    head2 = merge_sort(head2);
    head = merge(head1,head2);
    return head;
    }
  
}
void traverse(struct node *start)
{
    struct node *temp = start;
    printf("YOUR SORTED LIST IS : ");
    while(temp)
    {
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int main()
{
    int size;
    printf("NUMBER OF NODES IN LINKED LIST : ");
    scanf("%d",&size);
    struct node *head;
    head = create_LL(size); 
    head = merge_sort(head);
    traverse(head);
}
 