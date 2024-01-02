#include <stdlib.h>
#include <stdio.h>

int a[100];
int n;

void bubbleSort()
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertionSort()
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j]=a[i];
            j--;
        }
        a[j+1]=temp;
    }
}

void selectionSort()
{
    int imin,i,j,temp;
    for(i=0;i<n;i++)
    {
        imin=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[imin])
            {
                imin=j;
            }
        }
        temp=a[imin];
        a[imin]=a[i];
        a[i]=temp;
    }
}

void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quick_Sort(int low,int high)
{
    if(low<high)
    {
        int loc=partition(low,high);
        quick_Sort(low,loc-1);
        quick_Sort(loc+1,high);
    }
}
int partition(int low,int high)
{
    int pivot=a[low];
    int start=low+1;
    int end=high;
    while(start<end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[low],&a[end]);
    return end;
}



// RADIXSORT
void radixSort(int a[], int n) {
    int range = 10;
    int output[n];
    int count[range];

    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) 
    {
        
        for (int i = 0; i < range; i++)
            count[i] = 0;

        
        for (int i = 0; i < n; i++)
        {
            count[(a[i] / exp) % range]++;
        }

        
        for (int i = 1; i < range; i++)
        {
            count[i] += count[i - 1];
        }

        
        for (int i = n - 1; i >= 0; i--) 
        {
            output[count[(a[i] / exp) % range] - 1] = a[i];
            count[(a[i] / exp) % range]--;
        }

        
        for (int i = 0; i < n; i++)
        {
            a[i] = output[i];
        }
    }
}


int main()
{
    int data, val;
    printf("Enter number of data items in the array: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        a[i] = data;
    }

    // BUBBLE SORT
    printf("\nBUBBLE SORT: ");
    bubbleSort();
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }

    // INSERTION SORT
    printf("\nINSERTION SORT: ");
    insertionSort();
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }

    // SELECTION SORT
    printf("\nSELECTION SORT: ");
    selectionSort();
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }

    // QUICK SORT
    printf("\nQUICK SORT: ");
    quick_Sort(0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }

    // MERGE SORT



    // RADIX SORT
    n = sizeof(a) / sizeof(a[0]);
    radixSort(a, n);
    printf("\nRadixSorted array: ");
    for (int i = 0; i < n; i++)
    {
        if(a[i]!=0)
        {
            printf("%d ", a[i]);
        }
    }
    return 0;
}
