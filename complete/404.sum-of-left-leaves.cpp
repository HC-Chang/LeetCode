/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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

class Solution {
public:
    void traverse(int* sum, TreeNode* last, TreeNode* root) {
        if (!root)
            return;
        if ( last->left == root && !root->left && !root->right)
            *sum += root->val;
        if (root->left)
            traverse(sum, root, root->left);
        if (root->right)
            traverse(sum, root, root->right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root->left && !root->right)
            return 0;
        int sum = 0;
        TreeNode* last = root;
        traverse(&sum, last, root);
        return sum;
    }
};

// @lc code=end

// Note: tree