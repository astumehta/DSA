#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    int priority;
    struct Node * next;
}*start=NULL;

struct Node *insert(struct Node * start){
    struct Node *ptr,*p;
    int val,pri;
    ptr=(struct Node *)malloc(sizeof(struct Node)); 
    printf("enter the value to be inserted and its priority");
    scanf("%d %d",&val,&pri);
    ptr->data=val;
    ptr->priority=pri;
    if(start==NULL || pri<start->priority){
        ptr->next=start;
        start=ptr;
    }
    else{
        p=start;
        while(p->next!=NULL && p->next->priority<=pri){
            p=p->next;
        }
        ptr->next=p->next;
        p->next=ptr;
    }
    return start;
}

struct Node *delete(struct Node *start){
    struct Node *ptr;
    if(start==NULL){
        printf("empty");
    }
    else{
        ptr=start;
        printf("deleted element: %d",ptr->data);
        start=start->next;
        free(ptr);
    }
    return start;
}

void display(struct Node *start){
    struct Node *ptr;
    if(start==NULL){
        printf("empty");
    }
    else{
        ptr=start;
        while(ptr!=NULL){
            printf("%d\t[priority=%d]",ptr->data, ptr->priority);
            ptr=ptr->next;
        }
    }
}

void main(){
    int ch;
    do{
    printf("MENU");
    printf("1.Insert");
    printf("2.Delete");
    printf("3>display");
    printf("4.Exit");
    printf("choice:");
    scanf("%d",&ch);

    switch(ch){
        case 1:
        start=insert(start);
        break;
        case 2:
        start=delete(start);
        break;
        case 3:
        display(start);
        break;
    }
    }while(ch!=4);
}