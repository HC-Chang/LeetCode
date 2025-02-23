/*
 * @lc app=leetcode id=889 lang=c
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
struct TreeNode *constructTree(int *preIndex, int *postIndex, int *preorder, int *postorder)
{
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->left = 0;
    root->right = 0;
    root->val = preorder[*preIndex];
    ++(*preIndex);

    if (root->val != postorder[*postIndex])
        root->left = constructTree(preIndex, postIndex, preorder, postorder);
    if (root->val != postorder[*postIndex])
        root->right = constructTree(preIndex, postIndex, preorder, postorder);
    ++(*postIndex);
    return root;
}

struct TreeNode *constructFromPrePost(int *preorder, int preorderSize, int *postorder, int postorderSize)
{
    int preIndex = 0;
    int postIndex = 0;
    return constructTree(&preIndex, &postIndex, preorder, postorder);
}
// @lc code=end
