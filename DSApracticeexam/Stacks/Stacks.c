#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

int stack[50];
int top=-1;

void push(int x)
{
    if(top==49)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack Underflow");
    }
    else
    {
        item=stack[top];
        top--;
        printf("Popped item: %d\n",item);
    }
}
void display()
{
    int i;
    printf("Stack : ");
    for(i=top;i>=0;i--)
    {
        printf("|%d|",stack[i]);
    }
    printf("\n");
}
void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    display();
}