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
struct node* del_occurence(struct node *tell, int number)
{
    struct node *temp = tell;
    struct node *for_free;
    if(temp->data == number)
    {
        for_free = temp;
        while(temp->next != tell)
        {
            temp = temp->next;
        }
        temp->next = tell->next;
        tell = temp;
        free(for_free);
        tell = del_occurence(temp,number);
    }
    if(temp->next->data == number)
    {
        for_free = temp->next;
        temp->next = for_free->next;
        free(for_free);
        tell = del_occurence(temp,number);
    }
    while(temp->next != tell)
    {
        if(temp->next->data == number)
        {
            for_free = temp->next;
            temp->next = temp->next->next;
            free(for_free);
            tell = del_occurence(tell,number);
        }
        temp = temp->next;
    }
    return tell;
}
int main()
{
    int size,number;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d",&size);
    printf("ENTER NUMBER FOR DELETION : ");
    scanf("%d",&number);
    node* tell = create_LL(size);
    traverse(tell);
    printf("\n");
    tell = del_occurence(tell,number);
    traverse(tell);
}
