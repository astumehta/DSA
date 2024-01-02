#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int top = -1;
char stack[50];

void push(char x) 
{
    if (top == 49) 
    {
        printf("Stack full");
    } 
    else 
    {
        top++;
        stack[top] = x;
    }
}

char pop() 
{
    if (top == -1) 
    {
        printf("Stack empty");
    } 
    else 
    {
        char item = stack[top];
        top--;
        return item;
    }
}

int pri(char symbol) 
{
    if (symbol == '^') 
    {
        return (6);
    } 
    else if (symbol == '*' || symbol == '/') 
    {
        return (3);
    } 
    else if (symbol == '+' || symbol == '-') 
    {
        return (1);
    }
    else 
    {
        return (0);
    }
}

int prs(char symbol) 
{
    if (symbol == '^') 
    {
        return (5);
    } 
    else if (symbol == '*' || symbol == '/') 
    {
        return (4);
    } 
    else if (symbol == '+' || symbol == '-') 
    {
        return (2);
    }
    else 
    {
        return (0);
    }
}

int main() {
    int i = 0, k = 0;
    char ch;
    char postfix[50] = {'\0'}, infix[50];

    printf("Enter infix expression: ");
    while ((ch = getchar()) != '\n') 
    {
        infix[i++] = ch;
    }
    
    infix[i] = '\0';

    i = 0;

    while ((ch = infix[i]) != '\0') {
        if (ch == '(') 
        {
            push(ch);
        } 
        else if (isalnum(ch)) 
        {
            postfix[k++] = ch;
        } 
        else if (ch == ')') 
        {
            while (stack[top] != '(') 
            {
                postfix[k++] = pop();
            }
            pop();
        } 
        else 
        {
            while (pri(ch) <= prs(stack[top]) && top >= 0) 
            {
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (top >= 0) 
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    
    for (i = 0; i < k; i++) {
        printf("%c", postfix[i]);
    }

    return 0;
}
