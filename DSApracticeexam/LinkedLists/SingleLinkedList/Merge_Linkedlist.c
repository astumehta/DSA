#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *next;
    int data;
} *start1 = NULL, *start2 = NULL;

void createnode1();
void createnode2();
void merge();
void display();

int main()
{
    createnode1();
    createnode2();
    merge();
    display();  // Display the merged list
    return 0;
}

void createnode1()
{
    int n1, data;
    struct node *newnode, *temp;
    printf("\nEnter Number of nodes for the first list: ");
    scanf("%d", &n1);
    printf("First list: ");
    for (int i = 0; i < n1; i++)
    {
        printf("\nEnter data %d : ", i + 1);
        scanf("%d", &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if (start1 == NULL)
        {
            start1 = newnode;
            temp = start1;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }
}

void createnode2()
{
    int n2, data;
    struct node *newnode, *temp;
    printf("\nEnter Number of nodes for the second list: ");
    scanf("%d", &n2);
    printf("Second list: ");
    for (int i = 0; i < n2; i++)
    {
        printf("\nEnter data %d : ", i + 1);
        scanf("%d", &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if (start2 == NULL)
        {
            start2 = newnode;
            temp = start2;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }
}

void merge()
{
    struct node *temp = start1;

    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        temp->next = start2;
    }
}

void display()
{
    printf("\nMerged list: ");
    struct node *temp = start1;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}
