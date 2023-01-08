/*
 * @lc app=leetcode id=226 lang=c
 *
 * [226] Invert Binary Tree
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
struct TreeNode *invertTree(struct TreeNode *root)
{
    if (!root)
        return NULL;
    struct TreeNode *swap = root->left;
    root->left = root->right;
    root->right = swap;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    
    return root;
}
// @lc code=end
