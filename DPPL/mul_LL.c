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
    if(n==0){
        printf("YOUR LINKED LIST WAS EMPTY!");
    }
    else{
    node* head = create_node();
    node* temp = head;
    node* newnode;
    for(int i=1; i<n; i++)
    {
        newnode = create_node();
        temp -> next = newnode;
        temp = temp -> next;
    }
    return head;
    }
}
void traverse(node *start)
{
    node* ptr = start;
    printf("ELEMENT OF SINGLE LINK LIST IS : ");
    while(ptr)
    {
        printf("%d\t",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}
struct node* reverse(struct node *start)
{
    struct node *current, *next, *prev = NULL;
    current = start;
    while(current)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
node* multiplication(node *head1,node *head2)
{
    head1 = reverse(head1);
    head2 = reverse(head2);
    traverse(head1);
    traverse(head2);
    node *temp1 = head2,*temp2 = head2;
    node *result_head = (node*)malloc(sizeof(node));
    // result_head->data = 0;
    result_head->next = NULL;
    node *temp = result_head;
    int i=0;
    while(temp2)
    {
        int carry = 0,mul = 0;
        temp1 = head1;
        while(temp1)
        {
            mul = (temp1->data)*(temp2->data);
            printf("%d*%d\n",temp2->data,temp1->data);
            if(temp2 == head2){mul += carry;}
            else{mul = mul + carry + temp->data;}
            carry = mul/10;
            temp->data = mul%10;
            if(temp->next){
                temp = temp->next;}
            else{
                temp->next = (node*)malloc(sizeof(node));
                temp = temp->next;
                temp->next = NULL;
            }
            if(temp1->next == NULL)
            {temp->data = carry;}
            temp1 = temp1->next;
        }
        temp = result_head;
        temp2 = temp2->next;
        i++;
        for(int k=0; k<i; k++)
        {
            temp = temp->next;
        }
    }
    result_head = reverse(result_head);
    return result_head;
}
int main()
{
    // int size1,size2;
    // printf("ENTER NUMBER OF NODES FOR : ");
    // scanf("%d",&size);
    int size1 = 3,size2 = 2;
    printf("ENTER DATA FOR LIST 1____\n");
    node* head1 = create_LL(size1);
    printf("ENTER DATA FOR LIST 2____\n");
    node* head2 = create_LL(size2);
    node *result = multiplication(head1,head2);
    traverse(result);
}