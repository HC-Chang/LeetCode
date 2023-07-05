/*
 * @lc app=leetcode id=235 lang=c
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}
// @lc code=end
// 假設 p值 < q值
// 則   lca 介於 p、q 之間
//      p < lca < q
// 找完左側後再找右側