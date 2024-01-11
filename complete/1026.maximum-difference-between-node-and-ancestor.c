/*
 * @lc app=leetcode id=1026 lang=c
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
int traverse(struct TreeNode *root, int min_val, int max_val)
{
    if (!root)
        return max_val - min_val;

    if (root->val < min_val)
        min_val = root->val;
    if (root->val > max_val)
        max_val = root->val;

    int l = traverse(root->left, min_val, max_val);
    int r = traverse(root->right, min_val, max_val);
    if (l > r)
        return l;
    return r;
}
int maxAncestorDiff(struct TreeNode *root)
{
    return traverse(root, root->val, root->val);
}
// @lc code=end

// Note: binary tree