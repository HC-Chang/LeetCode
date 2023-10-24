/*
 * @lc app=leetcode id=515 lang=c
 *
 * [515] Find Largest Value in Each Tree Row
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
int depth(struct TreeNode *root)
{
    if (!root)
        return 0;

    int l = depth(root->left);
    int r = depth(root->right);

    return fmax(l, r) + 1;
}
void find_max(struct TreeNode *root, int *arr, int index)
{
    if (!root)
        return;
    if (root->val > arr[index])
        arr[index] = root->val;
    find_max(root->left, arr, index + 1);
    find_max(root->right, arr, index + 1);
}
int *largestValues(struct TreeNode *root, int *returnSize)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = depth(root);
    int *arr = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        arr[i] = INT_MIN;
    find_max(root, arr, 0);
    return arr;
}
// @lc code=end

// Note: binary tree