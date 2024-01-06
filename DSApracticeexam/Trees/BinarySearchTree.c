#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
}*root=NULL;



// CREATE
void create()
{
    struct node*temp,*parent;
    int data;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        if(root==NULL)
        {
            root=newnode;
        }
        else
        {
            temp=root;
            while (temp!=NULL)
            {
                parent=temp;
                if(temp->data>data)
                {
                    temp=temp->left;
                }
                else
                {
                    temp=temp->right;
                }
            }
                
                
            if(parent->data>data)
            {
                parent->left=newnode;
            }
            else
            {
                parent->right=newnode;
            }
        }
    }
}


// DELETE
void deleteNode()
{
    struct node *temp, *succ, *psucc, *parent;
    int data;
    printf("\nWhich node to delete: ");
    scanf("%d", &data);
    temp = root;
    parent = NULL;

    while (temp != NULL && temp->data != data)
    {
        parent = temp;
        if (temp->data > data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        printf("Node not found in the tree.\n");
    }
    else
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            if (parent == NULL)
            {
                free(root);
                root = NULL;
            }
            else if (parent->left == temp)
            {
                parent->left = NULL;
                free(temp);
            }
            else
            {
                parent->right = NULL;
                free(temp);
            }
        }
        else if (temp->right == NULL)
        {
            if (parent == NULL)
            {
                root = temp->left;
                free(temp);
            }
            else if (parent->left == temp)
            {
                parent->left = temp->left;
                free(temp);
            }
            else
            {
                parent->right = temp->left;
                free(temp);
            }
        }
        else if (temp->left == NULL)
        {
            if (parent == NULL)
            {
                root = temp->right;
                free(temp);
            }
            else if (parent->left == temp)
            {
                parent->left = temp->right;
                free(temp);
            }
            else
            {
                parent->right = temp->right;
                free(temp);
            }
        }
        else
        {
            succ = temp->left;
            psucc = temp;
            while (succ->right != NULL)
            {
                psucc = succ;
                succ = succ->right;
            }
            if (psucc == temp)
            {
                temp->data = succ->data;
                temp->left = succ->left;
                free(succ);
            }
            else
            {
                temp->data = succ->data;
                psucc->right = succ->left;
                free(succ);
            }
        }
    }
}



// INORDER
void inOrder(struct node *temp)
{
    if(temp!=NULL)
    {
        inOrder(temp->left);
        printf("|%d|",temp->data);
        inOrder(temp->right);
    }

}


// POSTORDER
void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("|%d|",temp->data);
    }
}


// PREORDER
void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("|%d|",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}



// TOTALNODES
int totalNodes(struct  node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        return totalNodes(temp->left)+totalNodes(temp->right)+1;
    }
}



// INTERNALNODES
int internalNodes(struct node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else if(temp->left==NULL || temp->right==NULL)
    {
        return 0;
    }
    else
    {
        return internalNodes(temp->left)+internalNodes(temp->right)+1;
    }
}


// EXTERNALNODES
int externalNodes(struct node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else if(temp->left==NULL || temp->right==NULL)
    {
        return 1;
    }
    else
    {
        return externalNodes(temp->left)+externalNodes(temp->right);
    }
}


// MIRRORIMAGE
void mirrorimage( struct node *temp)
{
    struct node *t1;
    if(temp!=NULL)
    {
        mirrorimage(temp->left);
        mirrorimage(temp->right);
        t1=temp->left;
        temp->left=temp->right;
        temp->right=t1;
    }
}


// MENU-DRIVEN
void main()
{
    create();
    printf("Inorder: ");
    inOrder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nPreorder: ");
    preorder(root);
    deleteNode();
    printf("Deleting..");
    inOrder(root);
    printf("\nTotal nodes are: %d",totalNodes(root));
    printf("\nInternal nodes are: %d",internalNodes(root));
    printf("\nExternal nodes are: %d",externalNodes(root));
    mirrorimage(root);
}



