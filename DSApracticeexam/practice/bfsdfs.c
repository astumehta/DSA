#include <stdlib.h>
#include <stdio.h>

#define size 50

int top=-1;
int front=-1;
int rear=-1;
int stack[size];
int queue[size];
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

void enqueue(int val)
{
    queue[++rear]=val;
}

int dequeue()
{
    return queue[++front];
}

void push(int val)
{
    stack[++top]=val;
}
int pop()
{
    return stack[top--];
}
void bfs(int root,int n)
{
    enqueue(root);
    printf("%d",root);
    visited[root]=1;
    while(front<=rear)
    {
        int current=dequeue();
        visited[current]=1;
        for(int i=0;i<n;i++)
        {
            if(a[current][i] && !visited[i])
            {
                printf("%d",i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
    front=-1;
    rear=-1;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
}
void dfs(int root,int n)
{
    push(root);
    printf("%d",root);
    visited[root]=1;
    while(top!=-1)
    {
        int current=pop();
        visited[current]=1;
        for(int i=0;i<n;i++)
        {
            if(a[current][i] && !visited[i])
            {
                printf("%d",i);
                visited[i]=1;
                push(i);
            }
        }
    }
    top=-1;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
}
void main()
{
    int root;
    
    printf("\nEnter root vertex: ");
    scanf("%d",&root);
    printf("\n1.BFS\n");
    bfs(root,8);
    printf("\n2.DFS\n");
    dfs(root,8);

}