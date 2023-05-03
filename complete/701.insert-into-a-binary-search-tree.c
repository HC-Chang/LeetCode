/*
 * @lc app=leetcode id=701 lang=c
 *
 * [701] Insert into a Binary Search Tree
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
struct TreeNode *insert_parent(struct TreeNode *root, int val)
{
    struct TreeNode *p;
    while (root)
    {
        p = root;
        if (root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return p;
}

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    struct TreeNode *insert_node = malloc(sizeof(struct TreeNode));
    insert_node->val = val;
    insert_node->left = NULL;
    insert_node->right = NULL;
    if (!root)
        return insert_node;
    struct TreeNode *p = insert_parent(root, val);
    if (p->val > val)
        p->left = insert_node;
    else
        p->right = insert_node;
    return root;
}
// @lc code=end
