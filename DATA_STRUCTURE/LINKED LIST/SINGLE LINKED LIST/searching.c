#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* create_node()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA IN NODE : ");
    scanf("%d",&ptr -> data);
    ptr -> next =NULL;
    return ptr;
}
struct node* create_LL(int n)
{
    struct node *temp, *newnode, *head;
    newnode = create_node();
    temp = newnode;
    head = newnode;
    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp -> next = newnode;
        temp = temp -> next;
    }
    return head;
}
int searching(struct node *start, int input)
{
    struct node *ptr = start;
    if(ptr==NULL)
    {
        printf("YOUR LINKED IS EMPTY !");
        exit(1);
    }
    int count=1;
    while(ptr)
    {
         if(ptr->data == input)
        {
            return count;
        }
        count++;
        ptr = ptr -> next;
       
    }
    if(ptr -> data != input)
    {
        return -1;
    }
}
int main()
{
    int n;
    printf("ENTER NUMBER OF NODES IN LINKED LIST : ");
    scanf("%d",&n);
    struct node *head = create_LL(n);
    int input;
    printf("ENTER THE ELEMENT FOR SEATCHING : ");
    scanf("%d",&input);
    int index_of_element = searching(head,input);
    printf("YOUR ELEMENT AT INDEX : %d",index_of_element);

}