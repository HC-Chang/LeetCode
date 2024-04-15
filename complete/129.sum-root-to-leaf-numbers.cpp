/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    void traverse(int tmp, int *sum, TreeNode *root)
    {
        if (!root)
            return;

        tmp = tmp * 10 + root->val;
        if (!root->left && !root->right)
            *sum += tmp;
        else
        {
            if (root->left)
                traverse(tmp, sum, root->left);
            if (root->right)
                traverse(tmp, sum, root->right);
        }
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        int sum = 0;
        traverse(0, &sum, root);
        return sum;
    }
};
// @lc code=end

// Note: binary tree