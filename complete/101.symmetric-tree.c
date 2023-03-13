/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool is_symmetric(struct TreeNode *r1, struct TreeNode *r2)
{
    return (!r1 && !r2) || (r1 && r2 && r1->val == r2->val && is_symmetric(r1->left, r2->right) && is_symmetric(r1->right, r2->left));
}

bool isSymmetric(struct TreeNode *root)
{
    return is_symmetric(root, root);
}
// @lc code=end
