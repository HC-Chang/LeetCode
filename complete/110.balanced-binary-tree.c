/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
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
int if_balance(struct TreeNode *root, bool *ret)
{
    if (!root || *ret == false)
        return 0;

    int l_height = if_balance(root->left, ret);
    if (*ret == false)
        return 0;

    int r_height = if_balance(root->right, ret);
    if (abs(l_height - r_height) > 1)
        *ret = false;

    return ((l_height > r_height ? l_height : r_height) + 1);
}

bool isBalanced(struct TreeNode *root)
{
    bool r = true;
    if_balance(root, &r);
    return r;
}
// @lc code=end
