/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    void record_leaf(struct TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            arr.push_back(root->val);
            return;
        }

        if (root->left)
            record_leaf(root->left, arr);
        if (root->right)
            record_leaf(root->right, arr);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr1;
        vector<int> arr2;
        record_leaf(root1, arr1);
        record_leaf(root2, arr2);
        if (arr1 == arr2)
            return true;
        return false;
    }
};
// @lc code=end
