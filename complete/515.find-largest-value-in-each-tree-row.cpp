/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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

        int l = depth(root->left);
        int r = depth(root->right);

        return max(l, r) + 1;
    }
    void find_max(struct TreeNode *root, vector<int> &arr, int index)
    {
        if (!root)
            return;
        if (arr[index] == INT_MIN || root->val > arr[index])
            arr[index] = root->val;
        find_max(root->left, arr, index + 1);
        find_max(root->right, arr, index + 1);
    }
    vector<int> largestValues(TreeNode *root)
    {
        if (!root)
            return vector<int>();
        vector<int> arr(depth(root), INT_MIN);
        find_max(root, arr, 0);
        return arr;
    }
};
// @lc code=end

// Note: binary tree