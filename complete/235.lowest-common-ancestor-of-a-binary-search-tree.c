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
struct TreeNode *lca(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (!root)
        return NULL;

    if (root->val < p->val)
        return lca(root->right, p, q);
    else if (root->val > q->val)
        return lca(root->left, p, q);
    else
        return root;
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (q->val > p->val)
        return lca(root, p, q);
    else
        return lca(root, q, p);
}
// @lc code=end
// 假設 p值 < q值
// 則   lca 介於 p、q 之間
//      p < lca < q
// 找完左側後再找右側