/*
   WHY IN THIS CODE DEQUEUE FUNCTION IS NOT RUNNING PROPERLY CLEAR IN LAB !
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *temp;
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int n)
{
    if(front == NULL)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        front = temp;
        rear =  temp;
    }
    else{
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp->next->data = n;
        temp = temp->next;
        temp->next = NULL;
        rear = temp;
    }
}
int dequeue()
{
    struct node *for_free;
    int element_returned;
    if(front == NULL && rear == NULL)
    {
        printf("\nQUEUE UNDERFLOW\n");
    }
    else if(front == rear)
    {
        for_free = front;
        element_returned = for_free->data;
        front = NULL; rear = NULL;
        free(for_free);
        return element_returned;
    }
    else{
        element_returned = front->data;
        for_free = front ;
        front = front->next;
        return element_returned; 
    }

}
void display()
{
    if(front == NULL)
    {
        printf("\n EMPTY QUEUE !");
    }
    else{
        printf("\n THE ELEMENT IN QUEUE IS : ");
        while(front)
        {
            printf("%d  ",front->data);
            front = front->next;
        }
        printf("\n");
    }
}
void main()
{
    char option = 'L';
   int input, dequeue_element;
   printf("|---------MENU---------|");
   printf("\n  ENTER A : FOR ENQUEUE\n");
   printf("\n  ENTER B : FOR DEQUEUE\n");
   printf("\n  ENTER C : FOR DISPALY\n");
   printf("\n  ENTER D : FOR EXIT\n");
   printf("-------------------------\n");
   while(option != 'D')
   {
      printf("\n  ENTER YOUR OPTION : ");
      scanf(" %c",&option);
      switch (option)
      {
        case 'A':
          printf("\n  ENTER YOUR INPUT FOR ENQUEUE : ");
          scanf("%d",&input);
          enqueue(input);
          break;
        case 'B':
          dequeue_element = dequeue();
          printf("\n  YOUR DEQUEUE ELEMENT IS : %d\n",dequeue_element);
          break;
        case 'C':
          printf("\n  DISPLAY IS CALL\n");
          display();
          break;
      }
   }
}