#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;
struct node* create_node_with_value(int n)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}
 void push(int data)
{
    struct node *newnode = create_node_with_value(data);
    newnode->next = top;
    top = newnode;
    printf("%d pushed in stack \n",data);
}
void pop()
{
    
    
        int item = top->data;
        printf("%d is popped \n",item);
        struct node *for_free = top;
        top = top->next;
        free(for_free);
    
}
void display()
{
    struct node *temp = top;
    printf("ELEMENT IN STACK ARE :");
    while(temp)
    {
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    char c;
    int number;
    printf("<------------MENU------------->\n");
    printf("       ENTER A : PUSH \n");
    printf("       ENTER B : POP \n");
    printf("       ENTER C : EXIT \n");
    printf("---------------------------------\n");
     do
    {
        printf("     ENTER YOUR INPUT : ");
        scanf(" %c",&c);
        if(c=='A')
        {
           printf("    ENTER NUMBER FOR PUSH : ");
           scanf("%d",&number);
           push(number);
           display();
        }
        if(c == 'B')
        {
           pop();
        }
    }while(c != 'q');
    
}