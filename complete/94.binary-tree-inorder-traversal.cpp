/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    void inorder(struct TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left, arr);
        arr.push_back(root->val);
        if (root->right)
            inorder(root->right, arr);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
// @lc code=end
