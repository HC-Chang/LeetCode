/*
 * @lc app=leetcode id=863 lang=c
 *
 * [863] All Nodes Distance K in Binary Tree
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
void push_arr(int val, int *index_arr, int *arr)
{
    arr[(*index_arr)++] = val;
}

int traverse(struct TreeNode *node, struct TreeNode *target, int k, int dist, int *index_arr, int *arr)
{
    if (!node)
        return 0;

    if (dist == k)
    {
        push_arr(node->val, index_arr, arr);
        return 0;
    }
    int left = 0, right = 0;
    if (node->val == target->val || dist > 0)
    {
        left = traverse(node->left, target, k, dist + 1, index_arr, arr);
        right = traverse(node->right, target, k, dist + 1, index_arr, arr);
    }
    else
    {
        left = traverse(node->left, target, k, dist, index_arr, arr);
        right = traverse(node->right, target, k, dist, index_arr, arr);
    }

    if (left == k || right == k)
    {
        push_arr(node->val, index_arr, arr);
        return 0;
    }

    if (node->val == target->val)
        return 1;
    if (left > 0)
        traverse(node->right, target, k, left + 1, index_arr, arr);
    if (right > 0)
        traverse(node->left, target, k, right + 1, index_arr, arr);
    if (left > 0 || right > 0)
        return left > 0 ? left + 1 : right + 1;
    return 0;
}

int *distanceK(struct TreeNode *root, struct TreeNode *target, int k, int *returnSize)
{
    *returnSize = 0;
    int *arr;
    if (k == 0)
    {
        arr = malloc(sizeof(int));
        push_arr(target->val, returnSize, arr);
        return arr;
    }

    arr = malloc(500 * sizeof(int));
    traverse(root, target, k, 0, returnSize, arr);
    arr = realloc(arr, *returnSize * sizeof(int));
    return arr;
}
// @lc code=end
