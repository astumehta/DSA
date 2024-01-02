#include <stdio.h>
#include <conio.h>

struct node
{
    int data;
    struct node *previous, *next;
} *root = NULL;

void create()
{
    struct node *newnode, *temp;
    int i, n, val;
    printf("enter no of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter num");
        scanf("%d", &val);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        if (root == NULL)
        {
            newnode->next = NULL;
            newnode->previous = NULL;
            root = newnode;
        }
        else
        {
            temp= root;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->previous = temp;
            newnode->next = NULL;
        }
    }
}

void insertbef()
{
    int n, val;
    struct node *newnode, *temp;
    printf("Enter the value before u wanna insert: ");
    scanf("%d", &n);
    printf("Enter the valueeeee: ");
    scanf("%d", &val);
    temp = root;
    while (temp->data != n)
    {
        temp = temp->next;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (temp->previous == NULL)
    {
        newnode->data = val;
        newnode->next = root;
        root->previous = newnode;
        newnode->previous = NULL;
        root = newnode;
    }
    else
    {
        newnode->data = val;
        newnode->next = temp;
        newnode->previous = temp->previous;
        temp->previous->next = newnode;
        temp->previous = newnode;
    }
}
void display()
{
    struct node *parent;
    parent = root;
    while (parent != NULL)
    {
        printf("%d ", parent->data);
        parent = parent->next;
    }
}

void insertaft()
{
    int n, val;
    struct node *newnode, *temp;
    printf("Enter the value after u wanna insert: ");
    scanf("%d", &n);
    printf("Enter the valueeeee: ");
    scanf("%d", &val);
    temp = root;
    while (temp->data != n)
    {
        temp = temp->next;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    if (temp->next == NULL)
    {
        newnode->next = NULL;
        newnode->previous = temp;
        temp->next = newnode;
    }
    else
    {
        newnode->next = temp->next;
        newnode->previous = temp;
        temp->next->previous = newnode;
        temp->next = newnode;
    }
}

void del()
{
    int n;
    struct node *newnode, *temp;
    printf("Enter the value u wanna delete: ");
    scanf("%d", &n);
    temp = root;
    while (temp->data != n)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        temp->previous->next = NULL;
        free(temp);
    }

    else if (temp->previous == NULL)
    {
        temp->next->previous = NULL;
        root = temp->next;
        free(temp);
    }

    else
    {
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        free(temp);
    }
}

void main()
{
    clrscr();
    create();
    display();
    insertbef();
    display();
    insertaft();
    display();
    del();
    display();
    getch();
}
