/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    string tree2str(TreeNode *root)
    {
        if (!root)
            return "";
        string left = "";
        string right = "";

        if (root->left)
            left = tree2str(root->left);
        if (root->right)
            right = tree2str(root->right);

        string str = "";
        str += to_string(root->val);
        int l_len = left.size();
        int r_len = right.size();

        if (l_len || r_len)
            str += "(" + left + ")";
        if (r_len)
            str += "(" + right + ")";
        return str;
    }
};
// @lc code=end
