#include<stdio.h>
#include<stdlib.h>
#define size_of_queue 5
int queue[size_of_queue];
int front = -1, rear = -1;
void enqueue(int data)
{
    if(rear==size_of_queue)
    {
        printf("\nQUEUE IS FULL!\n");
    }else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = data;
        printf("\n  FIRST ELEMENT IS ADDED IN QUEUE ^\n");
    }
    else{
        rear++;
        queue[rear] = data;
    }
}
int dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\n  THE QUEUE IS EMPTY!\n");
    }else if(front == rear)
    {
        int returning_element = queue[front];
        front = -1;
        rear = -1;
        return returning_element;
    }else{
        int returning_element = queue[front];
        front++;
        return returning_element;
    }
}
void display()
{
    if(front == -1 && rear == -1)
    {
        printf("\n  QUEUE IS EMPTY!\n");
    }else
    {
        printf("\n  YOUR QUEUE IS : ");
        for(int i = front; i<=rear; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("  \n  YOUR QUEUE IS SUCCESFULLY PRINTED !\n");
    }
}
int main()
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



