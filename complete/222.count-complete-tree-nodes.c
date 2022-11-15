/*
 * @lc app=leetcode id=222 lang=c
 *
 * [222] Count Complete Tree Nodes
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
void count(struct TreeNode *root, int *c)
{
    if (!root)
        return;
    ++*c;
    if (root->left)
        count(root->left, c);
    if (root->right)
        count(root->right, c);
}
int countNodes(struct TreeNode *root)
{
    int c = 0;
    count(root, &c);
    return c;
}
// @lc code=end
