/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int depth(struct TreeNode *root, int cur_layer, int *layer, int *val)
    {
        if (!root)
            return 0;
        if (cur_layer > *layer)
        {
            *val = root->val;
            *layer = cur_layer;
        }

        return fmax(depth(root->left, cur_layer + 1, layer, val), depth(root->right, cur_layer + 1, layer, val)) + 1;
    }
    int findBottomLeftValue(TreeNode *root)
    {
        int layer = 0;
        int val = root->val;
        if (!root->left && !root->right)
            return val;
        depth(root, 0, &layer, &val);
        return val;
    }
};
// @lc code=end

// Note: queue / recursion