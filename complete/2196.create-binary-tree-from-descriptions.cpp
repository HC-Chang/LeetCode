/*
 * @lc app=leetcode id=2196 lang=cpp
 *
 * [2196] Create Binary Tree From Descriptions
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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> hash;
        for (auto &d : descriptions)
        {
            if (hash.find(d[0]) == hash.end())
                hash[d[0]] = new TreeNode(d[0]);
            if (hash.find(d[1]) == hash.end())
                hash[d[1]] = new TreeNode(d[1]);
            if (d[2])
                hash[d[0]]->left = hash[d[1]];
            else
                hash[d[0]]->right = hash[d[1]];
        }

        for (auto &d : descriptions)
            hash.erase(d[1]);

        return hash.begin()->second;
    }
};
// @lc code=end

// Note: hash table + binary tree

// Official Solution