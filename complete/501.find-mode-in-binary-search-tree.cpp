/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    void inorder_traverse(TreeNode *root, unordered_map<int, int> &hash, int &max_count)
    {
        if (!root)
            return;
        if (root->left)
            inorder_traverse(root->left, hash, max_count);
        max_count = max(max_count, ++hash[root->val]);
        if (root->right)
            inorder_traverse(root->right, hash, max_count);
    }

    vector<int> findMode(TreeNode *root)
    {
        vector<int> r;
        int max_count = 0;
        unordered_map<int, int> hash;
        inorder_traverse(root, hash, max_count);
        for (auto h : hash)
        {
            if (h.second == max_count)
                r.push_back(h.first);
        }
        return r;
    }
};
// @lc code=end

// Note: tree