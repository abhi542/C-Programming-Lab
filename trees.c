#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *left, *right;
} Node;

Node *createNode(int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->num = num;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert(Node *root, int num)
{
    if (root == NULL)
    {
        return createNode(num);
    }

    if (num < root->num)
    {
        root->left = insert(root->left, num);
    }
    else if (num > root->num)
    {
        root->right = insert(root->right, num);
    }

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->num);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->num);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->num);
        preorder(root->left);
        preorder(root->right);
    }
}

Node *search(Node *root, int num)
{
    if (root == NULL || root->num == num)
    {
        return root;
    }

    if (num < root->num)
    {
        return search(root->left, num);
    }

    return search(root->right, num);
}

int main()
{
    int n, num, choice;
    Node *root = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        root = insert(root, num);
    }

    do
    {
        printf("\n1. Inorder traversal\n2. Postorder traversal\n3. Preorder traversal\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inorder(root);
            break;

        case 2:
            postorder(root);
            break;

        case 3:
            preorder(root);
            break;

        case 4:
            printf("Enter the number to search: ");
            scanf("%d", &num);
            if (search(root, num) != NULL)
            {
                printf("Search is successful\n");
            }
            else
            {
                printf("Search is unsuccessful\n");
            }
            break;

        case 5:
            printf("Exiting...");
            break;

        default:
            printf("Invalid choice");
        }

    } while (choice != 5);

    return 0;
}
