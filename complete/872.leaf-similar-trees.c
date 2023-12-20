/*
 * @lc app=leetcode id=872 lang=c
 *
 * [872] Leaf-Similar Trees
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
void record_leaf(struct TreeNode *root, int *idx, int *arr)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        arr[(*idx)++] = root->val;
        return;
    }

    if (root->left)
        record_leaf(root->left, idx, arr);
    if (root->right)
        record_leaf(root->right, idx, arr);
}
bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    int arr1[200] = {0};
    int arr2[200] = {0};
    int idx_1 = 0;
    int idx_2 = 0;
    record_leaf(root1, &idx_1, arr1);
    record_leaf(root2, &idx_2, arr2);
    if (idx_1 != idx_2)
        return false;

    return !memcmp(arr1, arr2, sizeof(arr1));
}
// @lc code=end
