/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
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
    bool get_path(int val, string &path, TreeNode *root)
    {
        if (!root)
            return false;
        if (root->val == val)
            return true;
        if (get_path(val, path, root->left))
        {
            path.push_back('L');
            return true;
        }
        else if (get_path(val, path, root->right))
        {
            path.push_back('R');
            return true;
        }
        return false;
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string s_path;
        string d_path;
        get_path(startValue, s_path, root);
        get_path(destValue, d_path, root);

        while (!s_path.empty() && !d_path.empty() &&
               s_path.back() == d_path.back())
        {
            s_path.pop_back();
            d_path.pop_back();
        }
        reverse(begin(d_path), end(d_path));
        return string(s_path.size(), 'U') + d_path;
    }
};
// @lc code=end

// Note: DFS + binary tree