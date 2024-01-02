#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int stack[50];
int top = 0;


void decimaltobinary(int decimal) 
{
    int remainder;
    while (decimal > 0) 
    {
        remainder = (decimal % 2);
        // USE PUSH FUNCTION INSTEAD OF THE LINE OF CODE BELOW
        stack[top++] = remainder;
        decimal = decimal / 2;
        decimaltobinary(decimal);
    }
}

int main() 
{
    decimaltobinary(20);
    for (int i = top - 1; i >= 0; i--) 
    {
        printf("%d", stack[i]);
    }
    return 0;
}
