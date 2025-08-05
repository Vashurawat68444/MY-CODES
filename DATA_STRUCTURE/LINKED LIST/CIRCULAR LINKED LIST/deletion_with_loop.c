/*
  <----------------DELETIONOF OCCURENCE OF INPUT NUMBER------------------>
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
void deletion(struct node *start)
{
    node *x,*y;
    x = start -> next;
    while(x != start)
    {
        y = x -> next;
        free(x);
        x = y;
    }
    if(x == start){
        printf("YOUR LIST WAS SUCCESFULLY DELETED !\n");
        free(x); //FINALLY START NODE ALSO DELETED
    }
}
int main()
{
    int size;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&size);
    node* head = create_LL(size);
    traverse(head);
    deletion(head);
    traverse(head);
}
