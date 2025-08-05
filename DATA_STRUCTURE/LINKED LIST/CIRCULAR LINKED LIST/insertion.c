/*
   <------------------------------------------INSERTION------------------------------------------------>
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
node* create_LL(int n)   //its return tell pointer means address of last node!
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
    return temp;
}
void traverse(node *tell)
{
    node* ptr = tell->next;
    printf("ELEMENT OF LINK LIST IS : ");
    while(ptr!=tell)
    {
        printf("%d  ",ptr -> data);
        ptr = ptr -> next;
    }
   printf("%d  ",tell->data);
}
struct node* insertion_at_beg(struct node *tell)
{
    struct node *newnode = create_node();
    newnode -> next = tell -> next;
    tell -> next = newnode;
    return tell;
}
struct node* insertion_at_end(struct node *tell)
{
    struct node *newnode = create_node();
    newnode -> next = tell ->next;
    tell->next = newnode;
    tell = newnode;
    return tell;
}
struct node* insertion_at_pos(struct node *tell, int position)
{
    int count = 0;
    struct node *temp = tell;
    while(count != position - 1)
    {
        temp = temp->next ; 
        count++;
    }
    struct node *newnode = create_node();
    newnode->next = temp->next;
    temp->next = newnode;
    if(temp == tell)
    {
        return newnode;
    }else{
    return tell;
    }
}
int main()
{
    int size,position;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&size);
    // printf("ENTER POSITION FOR INSERTION : ");
    // scanf("%d",&position);                         |THIS CODE USED ONLY WHEN YOU WANT TO INSERT ELEMENT AT POSITION |
    node* tell = create_LL(size);
    traverse(tell);
    printf("\n");
    // tell = insertion_at_beg(tell);
    // traverse(tell);
    // tell = insertion_at_end(tell);
    // traverse(tell);
    // tell = insertion_at_pos(tell,position);
    // traverse(tell);
}
