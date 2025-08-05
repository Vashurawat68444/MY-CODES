/*
     -----------------------THIS CODE DOES USE FOR INSERTION IN DOUBLY LINKED LIST-----------------------
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
   printf("\n\n");
}
struct node* insertion_at_beg(struct node *start)
{
    struct node *ptr, *temp;
    temp = start;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("ENTER YOUR FOR INSERTION ELEMENT AT BEGINING : ");
    scanf("%d",&ptr -> data);
    ptr -> next = temp;
    temp -> prev = ptr;
    return ptr;
}
struct node* insertion_at_end(struct node *start)
{
    struct node *ptr, *temp;
    temp = start;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("ENTER YOUR FOR INSERTION ELEMENT AT END : ");
    scanf("%d",&ptr -> data);
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = ptr;
    ptr -> prev = temp;
    return start;
}
struct node* insertion_at_position(struct node *start, int position)
{
    struct node *temp = start;
   struct node *ptr = (struct node*)malloc(sizeof(struct node));
   int count = 1;
   printf("ENTER ELEMENT FOR INSERTION AT INPUT POSITION : ");
   scanf("%d",&ptr -> data);
   while(count != position)
   {
       count++;
       temp = temp -> next;
   }
   temp -> prev -> next = ptr;
   ptr -> prev = temp -> prev;
   ptr -> next = temp;
   temp -> prev = ptr;

   return start;
}
int main()
{
    int n;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&n);
    struct node *head = create_LL(n);
    traverse(head);
    // head = insertion_at_beg(head);
    // traverse(head);
    // head = insertion_at_end(head);
    // traverse(head);
    

    // int pos;
    // printf("ENTER POSITION FOR INSERTION : ");
    // scanf("%d",&pos);
    // head = insertion_at_position(head,pos);
    // traverse(head);

}