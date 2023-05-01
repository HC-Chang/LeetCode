/*
 * @lc app=leetcode id=700 lang=c
 *
 * [700] Search in a Binary Search Tree
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
struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    struct TreeNode *r;
    if (!root)
        return NULL;
    if (root->val == val)
        r = root;
    else if (root->val > val)
        r = searchBST(root->left, val);
    else if (root->val < val)
        r = searchBST(root->right, val);
    return r;
}
// @lc code=end
