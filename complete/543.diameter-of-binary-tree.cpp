/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int maxDepth(struct TreeNode *root, int *maxx)
    {
        if (!root)
            return 0;

        int l_depth = maxDepth(root->left, maxx);
        int r_depth = maxDepth(root->right, maxx);
        if (l_depth + r_depth > *maxx)
            *maxx = l_depth + r_depth;
        return max(l_depth, r_depth) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxx = 0;
        maxDepth(root, &maxx);

        return maxx;
    }
};
// @lc code=end
