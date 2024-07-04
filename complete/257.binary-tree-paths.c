/*
 * @lc app=leetcode id=257 lang=c
 *
 * [257] Binary Tree Paths
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode *root, int *arr, int *arr_size, char **ans,
              int *ans_size)
{
    if (!root)
        return;
    arr[(*arr_size)++] = root->val;
    if (root->left)
    {
        traverse(root->left, arr, arr_size, ans, ans_size);
        --*arr_size;
    }
    if (root->right)
    {
        traverse(root->right, arr, arr_size, ans, ans_size);
        --*arr_size;
    }
    if (!root->left && !root->right)
    {
        char *s =
            malloc((3 * (*arr_size) + 2 * ((*arr_size) - 1) + 1) * sizeof(char));
        int idx = 0;
        for (int i = 0; i < (*arr_size) - 1; i++)
        {
            sprintf(s + idx, "%d->", arr[i]);
            idx = strlen(s);
        }
        sprintf(s + idx, "%d", arr[(*arr_size) - 1]);
        ans[(*ans_size)++] = s;
    }
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
    int arr[100] = {0};
    int arr_size = 0;
    char **ans = malloc(100 * sizeof(char *));
    *returnSize = 0;
    traverse(root, arr, &arr_size, ans, returnSize);
    return ans;
}
// @lc code=end

// Note: backtracking + tree