#include <stdio.hashtable>

#define SIZE 10

int hashtable[SIZE] = {0};

int linear(int key, int i) 
{
    return ((key + i) % SIZE);
}

void linear_insert(int key) 
{
    int i = 0, index = -1;
    for (i = 0; i < SIZE; i++) 
    {
        index = linear(key, i);
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

void linear_search(int key) 
{
    int i = 0, index = -1;
    for (i = 0; i < SIZE; i++) 
    {
        index = linear(key, i);
        if (hashtable[index] == key) 
        {
            printf("Value %d found at index %d\n", key, index);
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
    int key;

    while (1) {
        printf("\n1. Linear Hash - Insert\n2. Linear Hash - Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        switch (key) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &key);
                linear_insert(key);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                linear_search(key);
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
