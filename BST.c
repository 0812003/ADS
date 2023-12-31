#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

};


struct node *new_node(struct node *root, int data)
{
   struct node *newnode ;
   newnode=malloc(sizeof(struct node));
   newnode->data=data;
   newnode->left=NULL;
   newnode->right=NULL;

   return newnode;
}

struct node *insert(struct node *root, int data)
{

    if(root==NULL)
    {
        return new_node(root,data);
    }
    else if(data <root->data)
    {
        root->left=insert(root->left, data);
    }
    else
    {
        root->right=insert(root->right, data);
    }

    return root;
}

struct node *findminimum(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
     findminimum(root->left);
    }

    return root;
}


struct node *delete(struct node *root, int data)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(data < root->data)
    {
        root->left=delete(root->left, data);
    }
    else if(data > root->data)
    {
        root->right=delete(root->right,data);
    }
    else
    {
       if(root->left==NULL && root->right==NULL)
       {
        free(root);
        return NULL;
       }
       else if(root->left==NULL || root->right==NULL)
       {
        struct node *temp;
        if(root->left==NULL)
        {
            temp=root->right;
        }
        else
        {
          temp=root->left;
        }

        free(root);
        return temp;
       }
       else{

        struct node *temp;
        temp=findminimum(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
       }
    }

    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root=NULL;

    root=new_node(root,20);
    root=insert(root,5);
    root=insert(root,1);
    root=insert(root,15);
    root=insert(root,9);
    root=insert(root,7);
    root=insert(root,12);
    root=insert(root,30);
    root=insert(root,25);
    root=insert(root,40);
    root=insert(root,45);
    root=insert(root,42);

    printf("\nWithout Deleting Elements: ");
    inorder(root);
    printf("\nAfter Deleting Elements 40: ");
    root=delete(root,40);
    inorder(root);
      printf("\nAfetr Deleting Elements 1: ");
      root=delete(root,1);
    inorder(root);
   
    return 0;

}
