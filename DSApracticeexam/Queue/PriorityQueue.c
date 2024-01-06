#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    int priority;
    struct Node * next;
}*start=NULL;

struct Node *insert(struct Node * start)
{
    struct Node *newnode,*temp;
    int val,pri;
    newnode=(struct Node *)malloc(sizeof(struct Node)); 
    printf("enter the value to be inserted and its priority");
    scanf("%d %d",&val,&pri);
    newnode->data=val;
    newnode->priority=pri;
    if(start==NULL || pri<start->priority)
    {
        newnode->next=start;
        start=newnode;
    }
    else
    
    {
        temp=start;
        while(temp->next!=NULL && temp->next->priority<=pri)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return start;
}

struct Node *delete(struct Node *start)
{
    struct Node *newnode;
    if(start==NULL)
    {
        printf("empty");
    }
    else
    {
        newnode=start;
        printf("deleted element: %d",newnode->data);
        start=start->next;
        free(newnode);
    }
    return start;
}

void display(struct Node *start)
{
    struct Node *newnode;
    if(start==NULL)
    {
        printf("empty");
    }
    else
    {
        newnode=start;
        while(newnode!=NULL)
        {
            printf("%d\t[priority=%d]",newnode->data, newnode->priority);
            newnode=newnode->next;
        }
    }
}

void main(){
    int ch;
    do{
    printf("MENU");
    printf("1.Insert");
    printf("2.Delete");
    printf("3>display");
    printf("4.Exit");
    printf("choice:");
    scanf("%d",&ch);

    switch(ch){
        case 1:
        start=insert(start);
        break;
        case 2:
        start=delete(start);
        break;
        case 3:
        display(start);
        break;
    }
    }while(ch!=4);
}