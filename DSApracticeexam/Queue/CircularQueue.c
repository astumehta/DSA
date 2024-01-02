#include <stdio.h>

#include <stdlib.h>
#define size 5
int front = -1;
int rear = -1;
int queue[size];


void enqueue(int x)
{
    if((rear+1)%size==front)
    {
        printf("Stack Full");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Stack empty");
    }
    else if(front==rear)
    {
        printf("Element Dequeued");
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
}

void display()
{
    int i=front;
    while(i!=rear)
    {
        printf("%d,",queue[i]);
        i=(i+1)%size;
    }
    printf("%d",queue[rear]);
}


void main()
{
    int choice,data;
    while(1)
    {
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
        printf("Enter data: ");
        scanf("%d",&data);
        enqueue(data);
        break;

        case 2:
        dequeue();
        break;

        case 3:
        display();
        break;

        case 4:
        exit(0);
       
    }
    }
}