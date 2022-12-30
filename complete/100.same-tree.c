/*
 * @lc app=leetcode id=100 lang=c
 *
 * [100] Same Tree
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
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (!p && q)
        return false;
    if (p && !q)
        return false;
    if (!p && !q)
        return true;
    if (p->val == q->val)
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    else
        return false;
}
// @lc code=end
