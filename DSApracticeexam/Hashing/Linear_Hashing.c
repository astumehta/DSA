#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define size 10

int hashtable[size]={0};

void insert()
{
    int data;
    int i;
    printf("Enter data to insert: ");
    scanf("%d",&data);
    int hkey=data%size;
    for(i=0;i<size;i++)
    {
        int index=(hkey+i)%size;
        if(hashtable[index]==0)
        {
            hashtable[index]=data;
            printf("Value %d inserted at index %d",data,index);
            break;
        }
    }
    if(i==size)
    {
        printf("Hash Full");
    }
}
void search()
{
    int data;
    int i;
    printf("Enter data to search: ");
    scanf("%d",&data);
    int hkey=data%size;
    for(i=0;i<size;i++)
    {
        int index=(hkey+i)%size;
        if(hashtable[index]==data)
        {
            printf("Value found at index %d",index);
            return;
        }
    }
    if(i==size)
    {
        printf("Value not found");
    }
}
void display()
{
    for(int i=0;i<size;i++)
    {
        printf("\nValue %d at index %d\n",hashtable[i],i);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}