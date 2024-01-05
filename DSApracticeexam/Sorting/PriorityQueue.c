#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    int priority;
    struct node *next;
} *start = NULL;

struct node *insert(struct node *start)
{
    int val, pri;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the value and its priority : ");
    scanf("%d %d", &val, &pri);
    newnode->data = val;
    newnode->priority = pri;
    if (start == NULL || pri < start->priority)
    {
        newnode->next = start;
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL && temp->next->priority <= pri)
        {
            temp = temp->next;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    return start;
}
struct node *delete(struct node *start)
{
    struct node *temp;
    if (start == NULL)
    {
        printf("\n UNDERFLOW");
        return;
    }
    else
    {
        temp = start;
        printf("\n Deleted item is: %d", temp->data);
        start = start->next;
        free(temp);
    }
    return start;
}
void display(struct node *start)
{
    struct node *temp;
    temp = start;
    if (start == NULL)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\n PRIORITY QUEUE IS : ");
        while (temp != NULL)
        {
            printf("\t%d[priority=%d]", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}
void main()
{
    int option;
    while (1)
    {
        printf("\n MENU");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = insert(start);
            break;
        case 2:
            start = delete (start);
            break;
        case 3:
            display(start);
            break;
        }
    }
}