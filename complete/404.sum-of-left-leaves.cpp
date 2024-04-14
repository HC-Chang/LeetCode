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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
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
    void traverse(int *sum, TreeNode *last, TreeNode *root)
    {
        if (!root)
            return;
        if ((last == NULL || last->left == root) && root->left == NULL &&
            root->right == NULL)
            *sum += root->val;
        if (root->left)
            traverse(sum, root, root->left);
        if (root->right)
            traverse(sum, root, root->right);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
            return 0;
        int sum = 0;
        TreeNode *last = NULL;
        traverse(&sum, last, root);
        return sum;
    }
};
// @lc code=end

// Note: tree