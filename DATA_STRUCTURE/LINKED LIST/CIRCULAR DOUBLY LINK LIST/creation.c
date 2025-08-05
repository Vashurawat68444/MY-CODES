/*
  <-----------------------THIS CODE DOES USE FOR CREATING CIRCULAR DOUBLY LINKED LIST----------------------->
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
    if(n==0){
    printf("YOUR LINKED LIST WAS EMPTY !\n");
    }else{
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
    temp -> next = head;
    head -> prev =temp;
    return head;
    }
}
void traverse(struct node *start)
{
   struct node *temp = start -> next;
   if (temp == NULL)
   {
     printf("LINK LIST WAS EMPTY ! \n");
     exit(1);
   }
   printf("YOUR LINK LIST IS : ");
   printf("%d  ",start -> data);
   while(temp->next != start->next)
   {
     printf("%d  ",temp -> data);
     temp = temp -> next;
   }
}
int main()
{
    int n;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&n);
    struct node *head = create_LL(n);
    traverse(head);
}