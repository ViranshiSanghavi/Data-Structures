#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;
struct node* create(struct node*);
void display(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void inorder(struct node*);
int main()
{
 int choice, val;
 do
  {
    printf("\nMain Menu\n");
    printf("1. Create a binary search tree\n");
    printf("2. Display the tree\n");
     printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
        {
        case 1:
            root = create(root);
            break;
        case 2:
            display(root);
            break;
        case 3:
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
struct node* create(struct node* root)
{
    struct node* newnode = NULL, * temp = NULL, * parent = NULL;
    int val;
    printf("Enter the data or enter -1 to exit: ");
    scanf("%d", &val);
    while (val != -1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;

        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            temp = root;
            while (temp != NULL)
            {
                parent = temp;
                if (val < temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            if (val < parent->data)
            {
                parent->left = newnode;
            }
            else
            {
                parent->right = newnode;
            }
        }
        printf("Enter the data or enter -1 to exit: ");
        scanf("%d", &val);
    }
    printf("Successfully created\n");
    return root;
}

void display(struct node* root)
{
    int choice1;
    printf("\nDisplay Menu\n");
    printf("1. Preorder\n");
    printf("2. Inorder\n");
    printf("3. Postorder\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch (choice1)
    {
    case 1:
        printf("The preorder traversal is: ");
        preorder(root);
        break;
    case 2:
        printf("The inorder traversal is: ");
        inorder(root);
        break;
    case 3:
        printf("The postorder traversal is: ");
        postorder(root);
        break;
    case 4:
        break;
    default:
        printf("Invalid choice!\n");
    }
}
void preorder(struct node* temp)
{
    if (temp != NULL)
    {
     printf("%d ", temp->data);
     preorder(temp->left);
     preorder(temp->right);
    }
}
void postorder(struct node* temp)
{
    if (temp != NULL)
    {
     postorder(temp->left);
     postorder(temp->right);
     printf("%d ", temp->data);
    }
}
void inorder(struct node* temp)
{
  if (temp != NULL)
    {
     inorder(temp->left);
     printf("%d ", temp->data);
     inorder(temp->right);
    }
}


/*
Main Menu
1. Create a binary search tree
2. Display the tree
3. Exit
Enter your choice: 1

Enter the data or enter -1 to exit: 50
Enter the data or enter -1 to exit: 30
Enter the data or enter -1 to exit: 70
Enter the data or enter -1 to exit: 20
Enter the data or enter -1 to exit: 40
Enter the data or enter -1 to exit: 60
Enter the data or enter -1 to exit: 80
Enter the data or enter -1 to exit: -1
Successfully created

Main Menu
1. Create a binary search tree
2. Display the tree
3. Exit
Enter your choice: 2

Display Menu
1. Preorder
2. Inorder
3. Postorder
4. Exit
Enter your choice: 1
The preorder traversal is: 50 30 20 40 70 60 80

Display Menu
1. Preorder
2. Inorder
3. Postorder
4. Exit
Enter your choice: 2
The inorder traversal is: 20 30 40 50 60 70 80

Display Menu
1. Preorder
2. Inorder
3. Postorder
4. Exit
Enter your choice: 3
The postorder traversal is: 20 40 30 60 80 70 50

Display Menu
1. Preorder
2. Inorder
3. Postorder
4. Exit
Enter your choice: 4

Main Menu
1. Create a binary search tree
2. Display the tree
3. Exit
Enter your choice: 3
*/
