/*
 * @lc app=leetcode id=145 lang=c
 *
 * [145] Binary Tree Postorder Traversal
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
void post_order(struct TreeNode *root, int *arr, int *returnSize)
{
    if (!root)
        return;
    if (root->left)
        post_order(root->left, arr, returnSize);
    if (root->right)
        post_order(root->right, arr, returnSize);
    arr[(*returnSize)++] = root->val;
}
int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *arr = malloc(100 * sizeof(int));
    *returnSize = 0;
    post_order(root, arr, returnSize);
    return arr;
}
// @lc code=end
