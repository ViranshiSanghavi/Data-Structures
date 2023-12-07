#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL; // Declare root globally

struct node* createNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

int main()
{
    int val;
    printf("Enter the data or enter -1 to exit: ");
    scanf("%d", &val);
    while (val != -1)
    {
        root = insert(root, val);
        printf("Enter the data or enter -1 to exit: ");
        scanf("%d", &val);
    }
    printf("Successfully created binary tree\n");

    

    return 0;
}

