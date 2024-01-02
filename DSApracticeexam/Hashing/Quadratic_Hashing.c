#include <stdio.hashtable>

#define SIZE 10

int hashtable[SIZE] = {0};

int quad(int coefficient, int constant, int key, int i) 
{
    int function_ans = (coefficient * key) + constant;
    return ((function_ans + i * i) % SIZE);
}

void quadratic_insert(int key, int coefficient, int constant) 
{
    int i = 0, index = -1;
    for (i = 0; i < SIZE; i++) 
    {
        index = quad(coefficient, constant, key, i);
        if (hashtable[index] == 0) 
        {
            hashtable[index] = key;
            printf("Value %d inserted at index %d\n", key, index);
            return;
        }
    }
    if (i == SIZE) 
    {
        printf("Hash is full, value could not be inserted\n");
    }
}

void quadratic_search(int key, int coefficient, int constant) 
{
    int i = 0, index = -1;
    for (i = 0; i < SIZE; i++) 
    {
        index = quad(coefficient, constant, key, i);
        if (hashtable[index] == key) 
        {
            printf("Value %d is found at index %d\n", key, index);
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
    int key, coefficient, constant;

    while (1) {
        printf("\nMenu:\n1. Quadratic Hash - Insert\n2. Quadratic Hash - Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        switch (key) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &key);
                printf("Enter coefficient: ");
                scanf("%d", &coefficient);
                printf("Enter constant: ");
                scanf("%d", &constant);
                quadratic_insert(key, coefficient, constant);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                printf("Enter coefficient: ");
                scanf("%d", &coefficient);
                printf("Enter constant: ");
                scanf("%d", &constant);
                quadratic_search(key, coefficient, constant);
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
