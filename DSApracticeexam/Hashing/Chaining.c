#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
}*HashTable[10];

int hash(int val)
{
    return val%10;
}

void insert(struct node *HashTable[], int val)
{
    int index = 0;
    index = hash(val);
    if (HashTable[index]==0)
    {
        HashTable[index] = (struct node *)malloc(sizeof(struct node));
        HashTable[index]->data = val;
        HashTable[index]->next = NULL;
    }
    else{
        struct node *trail,*temp,*newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;
        temp = HashTable[index];
        while (temp!=NULL&&temp->data<val)
        {
            trail = temp;
            temp = temp->next;
        }
        if (temp==NULL)
        {
            trail->next = newnode;
        }
        else{
            newnode->next = temp;
            trail->next = newnode;
        }        
    }
}
void display(struct node *HashTable[])
{
    struct node *temp;
    for (int i = 0; i < 10; i++)
    {
        temp = HashTable[i];
        printf("%d ",i);
        while (temp!= NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        HashTable[i] = 0;
    }
    insert(HashTable,12);
    insert(HashTable,14);
    insert (HashTable,16);
    insert(HashTable,32);
    insert(HashTable,22);
    display(HashTable);
    return 0;
}