/*
 * @lc app=leetcode id=1161 lang=c
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */

// @lc code=start
/**
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int deepth(int deep, struct TreeNode *root)
{
    if (!root)
        return deep;
    int l = deep, r = deep;
    if (root->left)
        l = deepth(deep + 1, root->left);
    if (root->right)
        r = deepth(deep + 1, root->right);
    return l > r ? l : r;
}

void traverse(int *sums, int deep, struct TreeNode *root)
{
    if (!root)
        return;
    sums[deep] += root->val;
    if (root->left)
        traverse(sums, deep + 1, root->left);
    if (root->right)
        traverse(sums, deep + 1, root->right);
}

int maxLevelSum(struct TreeNode *root)
{
    int deep = deepth(1, root);
    int *sums = calloc(deep, sizeof(int));
    traverse(sums, 0, root);

    int max_index = 0;
    for (int i = 1; i < deep; i++)
    {
        if (sums[i] > sums[max_index])
            max_index = i;
    }

    free(sums);
    return max_index + 1;
}
// @lc code=end

// Note: tree + dfs
