/*
 * @lc app=leetcode id=1038 lang=c
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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

// Solution 2:

void traverse(int *sum, struct TreeNode *root)
{
    if (!root)
        return;
    if (root->right)
        traverse(sum, root->right);
    root->val += *sum;
    *sum = root->val;
    if (root->left)
        traverse(sum, root->left);
}

struct TreeNode *bstToGst(struct TreeNode *root)
{
    int sum = 0;
    traverse(&sum, root);
    return root;
}

// @lc code=end

// Note: DFS

// Solution 1:

// void traverse1(int *arr, int *arr_idx, struct TreeNode *root)
// {
//     if (!root)
//         return;
//     if (root->left)
//         traverse1(arr, arr_idx, root->left);
//     arr[(*arr_idx)++] = root->val;
//     if (root->right)
//         traverse1(arr, arr_idx, root->right);
// }
// void traverse2(int *arr, int *arr_idx, struct TreeNode *root)
// {
//     if (!root)
//         return;
//     if (root->left)
//         traverse2(arr, arr_idx, root->left);
//     root->val = arr[(*arr_idx)++];
//     if (root->right)
//         traverse2(arr, arr_idx, root->right);
// }
// struct TreeNode *bstToGst(struct TreeNode *root)
// {
//     int arr[101] = {0};
//     int arr_idx = 0;
//     traverse1(&arr, &arr_idx, root);
//     for (int i = arr_idx - 2; i >= 0; i--)
//         arr[i] += arr[i + 1];

//     arr_idx = 0;
//     traverse2(&arr, &arr_idx, root);
//     return root;
// }