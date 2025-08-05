#include<stdio.h>
#include<stdlib.h>
#define size 5
int circular_queue[size];
int front = -1;
int rear = -1;
void enQUEUE(int input)
{
    if((front = -1) && (rear = -1))
    {
        front++;
        rear++;
        circular_queue[rear] = input;
    }
    else if((front == 0 && rear == size-1) || ((rear+1) % size == front))
    {
        printf("\n QUEUE IS FULL \n");
    }
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        circular_queue[rear]=input;
    }
    else{
        rear++;
        circular_queue[rear] = input;
    }
}
int deQUEUE()
{
    int dequeued_element;
    if(front = -1)
    {
        printf("\nQUEUE IS EMPTY\n");
    }
    else if(front == rear)
    {
        dequeued_element = circular_queue[front];
        front=-1;
        rear=-1;
    }
    else if(front = size-1)
    {
        dequeued_element = circular_queue[front];
        front = 0;
    }
    else
    {
        dequeued_element = circular_queue[front];
        front++;
    }
}
void display_queue()
{
    int i;
    if(front == -1)
    {
        printf("\nYOUR QUEUE WAS EMPTY\n");
    }
    else{
        printf("YOUR QUEUE IS : ");
        printf("\n Front -> %d ", front);
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % size) {
        printf("%d ", circular_queue[i]);
        }
        printf("%d ", circular_queue[i]);
        printf("\n Rear -> %d \n", rear);
    }
}
int main()
{
    enQUEUE(1);
    enQUEUE(2);
    display_queue();
}