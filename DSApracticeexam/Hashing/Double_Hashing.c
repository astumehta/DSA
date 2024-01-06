#include <stdio.h>
#include <conio.h>
#define SIZE 10

int h[SIZE] = {0};

void double_insert()
{
    int key,size2=8,data,index=0,i;
    printf("Enter data: ");
    scanf("%d", &data);
    key=(data%SIZE);
    for (i = 0; i < SIZE; i++)
    {
        index = (key+(i*(data%size2)))%SIZE;
        if (h[index] == 0)
        {
            h[index] = data;
            printf("Value %d inserted at index %d\n", data, index);
            return;
        }
    }
    if (i == SIZE)
    {
        printf("Hash is full, value could not be inserted\n");
    }
}

void double_search()
{
    int key,size2=8,data,index=0,i;
    printf("Enter data: ");
    scanf("%d", &data);
    key=(data%SIZE);
    for (i = 0; i < SIZE; i++)
    {
        index = (key+(i*(data%size2)))%SIZE;
        if (h[index] == data)
        {
            printf("Data Found");
            return;
        }
    }
    if (i == SIZE)
    {
        printf("Hash is full, value could not be inserted\n");
    }
}

void display()
{
    int i;
    printf("\nElements are \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("\nIndex %d value = %d", i, h[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nMenu:\n1. Double Hash - Insert\n2. Double Hash - Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            double_insert();
            break;
        case 2:

            double_search();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice, try again\n");
        }
    }
    return 0;
}