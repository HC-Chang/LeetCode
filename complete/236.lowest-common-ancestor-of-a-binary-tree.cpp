/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void traverse(TreeNode *root, TreeNode *target, vector<TreeNode *> &v, int &stopped)
    {
        if (!root || stopped)
            return;

        v.push_back(root);

        if (root->val == target->val)
            stopped = 1;

        if (root->left)
            traverse(root->left, target, v, stopped);

        if (root->right)
            traverse(root->right, target, v, stopped);
        if (!stopped)
            v.pop_back();
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> v1, v2;
        int stop1 = 0, stop2 = 0;
        traverse(root, p, v1, stop1);
        traverse(root, q, v2, stop2);

        int i = 0;
        int n = min(v1.size(), v2.size());
        while (i + 1 < n && v1[i + 1]->val == v2[i + 1]->val)
            i++;

        return v1[i];
    }
};
// @lc code=end
