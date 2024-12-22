/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
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
    int height(TreeNode *root, int h)
    {
        int l = 0;
        int r = 0;
        if (!root)
            return h;
        if (root->left)
            l = height(root->left, h + 1);
        if (root->right)
            r = height(root->right, h + 1);

        return max(h, max(l, r));
    }

    void traverse(TreeNode *root, int h, vector<vector<TreeNode *>> &arrs)
    {
        if (!root)
            return;

        arrs[h].push_back(root);
        if (root->left)
            traverse(root->left, h + 1, arrs);
        if (root->right)
            traverse(root->right, h + 1, arrs);
    }

    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return root;
        int h = height(root, 1);

        vector<vector<TreeNode *>> arrs(h);
        traverse(root, 0, arrs);
        int tmp;
        int n;
        for (int i = 1; i < h; i += 2)
        {
            n = arrs[i].size();
            for (int j = 0; j < n / 2; j++)
            {
                tmp = arrs[i][j]->val;
                arrs[i][j]->val = arrs[i][n - 1 - j]->val;
                arrs[i][n - 1 - j]->val = tmp;
            }
        }

        return root;
    }
};
// @lc code=end

// Note: tree + dfs