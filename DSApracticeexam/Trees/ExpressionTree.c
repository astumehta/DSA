#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

struct node{
    char ch;
    struct node *left, *right;
} *root;

char postfix[100];
struct node *stack1[10];
int top1 = -1;

void push1(struct node *newnode)
{
    if(root==NULL)
    root = newnode;
    top1++;
    stack1[top1] = newnode; 
}

struct node *pop1()
{
    struct node *temp;
    if(top1 == -1){
        root = NULL;
        temp = NULL;
    }
    else {
        temp = stack1[top1];
        top1--;
    }
        return temp;
}


void create(char x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> ch = x;
    newnode -> left = newnode -> right = NULL;
    push1(newnode);
    root = newnode;
}

void createNode(char x){

    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> ch = x;
    temp = pop1();
    newnode -> right = temp;
    temp = pop1();
    newnode -> left = temp;
    push1(newnode);
    root = newnode;

}

void expression_tree() {
    int i = 0;
    char x;

    while(postfix[i] != '\0'){
        x = postfix[i];
        if(isalnum(x))
            create(x);
        
        else if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
            createNode(x);

        else {
            printf("Expression incorrect");
            break;
        }
        i++;
    }    
}

void inorder(struct node *temp){
    if (temp!=NULL) {
        inorder(temp -> left);
        printf("%c ", temp -> ch);
        inorder(temp -> right);
    }
}


int main(){
    printf("Enter the Postfix expression:\n");
    scanf("%s", postfix);
    expression_tree();
    inorder(root);
    return 0;
}