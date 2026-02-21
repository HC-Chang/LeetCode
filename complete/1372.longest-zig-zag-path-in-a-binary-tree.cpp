/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    typedef enum
    {
        NONE = 0,
        LEFT,
        RIGHT
    } DIRECTION;

    int traverse(TreeNode *root, DIRECTION last_dir, int cnt, int max_cnt)
    {
        int l = 0;
        int r = 0;
        if (root->left)
        {
            if (last_dir == LEFT)
                l = max(l, traverse(root->left, LEFT, 1, max_cnt));
            else if (last_dir == RIGHT)
                l = max(l, traverse(root->left, LEFT, ++cnt, max_cnt));
            else
                l = max(l, traverse(root->left, LEFT, 1, max_cnt));
        }
        if (root->right)
        {
            if (last_dir == RIGHT)
                r = max(r, traverse(root->right, RIGHT, 1, max_cnt));
            else if (last_dir == LEFT)
                r = max(r, traverse(root->right, RIGHT, ++cnt, max_cnt));
            else
                r = max(r, traverse(root->right, RIGHT, 1, max_cnt));
        }

        if (max(cnt, max(l, r)) > max_cnt)
            max_cnt = max(cnt, max(l, r));
        return max_cnt;
    }

    int longestZigZag(TreeNode *root)
    {
        return traverse(root, NONE, 0, 0);
    }
};
// @lc code=end

// NOTE: DFS