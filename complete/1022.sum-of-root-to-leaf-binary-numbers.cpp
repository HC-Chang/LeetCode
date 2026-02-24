/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    void traverse(TreeNode *root, string s, int &sum)
    {
        if (!root)
            return;

        s += root->val + '0';
        traverse(root->left, s, sum);
        traverse(root->right, s, sum);
        if (!root->left && !root->right)
            sum += stoi(s, nullptr, 2);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        int sum = 0;
        traverse(root, "", sum);
        return sum;
    }
};
// @lc code=end

// Note: backtracking