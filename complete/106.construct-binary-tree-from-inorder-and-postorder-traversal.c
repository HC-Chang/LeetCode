/*
 * @lc app=leetcode id=106 lang=c
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    int *postorder;
    int post_index;
    int *inorder;
} TREE_CONSTRUCTOR;

struct TreeNode *make_tree(TREE_CONSTRUCTOR *t_c, int start, int end)
{
    if (start == end)
        return NULL;

    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = t_c->postorder[--t_c->post_index];

    int i = start;
    while (i < end && t_c->inorder[i] != node->val)
        i++;

    node->left = make_tree(t_c, start, i);
    node->right = make_tree(t_c, i + 1, end);

    return node;
}

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    TREE_CONSTRUCTOR t_c;
    
    t_c.postorder = postorder;
    t_c.post_index = postorderSize;
    t_c.inorder = inorder;
    return make_tree(&t_c, 0, inorderSize);
}

// @lc code=end
