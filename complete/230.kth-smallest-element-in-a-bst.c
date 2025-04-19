/*
 * @lc app=leetcode id=230 lang=c
 *
 * [230] Kth Smallest Element in a BST
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
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void push_arr(int val, int *index, int *arr)
{
    arr[(*index)++] = val;
}
void traverse(struct TreeNode *root, int *index, int *arr)
{
    if (!root)
        return;
    push_arr(root->val, index, arr);
    traverse(root->left, index, arr);
    traverse(root->right, index, arr);
}

int kthSmallest(struct TreeNode *root, int k)
{
    int index = 0;
    int arr[10001] = {0};
    traverse(root, &index, &arr);
    qsort(&arr, index, sizeof(int), sort);
    return arr[k - 1];
}
// @lc code=end

// BST + sort