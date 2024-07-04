/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void traverse(TreeNode *root, vector<int> &arr, vector<string> &ans)
    {
        if (!root)
            return;
        arr.push_back(root->val);
        if (root->left)
        {
            traverse(root->left, arr, ans);
            arr.pop_back();
        }
        if (root->right)
        {
            traverse(root->right, arr, ans);
            arr.pop_back();
        }
        if (!root->left && !root->right)
        {
            string s;
            for (int i = 0; i < arr.size() - 1; i++)
                s += to_string(arr[i]) + "->";
            s += to_string(arr[arr.size() - 1]);
            ans.push_back(s);
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> arr;
        vector<string> ans;
        traverse(root, arr, ans);
        return ans;
    }
};
// @lc code=end

// Note: backtracking + tree