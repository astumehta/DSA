#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define size 50

int top = -1;
int stack[size];
char postfix[size];

void push(int ch) 
{
    if (top == size - 1) 
    {
        printf("Stack full");
    } 
    else 
    {
        top++;
        stack[top] = ch;
    }
}

int pop() {
    if (top == -1) {
        printf("Underflow");
    } 
    else 
    {
        int item = stack[top];
        top--;
        return item;
    }
}

int main() {
    printf("Enter postfix expression: ");
    scanf(" %[^\n]", postfix);

    for (int i = 0; postfix[i] != '\0'; i++)
     {
        
        int x = postfix[i];
        if (isdigit(x)) 
        {
            push(x - '0');
        } 
        else 
        {
            int op2 = pop();
            int op1 = pop();
            switch (x) {
                case '+':
                    push(op1 + op2);
                    break;

                case '-':
                    push(op1 - op2);
                    break;

                case '*':
                    push(op1 * op2);
                    break;

                case '/':
                    if (op2 == 0) 
                    {
                        printf("Division by zero");
                        exit(1);
                    } 
                    else 
                    {
                        push(op1 / op2);
                    }
                    break;
            }
        }
    }

    
    int ans = stack[top];
    printf("%d", ans);
    

    return 0;
}
