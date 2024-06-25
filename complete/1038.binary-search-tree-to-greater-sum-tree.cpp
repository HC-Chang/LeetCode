/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
    void traverse(int *sum, TreeNode *root)
    {
        if (!root)
            return;
        if (root->right)
            traverse(sum, root->right);
        root->val += *sum;
        *sum = root->val;
        if (root->left)
            traverse(sum, root->left);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        traverse(&sum, root);
        return root;
    }
};
// @lc code=end

// Note: DFS
