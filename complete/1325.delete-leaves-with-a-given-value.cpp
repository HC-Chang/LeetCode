/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
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
    void traverse(TreeNode *last, TreeNode *root, int target)
    {
        if (root->left)
            traverse(root, root->left, target);
        if (root->right)
            traverse(root, root->right, target);
        if (!root->left && !root->right && root->val == target && last)
        {
            if (last->left == root)
                last->left = NULL;
            else
                last->right = NULL;
        }
    }
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        traverse(NULL, root, target);
        if (root->val == target && !root->left && !root->right)
            return NULL;
        return root;
    }
};
// @lc code=end

// Note: DFS