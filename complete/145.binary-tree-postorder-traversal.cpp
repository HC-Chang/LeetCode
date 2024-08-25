/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    void traverse(TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;
        if (root->left)
            traverse(root->left, arr);
        if (root->right)
            traverse(root->right, arr);
        arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> arr;
        traverse(root, arr);
        return arr;
    }
};
// @lc code=end
