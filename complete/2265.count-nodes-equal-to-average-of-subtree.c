/*
 * @lc app=leetcode id=2265 lang=c
 *
 * [2265] Count Nodes Equal to Average of Subtree
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
typedef struct
{
    int sum;
    int count;
} DATA;

DATA post_treverse(struct TreeNode *root, int *ans)
{
    DATA rr;
    rr.sum = 0;
    rr.count = 0;
    if (!root)
        return rr;

    DATA l = post_treverse(root->left, ans);
    DATA r = post_treverse(root->right, ans);

    rr.sum = l.sum + root->val + r.sum;
    rr.count = l.count + 1 + r.count;

    if (rr.sum / rr.count == root->val)
        ++*ans;

    return rr;
}
int averageOfSubtree(struct TreeNode *root)
{
    int ans = 0;
    post_treverse(root, &ans);
    return ans;
}
// @lc code=end
