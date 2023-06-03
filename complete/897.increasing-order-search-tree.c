/*
 * @lc app=leetcode id=897 lang=c
 *
 * [897] Increasing Order Search Tree
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
void inorder(int *index, int *arr, struct TreeNode *root)
{
    if (!root)
        return;
    if (root->left)
        inorder(index, arr, root->left);
    arr[(*index)++] = root->val;
    if (root->right)
        inorder(index, arr, root->right);
}

struct TreeNode *increasingBST(struct TreeNode *root)
{
    int index = 0;
    int arr[100] = {0};
    inorder(&index, arr, root);
    struct TreeNode *obj = calloc(1, sizeof(struct TreeNode));
    obj->val = arr[0];
    struct TreeNode *head = obj;
    for (int i = 1; i < index; i++)
    {
        obj->right = calloc(1, sizeof(struct TreeNode));
        obj = obj->right;
        obj->val = arr[i];
    }
    return head;
}
// @lc code=end
