/*
 * @lc app=leetcode id=1325 lang=c
 *
 * [1325] Delete Leaves With a Given Value
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
void traverse(struct TreeNode *last, struct TreeNode *root, int target)
{
    if (root->left)
        traverse(root, root->left, target);
    if (root->right)
        traverse(root, root->right, target);
    if (!root->left && !root->right && root->val == target && last)
    {
        if (last->left == root)
            last->left = NULL;
        else
            last->right = NULL;
    }
}

struct TreeNode *removeLeafNodes(struct TreeNode *root, int target)
{
    traverse(NULL, root, target);
    if (root->val == target && !root->left && !root->right)
        return NULL;
    return root;
}
// @lc code=end

// Note: DFS