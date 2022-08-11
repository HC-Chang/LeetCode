/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode *root, int *returnSize, int *r)
{
    if (root != NULL)
    {
        inorder(root->left, returnSize, r);
        r[(*returnSize)++] = root->val;
        inorder(root->right, returnSize, r);
    }
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *r = calloc(100, sizeof(int));
    *returnSize = 0;

    inorder(root, returnSize, r);
    return r;
}
// @lc code=end
