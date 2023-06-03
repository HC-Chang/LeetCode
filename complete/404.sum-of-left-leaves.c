/*
 * @lc app=leetcode id=404 lang=c
 *
 * [404] Sum of Left Leaves
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
void traverse(int *sum, struct TreeNode *last, struct TreeNode *root)
{
    if (!root)
        return;
    if ((last == NULL || last->left == root) && root->left == NULL && root->right == NULL)
        *sum += root->val;
    if (root->left)
        traverse(sum, root, root->left);
    if (root->right)
        traverse(sum, root, root->right);
}
int sumOfLeftLeaves(struct TreeNode *root)
{
    if(root->left == NULL && root->right == NULL)
        return 0;
    int sum = 0;
    struct TreeNode * last = NULL;
    traverse(&sum, last, root);
    return sum;
}
// @lc code=end
