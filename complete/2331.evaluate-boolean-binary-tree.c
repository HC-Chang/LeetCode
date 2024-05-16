/*
 * @lc app=leetcode id=2331 lang=c
 *
 * [2331] Evaluate Boolean Binary Tree
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
bool evaluateTree(struct TreeNode *root)
{
    switch (root->val)
    {
    case 0:
        return false;
        break;
    case 1:
        return true;
        break;
    case 2:
        return evaluateTree(root->left) || evaluateTree(root->right);
        break;
    case 3:
        return evaluateTree(root->left) && evaluateTree(root->right);
        break;
    }

    return root->val;
}
// @lc code=end

// Note: DFS