/*
     |------------------------THIS CODE IS USE FOR DELETION-------------------|
*/
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next,*prev;
};
struct node* create_node()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA FOR LINKED LIST : ");
    scanf("%d",&ptr -> data);
    ptr -> next = NULL;
    ptr -> prev = NULL;
    return ptr;
}
struct node* create_LL(int n)
{
    struct node *temp = create_node();
    struct node *head = temp;
    struct node *newnode;

    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp -> next = newnode;
        newnode -> prev = temp;
        temp = temp -> next;
    }
    return head;
}
void traverse(struct node *start)
{
    struct node *temp = start;
    if(temp == NULL)
    {
        printf("EMPTY LINKED LIST !");
        exit(1);
    }
    printf("YOUR LINKED LIST : ");
    while(temp)
    {
        printf("   %d   ",temp -> data);
        temp = temp -> next;
    }
    printf("\n\n");
}
struct node* deletion_at_begening(struct node *start)
{
    struct node *for_free = start;
    struct node *head = start -> next;
    head -> prev = NULL;
    free(for_free);
    return head;
}
struct node* deletion_at_end(struct node *start)
{
    struct node *temp = start;
    while(temp -> next -> next !=NULL)
    {
        temp = temp -> next;
    }
    struct node* for_free = temp -> next;
    temp -> next = NULL;
    free(for_free);
    return start;
}
struct node* deletion_at_pos(struct node* start, int position)
{
    struct node *temp = start;
    struct node *head = start;
    int count = 1;
    while(count != position)
    {
        temp = temp -> next;
        count++;
    }
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(temp);
    return start;

}
int main()
{
    int number_of_node;
    printf("ENTER THE NUMBER OF NODES : ");
    scanf("%d",&number_of_node);
    struct node *head = create_LL(number_of_node);
    traverse(head);
    // head = deletion_at_begening(head);
    // traverse(head);
    //  head = deletion_at_end(head);
    //  traverse(head);

    // int position;
    // printf("ENTER POSITION FOR DELETION : ");
    // scanf("%d",&position);
    // head = deletion_at_pos(head,position);
    // traverse(head);

}