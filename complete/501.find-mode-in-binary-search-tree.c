/*
 * @lc app=leetcode id=501 lang=c
 *
 * [501] Find Mode in Binary Search Tree
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
typedef struct
{
    int index;
    int count;
} DATA;

void inorder_traverse(struct TreeNode *root, DATA *d)
{
    if (!root)
        return;
    if (root->left)
        inorder_traverse(root->left, d);
    ++(d[root->val + 100000].count);
    if (root->right)
        inorder_traverse(root->right, d);
}
int sort(void *a, void *b) { return ((DATA *)b)->count - ((DATA *)a)->count; }
int *findMode(struct TreeNode *root, int *returnSize)
{
    DATA d[200001];
    for (int i = 0; i < 200001; i++)
    {
        d[i].index = -100000 + i;
        d[i].count = 0;
    }
    inorder_traverse(root, &d);
    qsort(&d, 200001, sizeof(DATA), sort);
    *returnSize = 1;
    while (d[0].count == d[*returnSize].count)
        ++(*returnSize);
    int *r = calloc(*returnSize, sizeof(int));
    for (int i = 0; i < (*returnSize); i++)
        r[i] = d[i].index;
    return r;
}
// @lc code=end

// Note: tree