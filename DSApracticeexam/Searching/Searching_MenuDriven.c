#include <stdlib.h>
#include <stdio.h>

int a[50];
int n;


void linearSearch(int num)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            printf("Num found at position %d\n",i+1);
            break;
        }
        else if(i==(n-1) && a[i]!=num)
        {
            printf("Num not found\n");
        }
    }
}

void binarySearch(int low,int high,int num)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        if(a[mid]==num)
        {
            printf("Num found at position %d\n",mid+1);
        }
        else if(a[mid]>num)
        {
            binarySearch(low,mid-1,num);
        }
        else if(a[mid]<num)
        {
            binarySearch(mid+1,high,num);
        }
        else
        {
            printf("Num not found\n");
        }
    }
    else
    {
        printf("Enter valid limits\n");
    }
}


int min(int a,int b)
{
    return (a<=b)?a:b;
}
int fibonacci(int a[],int x)
{
    int data;
    printf("Enter data to be searched:");
    scanf("%d",&data);
    int fib0=0;
    int fib1=1;
    int fib2=fib0+fib1;
    
    while(fib2<x)
    {
        fib0=fib1;
        fib1=fib2;
        fib2=fib0+fib1;
    }

    int offset=-1;
    while(fib2>1)
    {
        int i=min(offset+fib0,x-1);
        if(a[i]<data)
        {
            fib2=fib1;
            fib1=fib0;
            fib0=fib2-fib1;
            offset=i;
        }   
        else if(a[i]>data)
        {
            fib2=fib0;
            fib1=fib1-fib0;
            fib0=fib2-fib1;
        }
        else return i;
    }
    if(a[offset+1]==data)
    {
        return offset+1;
    }
    else
    {
    return -1;
    }
}


void main()
{
    int data,val;
    printf("Enter number of data items in the array: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        a[i]=data;
    }

    // LINEAR SEARCH
    printf("Enter data to search? : \n");
    scanf("%d",&val);
    linearSearch(val);

    // BINARY SEARCH
    printf("Data to search? : \n");
    scanf("%d",&val);
    binarySearch(0,n-1,val);


    // FIBO
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter sorted array\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter data:");
        scanf("%d",&a[i]);
    }
    int index=fibonacci(a,n);
    if(index==-1)
    {
        printf("Not found.\n");
    }
    else
    {
        printf("Data searched is found at %d position.",index+1);
    }


}