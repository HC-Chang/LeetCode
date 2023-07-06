/*
 * @lc app=leetcode id=102 lang=c
 *
 * [102] Binary Tree Level Order Traversal
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int height(struct TreeNode *root)
{
    if (!root)
        return 0;
    int l_len = height(root->left) + 1;
    int r_len = height(root->right) + 1;
    return l_len > r_len ? l_len : r_len;
}

int **travel(struct TreeNode *root, int **r, int level, int *col)
{
    if (!root)
        return r;

    r[level] = realloc(r[level], sizeof(int) * (col[level] + 1));
    r[level][(col[level])] = root->val;
    col[level] += 1;
    r = travel(root->left, r, level + 1, col);
    r = travel(root->right, r, level + 1, col);

    return r;
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = height(root);
    int **r = (int **)malloc(sizeof(int *) * (*returnSize));
    int *colSize = calloc((*returnSize), sizeof(int));
    for (int i = 0; i < (*returnSize); i++)
        r[i] = malloc(sizeof(int));

    r = travel(root, r, 0, colSize);
    returnColumnSizes[0] = colSize;

    return r;
}

// @lc code=end

// Note: queue