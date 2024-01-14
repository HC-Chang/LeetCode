/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int traverse(TreeNode *root, int *res)
    {
        if (!root)
            return 0;
        int l = traverse(root->left, res);
        int r = traverse(root->right, res);
        *res += abs(l) + abs(r);
        return root->val + l + r - 1;
    }

    int distributeCoins(TreeNode *root)
    {
        int res = 0;
        traverse(root, &res);
        return res;
    }
};
// @lc code=end

// Note: binary tree