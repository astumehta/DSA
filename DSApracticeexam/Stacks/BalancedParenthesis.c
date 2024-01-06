#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool areParenthesesBalanced(char expression[]) 
{
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; expression[i] != '\0'; i++) 
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            stack[++top] = expression[i];
        } 
        else if (expression[i] == ')' && top != -1 && stack[top] == '(') 
        {
            top--;
        } 
        else if (expression[i] == ']' && top != -1 && stack[top] == '[') 
        {
            top--;
        } 
        else if (expression[i] == '}' && top != -1 && stack[top] == '{') 
        {
            top--;
        } 
        else 
        {
            return false; 
        }
    }

    return top == -1; 
}

int main() 
{
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areParenthesesBalanced(expression)) 
    {
        printf("balanced\n");
    } 
    else 
    {
        printf("not balanced\n");
    }

    return 0;
}
