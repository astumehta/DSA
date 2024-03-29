#include<stdio.h>
// graph is of numbers ranging from 0 - 7

int top = -1;
int front = -1;
int  rear = -1; 
int queue[20]; 
int stack[20];
int visited[8];
int a[8][8] = 
{
        {0, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 0},
};




// BFS (Queue)
void enqueue(int val)
{
    queue[++rear] = val;      
}

int dequeue()
{
    return queue[++front];    
}

void bfs(int root, int n)
{
    int current;
    enqueue(root);
    printf("%d ", root);
    visited[root] = 1;
    while(front <= rear)
    {
        current = dequeue(); 
        visited[current] = 1; 
        for(int i = 0; i < n; i++)
        {
            if(a[current][i] && !visited[i])
            {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    front = -1;
    rear = -1;
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("\n");
}

// DFS (Stack)
void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

void dfs(int root, int n)
{
    int i;
    push(root);
    printf("%d ", root);
    visited[root] = 1;
    while(top != -1)
    {
        int current = pop();
        if(!visited[current])
        {
            printf("%d ", current);
        }
        visited[current] = 1;
        for(i = 0; i < n; i++)
        {
            if(a[current][i] && !visited[i])
            {
                push(i);
            }
        }
    }
}

int main() 
{
    int n = 8, i, s, ch, j;
    char c;
    
    printf("The Adjacency Matrix is: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) 
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    do {
        for (i = 1; i <= n; i++)
            visited[i] = 0;
        printf("\nMenu");
        printf("\n1. BFS");
        printf("\n2. DFS");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        printf("Enter the root vertex: ");
        scanf("%d", &s);
        switch (ch) 
        {
            case 1:
                bfs(s, n);
                break;
            case 2:
                dfs(s, n);
                break;
        }
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &c); // Added space before %c to consume newline
        } 
    while ((c == 'y') || (c == 'Y'));

    return 0;
}