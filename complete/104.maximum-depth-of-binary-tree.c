/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
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

// 遞迴
// 樹的高度 = max(左子樹,右子樹) + 1
int maxDepth(struct TreeNode *root)
{
    // 邊界
    if (root == NULL)
    {
        return 0;
    }

    int l_depth = maxDepth(root->left);
    int r_depth = maxDepth(root->right);

    return ((l_depth > r_depth) ? l_depth : r_depth) + 1;
}
// @lc code=end
