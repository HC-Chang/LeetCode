/*
 * @lc app=leetcode id=623 lang=c
 *
 * [623] Add One Row to Tree
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
struct TreeNode *init_node(int val, struct TreeNode *left, struct TreeNode *right)
{
    struct TreeNode *obj = malloc(sizeof(struct TreeNode));
    obj->val = val;
    obj->left = left;
    obj->right = right;
    return obj;
}

struct TreeNode *addOneRow(struct TreeNode *root, int val, int depth)
{
    if (!root)
        return NULL;
    if (depth == 1)
        return init_node(val, root, NULL);
    else if (depth == 2)
    {
        root->left = init_node(val, root->left, NULL);
        root->right = init_node(val, NULL, root->right);
    }
    else
    {
        addOneRow(root->left, val, depth - 1);
        addOneRow(root->right, val, depth - 1);
    }
    return root;
}
// @lc code=end

// Note: binary tree