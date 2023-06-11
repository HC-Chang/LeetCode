/*
 * @lc app=leetcode id=450 lang=c
 *
 * [450] Delete Node in a BST
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
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    if (!root)
        return NULL;
    struct TreeNode *cur;
    if (root->val == key)
    {
        if (!root->right)
            return root->left;
        else
        {
            cur = root->right;
            while (cur->left)
                cur = cur->left;
            swap(&root->val, &cur->val);
        }
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}
// @lc code=end
