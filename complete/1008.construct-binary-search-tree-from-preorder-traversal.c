/*
 * @lc app=leetcode id=1008 lang=c
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *insertNode(struct TreeNode *node, int val)
{
    struct TreeNode *insert = calloc(1, sizeof(struct TreeNode));
    insert->val = val;

    struct TreeNode *temp = node;

    int stop = 1;
    int lr = 0;
    while (stop)
    {
        if (val < temp->val)
        {
            if (temp->left == NULL)
            {
                lr = 0;
                stop = 0;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if (temp->right == NULL)
            {
                lr = 1;
                stop = 0;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    if (lr == 0)
    {
        temp->left = insert;
    }
    else
    {
        temp->right = insert;
    }

    return node;
}

struct TreeNode *bstFromPreorder(int *preorder, int preorderSize)
{
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
    root->val = preorder[0];

    for (int i = 1; i < preorderSize; i++)
    {
        root = insertNode(root, preorder[i]);
    }

    return root;
}
// @lc code=end
