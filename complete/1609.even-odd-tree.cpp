/*
 * @lc app=leetcode id=1609 lang=cpp
 *
 * [1609] Even Odd Tree
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
    int depth(struct TreeNode *root)
    {
        if (!root)
            return 0;
        return fmax(depth(root->left), depth(root->right)) + 1;
    }

    bool traverse(struct TreeNode *root, int layer, int *arr)
    {
        if (!root)
            return true;

        if (layer % 2)
        {
            if (root->val >= arr[layer] || root->val % 2 == 1)
                return false;
        }
        else
        {
            if (root->val <= arr[layer] || root->val % 2 == 0)
                return false;
        }
        arr[layer] = root->val;
        return traverse(root->left, layer + 1, arr) && traverse(root->right, layer + 1, arr);
    }
    bool isEvenOddTree(TreeNode *root)
    {
        int d = depth(root);
        int arr[d];
        for (int i = 0; i < d; i++)
        {
            if (i % 2)
                arr[i] = INT_MAX;
            else
                arr[i] = INT_MIN;
        }

        return traverse(root, 0, arr);
    }
};
// @lc code=end
