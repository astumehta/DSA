#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
}*start;

void create()
{
    int i,n,data;
    struct node *newnode,*temp;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        if(start==NULL)
        {
            start=newnode;
            temp=start;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
    }
}

void insertbefore()
{
    int before,data;
    struct node *newnode,*temp,*pre;
    printf("\nData to be entered before which data item? :");
    scanf("%d",&before);
    printf("Enter data to insert :");
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    temp=start;
    while(temp->data!=before)
    {
        pre=temp;
        temp=temp->next;
    }
    if(temp==start)
    {
        newnode->next=start;
        start=newnode;
    }
    else
    {
        pre->next=newnode;
        newnode->next=temp;
    }
}
void insertafter()
{
    int after,data;
    struct node *newnode,*temp,*post;
    printf("\nData to be entered after which data item? :");
    scanf("%d",&after);
    printf("Enter data to insert :");
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    temp = start;
    while (temp->data != after)
    {
        post = temp;
        temp = temp->next;
    }
    post = temp->next;
    temp->next = newnode;
    newnode->next = post;
}

void deletenode()
{
    int data;
    struct node *newnode,*temp,*pre,*post;
    printf("Enter which data item to delete: ");
    scanf("%d",&data);
    
}

void display()
{
    struct node *temp;
    temp=start;
    printf("Linked list: ");
    while(temp->next!=NULL)
    {
        printf("%d,",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    
}
void main()
{
    create();
    display();
    insertbefore();
    display();
}