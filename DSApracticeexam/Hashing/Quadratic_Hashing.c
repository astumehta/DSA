#include<stdio.h>
#include<conio.h>
#define SIZE 10

int hashtable[SIZE] = {0};

void quadratic_insert() 
{
    int data,constant1,constant2,hkey;
    int i = 0, index = 0;
    printf("Enter value: ");
    scanf("%d", &data);
    printf("Enter constant 1: ");
    scanf("%d", &constant1);
    printf("Enter constant 2: ");
    scanf("%d", &constant2);
    hkey=data%SIZE;
    for (i = 0; i < SIZE; i++) 
    {
        index = ((hkey+(constant1*i)+(constant2*i*i))%SIZE);
        if (hashtable[index] == 0) 
        {
            hashtable[index] = data;
            printf("Value %d inserted at index %d\n", data, index);
            break;
        }
    }
    if (i == SIZE) 
    {
        printf("Hash is full, value could not be inserted\n");
    }
}

void quadratic_search() 
{
    int data,constant1,constant2,hkey;
    int i = 0, index = 0;
    printf("Enter value to search: ");
    scanf("%d", &data);
    printf("Enter constant 1: ");
    scanf("%d", &constant1);
    printf("Enter constant 2: ");
    scanf("%d", &constant2);
    hkey=data%SIZE;
    for (i = 0; i < SIZE; i++) 
    {
        index = ((hkey+(constant1*i)+(constant2*i*i))%SIZE);
        if (hashtable[index] == data) 
        {
            printf("Value %d is found at index %d\n", data, index);
            return;
        }
    }
    if (i == SIZE) 
    {
        printf("Value not found.\n");
    }
}

void display() {
    int i;
    printf("\nElements are \n");
    for (i = 0; i < SIZE; i++) {
        printf("\nIndex %d value = %d", i, hashtable[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Quadratic Hash - Insert\n2. Quadratic Hash - Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                quadratic_insert();
                break;
            case 2:    
                quadratic_search();
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