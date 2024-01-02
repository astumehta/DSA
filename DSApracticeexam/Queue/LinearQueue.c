#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define size 5

int data;
int queue[size];
int front=-1;
int rear=-1;

void enqueue(int data)
{
    if(rear==(size-1))
    {
        printf("Queue full");
    }
    else if(rear==-1)
    {
        front++;
        rear++;
        queue[rear]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
}

void dequeue()
{
    int data;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty");
    }
    else if(front==rear)
    {
        data=queue[front];
        front=-1;
        rear=-1;
        printf("Dequeued: %d",data);
    }
    else
    {
        data=queue[front];
        front++;
        printf("Dequeued: %d\n",data);
    }

}


void display()
{
    if(rear==-1)
    {
        printf("Stack Empty");
    }
    else
    {
        printf("Queue: \n");
        for(int i=front;i<rear+1;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}


void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
}