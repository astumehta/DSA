#include <stdio.h>
#include <conio.h>
#define SIZE 5
int st[SIZE];
int top = -1;

void push(int val)
{
    top++;
    if (top != SIZE)
    {
        st[top] = val;
    }
    else
    {
        printf("Stack overflow");
    }
}

int pop()
{
    int val;
    if (top == -1)
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

void display()
{
    int i;
    for (i = top; i > 0; i--)
    {
        printf("%d", st[i]);
    }
}

void rev()
{
    int arr[5];
    int i, val;
    for (i = 0; i < 4; i++)
    {
        printf("Enter element  ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 4; i++)
    {
        push(arr[i]);
    }
    for (i = 0; i < 4; i++)
    {
        val = pop();
        arr[i] = val;
    }
    for (i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
}

void pal()
{
    int arr[5], pal[5];
    int i, val, flag = 0;
    for (i = 0; i < 4; i++)
    {
        printf("Enter element  ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 4; i++)
    {
        push(arr[i]);
    }
    for (i = 0; i < 4; i++)
    {
        val = pop();
        pal[i] = val;
    }
    for (i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    for (i = 0; i < 4; i++)
    {
        if (arr[i] == pal[i])
        {
            flag++;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag > 0)
    {
        printf("NOICE");
    }
    else
    {
        printf("NAHI HAI");
    }
}

void main()
{
    int n, val;
    clrscr();
    do
    {
        printf("\nEnter what you want to do: 1.Push\n 2.Pop\n 3.Display \n 4.Reverse\n 5.Palindrome check\n 6.Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element to be pushed: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            rev();
            break;

        case 5:
            pal();
            break;
        }

    } while (n != 6);
    getch();
}
