#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* createnode()
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("ENTER ELEMENT FOR NODE : ");
    scanf("%d",&ptr -> data);
    ptr -> next = NULL;
    return ptr;
}
struct node* create_LL(int n)
{
   struct node *head, *newnode, *temp;
   newnode = createnode();
   head = newnode;
   temp = newnode;
//    if(temp == NULL)
//    {
//     printf("LIST IS EMPTY !");
//     exit(1);
//    }
   for(int i=1; i<n; i++)
   {
     temp -> next = createnode();
     temp = temp -> next;
   }
   return head;

}
struct node* del_at_beg(struct node *start)
{
    struct node *temp = start;
    start = start-> next;
    free(temp);
    return start;
}
struct node* del_at_end(struct node *start)
{
  struct node *temp = start;
  while(temp -> next -> next != NULL)
  {
    temp = temp -> next;
  }
  temp -> next = NULL;
  return start;
}
struct node* del_at_position(struct node *start,int position) 
{
  struct node *temp = start;
  int count = 1;
  while(count != position - 1)
  {
     temp = temp -> next;
     count++;
  }
  struct node *for_free = temp -> next;
  temp -> next = temp -> next -> next;
  free(for_free);
  return start;
}
void traverse(struct node *start) //for traverse and print original and updated linked list
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
int main()
{
    int n;
    printf("ENTER THE NUMBER OF NODES : ");
    scanf("%d",&n);  
    struct node *head = create_LL(n);  // for create link list
    traverse(head); // for printing orignal linked list


    // head = del_at_beg(head);
    // traverse(head); // traverse for printing linked list after deletion at begining
    // head = del_at_end(head);
    // traverse(head);  // traverse after deletion at end and print these value by this function.

    //below this use the code when you have to delete at an position


    // int pos;
    // printf("ENTER POSITION FOR DELETION : ");
    // scanf("%d",&pos);
    // head = del_at_position(head,pos);
    // traverse(head);
}