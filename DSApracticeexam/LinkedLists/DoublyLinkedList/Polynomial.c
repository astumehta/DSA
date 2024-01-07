#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
    int coeff,pow;
    struct node *next;
}*start1=NULL,*start2=NULL,*start3=NULL;


struct node *create(struct node *start)
{
    struct node *newnode,*temp;
    int n,coeff,pow;
    printf("Enter number of terms:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter coefficient and power:");
        scanf("%d %d",&coeff,&pow);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coeff=coeff;
        newnode->pow=pow;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return start;
}
void link(int c,int p)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=c;
    newnode->pow=p;
    newnode->next=NULL;
    if(start3==NULL)
    {
        start3=newnode;
        temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}
void add()
{
    struct node *temp1,*temp2;
    int c,p;
    temp1=start1;
    temp2=start2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->pow>temp2->pow)
        {
            c=temp1->coeff;
            p=temp1->pow;
            temp1=temp1->next;
            link(c,p);
        }
        else if(temp2->pow>temp1->pow)
        {
            c=temp2->coeff;
            p=temp2->pow;
            temp2=temp2->next;
            link(c,p);
        }
        else
        {
            c=temp1->coeff+temp2->coeff;
            p=temp1->pow;
            temp1=temp1->next;
            temp2=temp2->next;
            link(c,p);
        }
        if(temp1==NULL)
        {
            while(temp2!=NULL)
            {
                c=temp2->coeff;
                p=temp2->pow;
                temp2=temp2->next;
                link(c,p);
            }
        }
        if(temp2==NULL)
        {
            while(temp1!=NULL)
            {
                c=temp1->coeff;
                p=temp1->pow;
                temp1=temp1->next;
                link(c,p);
            }
        }
}
}
void display(struct node *start)
{
    struct node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        printf("%dx^%d+",temp->coeff,temp->pow);
        temp=temp->next;
    }
    printf("%dx^%d",temp->coeff,temp->pow);
}
void main()
{
    start1=create(start1);
    printf("Polynomial 1 is:\n");
    display(start1);    
    printf("\n");
    start2=create(start2);
    printf("Polynomial 2 is:\n");
    display(start2);
    printf("\n");
    add();
    printf("Addititon is:");
    display(start3);
}