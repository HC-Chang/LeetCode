/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void traverse(int *cnt, int max_val, TreeNode *root)
    {
        if (!root)
            return;

        if (root->val >= max_val)
        {
            max_val = root->val;
            ++*cnt;
        }
        if (root->left)
            traverse(cnt, max_val, root->left);
        if (root->right)
            traverse(cnt, max_val, root->right);
    }
    int goodNodes(TreeNode *root)
    {
        int cnt = 0;
        int max_val = INT_MIN;

        traverse(&cnt, max_val, root);

        return cnt;
    }
};
// @lc code=end
