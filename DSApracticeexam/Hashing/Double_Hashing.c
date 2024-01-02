#include <stdio.h>

#define SIZE 10

int h[SIZE] = {0};

int double_h(int coeff_1, int coeff_2, int const_1, int const_2, int key, int i) 
{
    int function1_ans = (coeff_1 * key) + const_1;
    int fn1 = function1_ans % SIZE;
    int function2_ans = (coeff_2 * key) + const_2;
    int fn2 = function2_ans % SIZE;
    return ((fn1 + (fn2 * i)) % SIZE);
}

void double_insert(int key, int coeff_1, int const_1, int coeff_2, int const_2) 
{
    int i = 0, index = -1;
    for (i = 0; i < SIZE; i++) 
    {
        index = double_h(coeff_1, coeff_2, const_1, const_2, key, i);
        if (h[index] == 0) 
        {
            h[index] = key;
            printf("Value %d inserted at index %d\n", key, index);
            return;
        }
    }
    if (i == SIZE) 
    {
        printf("Hash is full, value could not be inserted\n");
    }
}

void double_search(int key, int coeff_1, int const_1, int coeff_2, int const_2) 
{
    int i = 0, index = -1;
    for (i = 0; i < SIZE; i++) 
    {
        index = double_h(coeff_1, coeff_2, const_1, const_2, key, i);
        if (h[index] == key) 
        {
            printf("Value %d found at index %d\n", key, index);
            return;
        }
    }
    if (i == SIZE) {
        printf("Value not found.\n");
    }
}

void display() {
    int i;
    printf("\nElements are \n");
    for (i = 0; i < SIZE; i++) {
        printf("\nIndex %d value = %d", i, h[i]);
    }
    printf("\n");
}

int main() {
    int key, coeff_1, const_1, coeff_2, const_2;

    while (1) {
        printf("\nMenu:\n1. Double Hash - Insert\n2. Double Hash - Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        switch (key) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &key);
                printf("Enter 1st coefficient: ");
                scanf("%d", &coeff_1);
                printf("Enter 1st constant: ");
                scanf("%d", &const_1);
                printf("Enter 2nd coefficient: ");
                scanf("%d", &coeff_2);
                printf("Enter 2nd constant: ");
                scanf("%d", &const_2);
                double_insert(key, coeff_1, const_1, coeff_2, const_2);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                printf("Enter 1st coefficient: ");
                scanf("%d", &coeff_1);
                printf("Enter 1st constant: ");
                scanf("%d", &const_1);
                printf("Enter 2nd coefficient: ");
                scanf("%d", &coeff_2);
                printf("Enter 2nd constant: ");
                scanf("%d", &const_2);
                double_search(key, coeff_1, const_1, coeff_2, const_2);
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
