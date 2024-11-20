/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);

        TreeNode *a;
        TreeNode *b;

        while (!q.empty())
        {
            a = q.front();
            q.pop();
            b = q.front();
            q.pop();
            if (!a && !b)
                continue;
            if (!a || !b || a->val != b->val)
                return false;
            q.push(a->left);
            q.push(b->right);
            q.push(a->right);
            q.push(b->left);
        }
        return true;
    }
};
// @lc code=end
