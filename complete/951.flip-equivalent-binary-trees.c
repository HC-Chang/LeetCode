/*
 * @lc app=leetcode id=951 lang=c
 *
 * [951] Flip Equivalent Binary Trees
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
void findCanonicalForm(struct TreeNode *root)
{
    if (!root)
        return;

    findCanonicalForm(root->left);
    findCanonicalForm(root->right);

    if (!root->right)
        return;
    if (!root->left)
    {
        root->left = root->right;
        root->right = NULL;
        return;
    }

    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;
    if (left->val > right->val)
    {
        root->left = right;
        root->right = left;
    }
}

bool areEquivalent(struct TreeNode *root1, struct TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->val != root2->val)
        return false;

    return areEquivalent(root1->left, root2->left) &&
           areEquivalent(root1->right, root2->right);
}

bool flipEquiv(struct TreeNode *root1, struct TreeNode *root2)
{
    findCanonicalForm(root1);
    findCanonicalForm(root2);
    return areEquivalent(root1, root2);
}
// @lc code=end

// Note: DFS + b-tree

// Official Solution