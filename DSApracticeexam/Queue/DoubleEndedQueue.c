#include <stdio.h>
#define size 5

int queue[size];
int front = -1, rear = -1;

void enqueueUsingRear(int val) 
{
	if (front == (rear + 1) % size) 
    {
		printf("Queue full!");
	}
	else 
    {
		if (front == -1)
        {
			front++;
        }
		else
		{
		rear = (rear + 1) % size;
		queue[rear] = val;
		}
	}
}

void enqueueUsingFront(int val) 
{
	if (front == (rear + 1) % size) 
    {
		printf("Queue full!");
	}
	else 
    {
		if (front == -1) 
        {
			front++;
			rear++;
		}
		else
		{
            front = (front + size - 1) % size;
        }
		queue[front] = val;
	}
}

int dequeueUsingFront() 
{
	int x = -1;
	if (front == -1) 
    {
		printf("Queue empty!");
	}
	else 
    {
		x = queue[front];
		if (front == rear) 
        {
			front = -1;
			rear = -1;
		}
		else
		{	
            front = (front + 1) % size;
        }
	}
	return x;
}
int dequeueUsingRear() 
{
	int x = -1;
	if (rear == -1) 
    {
		printf("Queue empty!");
	}
	else 
    {
		x = queue[rear];
		if (front == rear) 
        {
			front = -1;
			rear = -1;
		}
		else
			rear = (rear + size - 1) % size;
	}
	return x;
}

void display() 
{
	int i = front;
	printf("\n");
	while (i != rear) 
    {
		printf("%d ", queue[i]);
		i = (i + 1) % size;
	}
	printf("%d\n", queue[rear]);
}

int main() {
    printf("Astu Mehta\n");
	int choice, inner_choice, val;
	do {
		printf("1. Input restricted\n2. Output restricted\n3. Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			do {
				printf("1. Enqueue\n2. Dequeue using front\n3. Dequeue using rear\n4. Display\n5. Exit\nEnter choice: ");
				scanf("%d", &inner_choice);
				switch (inner_choice) {
				case 1:
					printf("Enter value: ");
					scanf("%d", &val);
					enqueueUsingRear(val);
					break;
				case 2:
					printf("Dequeued %d\n", dequeueUsingFront());
					break;
				case 3:
					printf("Dequeued %d\n", dequeueUsingRear());
					break;
				case 4:
					display();
					break;
				case 5:
					break;
				default:
					printf("\nInvalid choice!");
					inner_choice = 5;
				}
			} 
            while (inner_choice != 5);
			break;
		case 2:
			do {
				printf("\n1. Enqueue using front\n2. Enqueue using rear\n3. Dequeue\n4. Display\n5. Exit\nEnter choice: ");
				scanf("%d", &inner_choice);
				switch (inner_choice) {
				case 1:
					printf("Enter value: ");
					scanf("%d", &val);
					enqueueUsingFront(val);
					break;
				case 2:
					printf("Enter value: ");
					scanf("%d", &val);
					enqueueUsingRear(val);
					break;
				case 3:
					printf("\nDequeued %d\n", dequeueUsingRear());
					break;
				case 4:
					display();
					break;
				case 5:
					break;
				default:
					printf("\nInvalid choice!");
					inner_choice = 5;
				}
			} 
            while (inner_choice != 5);
			break;
		case 3:
			break;
		default:
			printf("\nInvalid choice!");
			choice = 3;
		}
	} while (choice != 3);
	return 0;
}