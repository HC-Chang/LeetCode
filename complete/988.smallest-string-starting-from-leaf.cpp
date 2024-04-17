/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
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
    vector<string> arr;
    void traverse(string s, TreeNode *root)
    {
        s += root->val + 'a';

        if (!root->left && !root->right)
        {
            reverse(s.begin(), s.end());
            arr.push_back(s);
            return;
        }

        if (root->left)
            traverse(s, root->left);
        if (root->right)
            traverse(s, root->right);
    }

    string smallestFromLeaf(TreeNode *root)
    {
        traverse("", root);
        sort(arr.begin(), arr.end());
        return arr[0];
    }
};
// @lc code=end

// Note: DFS + binary tree