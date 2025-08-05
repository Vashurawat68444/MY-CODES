/*
  <-----------------------THIS CODE DOES USE FOR SORTING IN CIRCULAR DOUBLY LINKED LIST----------------------->
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
   printf("\n");
}
struct node* merging(struct node *head1, struct node *head2)
{
  struct node *ptr1, *ptr2, *ptr3, *temp,*head;
  ptr3 = (struct node*)malloc(sizeof(struct node));
  temp = ptr3;
  ptr1 = head1;
  ptr2 = head2;
  // do
  // {
  //    if(ptr1->data < ptr2->data)
  //     {
  //       ptr3->next=ptr1;
  //       ptr1->prev=ptr3;
  //       ptr1=ptr1->next;
  //     }
  //     else
  //     {
  //       ptr3->next=ptr2;
  //       ptr2->prev=ptr3;
  //       ptr2=ptr2->next;
  //     }
  //     ptr3=ptr3->next;
  // } while (ptr1 != head1 && ptr2 != head2);
  if(ptr1==head1)
  {
    do
    {
      ptr3->next=ptr2;
      ptr2->prev=ptr3;
      ptr2=ptr2->next;
      ptr3=ptr3->next;
    } while (ptr2!=head2);
  }else{
    do
    {
      ptr3->next=ptr1;
      ptr1->prev=ptr3;
      ptr1=ptr1->next;
      ptr3=ptr3->next;
    } while (ptr1!=head1);
    
  }

  //  while(ptr1 -> next != head1 && ptr2 -> next != head2)
  //  {
  //     if(ptr1->data < ptr2->data)
  //     {
  //       ptr3->next=ptr1;
  //       ptr1->prev=ptr3;
  //       ptr1=ptr1->next;
  //     }
  //     else
  //     {
  //       ptr3->next=ptr2;
  //       ptr2->prev=ptr3;
  //       ptr2=ptr2->next;
  //     }
  //     ptr3=ptr3->next;
  //  }
  //  while(ptr1->next=head1)
  //  {
  //     ptr3->next=ptr1;
  //     ptr1->prev=ptr3;
  //     ptr1=ptr1->next;
  //     ptr3=ptr3->next;
  //  }
  //  while(ptr2->next=head2)
  //  {  
  //     ptr3->next=ptr2;
  //     ptr2->prev=ptr3;
  //     ptr2=ptr2->next;
  //     ptr3=ptr3->next;  
  //  }
  temp -> next -> prev = ptr3;
  ptr3 -> next = temp -> next;
  head = temp->next;
  return head;
}
int main()
{
    int n , m;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d %d",&n,&m);
    printf("ENTER ELEMENT FOR LINK LIST 1 ->\n");
    struct node *head1 = create_LL(n);
    traverse(head1);
    printf("ENTER ELEMENT FOR LINK LIST 2 ->\n");
    struct node *head2 = create_LL(m);
    traverse(head2);
    struct node *head = merging(head1,head2);
    printf("YOUR SORTED LIST IS :\n");
    traverse(head);
}