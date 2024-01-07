#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*front = NULL,*rear = NULL;

void enqueue(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL) 
    {
        front = newNode;
        rear = newNode;
    } 
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() 
{
    if (front == NULL) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        struct Node* temp = front;
        printf("Dequeued: %d\n", temp->data);
        front = front->next;
        free(temp);
        if (front == NULL) 
        {
            rear = NULL;
        }
    }
}

void display() 
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        struct Node* temp = front;
        printf("Queue: \n");
        while (temp != NULL) 
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    return 0;
}
