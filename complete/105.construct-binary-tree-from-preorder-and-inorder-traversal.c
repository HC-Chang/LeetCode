/*
 * @lc app=leetcode id=105 lang=c
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int *preorder;
    int pre_index;
    int *inorder;
} TREE_CONSTRUCTOR;

struct TreeNode *make_tree(TREE_CONSTRUCTOR *t_c, int start, int end)
{
    if (start == end)
        return NULL;

    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = t_c->preorder[t_c->pre_index++];

    int i = start;
    while (i < end && t_c->inorder[i] != node->val)
        i++;

    node->left = make_tree(t_c, start, i);
    node->right = make_tree(t_c, i + 1, end);

    return node;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    TREE_CONSTRUCTOR t_c;

    t_c.preorder = preorder;
    t_c.pre_index = 0;
    t_c.inorder = inorder;

    return make_tree(&t_c, 0, inorderSize);
}

// @lc code=end
