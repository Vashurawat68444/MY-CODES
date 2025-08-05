/*
  <---------DELETION BY RECURSIVE APPROACH------------>
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
    node* head = create_node();
    node* temp = head;
    node* newnode;
    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp -> next = newnode;
        temp = temp -> next;
    }
    temp -> next = head;
    return head;
}
void traverse(node *start)
{
    if(start == NULL)
    {
        printf("YOUR LIST WAS EMPTY ! \n");
    }
    else{
    node* ptr = start -> next;
    printf("CIRCULAR LINK LIST IS : ");
    printf("%d  ",start->data);
    while(ptr!= start)
    {
        printf("%d  ",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
    }
}
void deletion(node *x, node *y, node *start)
{
   if(x == start)
   {
      free(x);
      printf("YOUR LIST WAS DELTED ! \n");
      return;
   }else{
    y = x -> next;
    free(x);
    deletion(y,y,start);
   }
}
int main()
{
    int size;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&size);
    node* head = create_LL(size);
    traverse(head); //initial traversing 
    node *x,*y;
    x = head -> next;
    deletion(x, y, head);
    traverse(head); //final traversing for checking
}
