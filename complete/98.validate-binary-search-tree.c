/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
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
// left side
bool large(struct TreeNode *root, struct TreeNode *node)
{
    if (!node)
        return true;
    if (root->val <= node->val)
        return false;
    return large(root, node->left) && large(root, node->right);
}

// right side
bool small(struct TreeNode *root, struct TreeNode *node)
{
    if (!node)
        return true;
    if (root->val >= node->val)
        return false;
    return small(root, node->left) && small(root, node->right);
}

bool isValidBST(struct TreeNode *root)
{
    if (!root)
    {
        return true;
    }

    if ((large(root, root->left) && small(root, root->right)) == false)
        return false;
    return isValidBST(root->right) && isValidBST(root->left);
}
// @lc code=end
// Tree Inorder Traversal
// Check Sorted Array