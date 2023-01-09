/*
 * @lc app=leetcode id=144 lang=c
 *
 * [144] Binary Tree Preorder Traversal
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
void pre_order(struct TreeNode *root, int *arr, int *returnSize)
{
    if (!root)
        return;
    arr[(*returnSize)++] = root->val;
    if (root->left)
        pre_order(root->left, arr, returnSize);
    if (root->right)
        pre_order(root->right, arr, returnSize);
}
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *arr = malloc(100 * sizeof(int));
    *returnSize = 0;
    pre_order(root, arr, returnSize);
    return arr;
}
// @lc code=end
