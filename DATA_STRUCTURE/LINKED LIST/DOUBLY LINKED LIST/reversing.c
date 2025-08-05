/*
  <-----------------------THIS CODE DOES USE FOR CREATING DOUBLY LINKED LIST----------------------->
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev, *next;
};
struct node* create_node()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("ENTER ELEMENT IN LINKED LIST : ");
    scanf("%d",&ptr -> data);
    ptr -> next = NULL;
    ptr -> prev = NULL;
    return ptr;
}
struct node* create_LL(int n)
{
    struct node *temp = create_node();
    struct node *head, *newnode;
    head = temp;
  //  next = newnode -> next;
  //  prev = newnode -> prev;
    for(int i=1; i<n; i++)
    {
        newnode = create_node(); //VERY CAREFUL AT LINE NUMBER 26,27,28,29;
        newnode -> prev = temp;
        temp -> next = newnode;
        temp = temp -> next;
       
    }
    return head;
}
void traverse(struct node *start)
{
   struct node *temp = start;
   if (temp == NULL)
   {
     printf("LINK LIST WAS EMPTY ! \n");
     exit(1);
   }
   printf("YOUR LINK LIST IS : ");
   while(temp)
   {
     printf("%d\t",temp -> data);
     temp = temp -> next;
   }
}
struct node* reversing(struct node *head)
{
    struct node *current = head;
    struct node *temp = NULL;
    while(current != NULL)
    {
        temp = current -> prev;
        current -> prev = current -> next ;
        current->next=temp;
        current = current->prev;
    }
    if(temp!=NULL)
    {
        head = temp->prev;
    }
    return head;
}
int main()
{
    int n;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&n);
    struct node *head = create_LL(n);
    traverse(head);
    printf("\n");
    head = reversing(head);
    traverse(head);
}