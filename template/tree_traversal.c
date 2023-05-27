// Tree Traversal (Preoreder/Inorder/Postorder)

#include <stdio.h>

typedef struct
{
    int val;
    struct NODE *left;
    struct NODE *right;
} NODE;

// Tree Traversal - Preoreder
void traversal_preorder(NODE *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%i\n", node->val);

    if (node->left != NULL)
    {
        traversal_preorder(node->left);
    }
    if (node->right != NULL)
    {
        traversal_preorder(node->right);
    }
}

// Tree Traversal - Inorder
void traversal_inorder(NODE *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traversal_inorder(node->left);
    }
    printf("%i\n", node->val);
    if (node->right != NULL)
    {
        traversal_inorder(node->right);
    }
}

// Tree Traversal - Postorder
void traversal_postorder(NODE *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traversal_postorder(node->left);
    }
    if (node->right != NULL)
    {
        traversal_postorder(node->right);
    }
    printf("%i\n", node->val);
}