/*
 * @lc app=leetcode id=129 lang=c
 *
 * [129] Sum Root to Leaf Numbers
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
void sum_tree(int tmp, int *sum, struct TreeNode *root)
{
    if (!root)
        return;

    tmp = tmp * 10 + root->val;

    if (!root->left && !root->right)
    {
        *sum += tmp;
        return;
    }

    sum_tree(tmp, sum, root->left);
    sum_tree(tmp, sum, root->right);
}
int sumNumbers(struct TreeNode *root)
{
    int sum = 0;
    sum_tree(0, &sum, root);
    return sum;
}
// @lc code=end
