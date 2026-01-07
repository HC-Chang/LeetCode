/*
 * @lc app=leetcode id=1339 lang=c
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
long mod = 1e9 + 7;

long postorder(long *total, long *ans, struct TreeNode *root)
{
    if (!root)
        return 0;
    long sum = root->val + postorder(total, ans, root->left) + postorder(total, ans, root->right);
    if (*total)
        *ans = fmax(*ans, sum * (*total - sum));
    return sum;
}

int maxProduct(struct TreeNode *root)
{
    long total = 0;
    long ans = 0;
    total = postorder(&total, &ans, root);
    postorder(&total, &ans, root);
    return ans % mod;
}
// @lc code=end

// Note: binary tree