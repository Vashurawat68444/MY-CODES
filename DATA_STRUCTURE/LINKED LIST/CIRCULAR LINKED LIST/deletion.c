/*
   <-----------------------------------DELETION--------------------------------------->
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
struct node* deletion_from_front(struct node *tell)
{
    struct node *for_free = tell->next;
    tell->next = tell->next->next;
    free(for_free);
    return tell;
}
struct node* deletion_from_end(struct node *tell)
{
    struct node *temp = tell;
    while(temp->next != tell)
    {
        temp = temp -> next;
    }
    temp->next = tell->next;
    free(tell);
    return temp;
}
struct node* deletion_from_position(struct node *tell , int position)
{
    int count = 0;
    struct node *temp=tell;
    while(count != position-1)
    {
        count++;
        temp = temp->next;
    }
    struct node *for_free = temp->next;
    temp ->next = temp->next->next;
    
    free(for_free);
    return tell;
    
}
int main()
{
    int size,position;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&size);
    node* tell = create_LL(size);
    printf("ENTER POSITION FOR DELETION : ");
    scanf("%d",&position);
    traverse(tell);
    printf("\n");
    // tell = deletion_from_front(tell);
    // traverse(tell);
    // tell = deletion_from_end(tell);
    // traverse(tell);
    // tell = deletion_from_position(tell,position);
    // traverse(tell);

    printf("\nDELETED SUCSESFULLY !");
}
