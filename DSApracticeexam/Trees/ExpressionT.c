#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char postfix[20];
struct node {
    char data;
    struct node *left, *right;
    struct node *next;
}*start = NULL;

struct node *stack[20]={NULL};

void push(struct node *newnode)
{
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        newnode->next=start;
        start=newnode;
    }
}
struct node *pop()
{
    struct node *temp;
    temp=start;
    start=start->next;
    return temp;
}
void inorder(struct node *start)
{
    if(start)
    {
        inorder(start -> left);
        printf("%c", start -> data);
        inorder(start -> right);
    }
}
void main()
{
    char postfix[50];
    struct node *temp,*y,*z;
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    int i=0;
    for(i=0;postfix[i]!='\0';i++)
    {
        char ch=postfix[i];
        if(isalnum(ch))
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=ch;
            temp->right=NULL;
            temp->left=NULL;
            temp->next=NULL;
            push(temp);
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=ch;
            y=pop();
            z=pop();
            temp->right=y;
            temp->left=z;
            push(temp);
    
        }
    }
    
inorder(start);
}