/*
 * @lc app=leetcode id=199 lang=c
 *
 * [199] Binary Tree Right Side View
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void recursive(struct TreeNode *root, int *r, int *r_size, int new)
{
    if (root == NULL)
    {
        return;
    }
    r[new ++] = root->val;
    *r_size = new > *r_size ? new : *r_size;

    recursive(root->left, r, r_size, new);
    recursive(root->right, r, r_size, new);
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
    int buffer_size = 1000;
    int *r = calloc(buffer_size, sizeof(int));
    int r_size = 0;
    recursive(root, r, &r_size, 0);

    *returnSize = r_size;

    return r;
}
// @lc code=end
