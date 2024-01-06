 #include <stdio.h>
 #include <ctype.h>
 #include <stdlib.h>

 struct node{
    int coeff;
    int pow;
    struct node *next;
 }*start1=NULL,*start2=NULL,*start3=NULL;

 struct node *create(struct node *start)
 {
    int n;
    int coeff,power;
    struct node *temp,*newnode;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter coeff: ");
        scanf("%d",&coeff);
        printf("Enter power: ");
        scanf("&d",&power);
        newnode->coeff=coeff;
        newnode->pow=power;
        if(start==NULL)
        {
            start=newnode;
            temp=start;
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
    struct node *temp1;
    struct node *temp2;
    temp1=start1;
    temp2=start2;
    while(temp1!=NULL && temp2!=NULL)
    {
        
    }
 }