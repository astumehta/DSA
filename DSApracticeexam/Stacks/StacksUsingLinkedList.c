#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*start = NULL;

void push(int data) 
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) 
    {
        exit(1);
    }
    newnode->data = data;
    newnode->next = start;
    start = newnode;
}

void pop() 
{
    if (start == NULL) 
    {
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = start;
    start = start->next;
    printf("Popped item: %d\n", temp->data);
    free(temp);
}

void display() 
{
    struct Node *temp = start;
    printf("Stack: ");
    while (temp != NULL) {
        printf("|%d|", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    display();
    return 0;
}
