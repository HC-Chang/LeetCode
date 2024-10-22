/*
 * @lc app=leetcode id=2583 lang=c
 *
 * [2583] Kth Largest Sum in a Binary Tree
 */

// Difficulty:Medium

// You are given the root of a binary tree and a positive integer k.
// The level sum in the tree is the sum of the values of the nodes that are on the same level.
// Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

// Note that two nodes are on the same level if they have the same distance from the root.

// Constraints:
// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= 106
// 1 <= k <= n

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode *root)
{
    if (!root)
        return 0;
    int l_height = height(root->left) + 1;
    int r_height = height(root->right) + 1;
    return l_height > r_height ? l_height : r_height;
}

void traverse(struct TreeNode *root, int level, long long *col)
{
    if (!root)
        return;

    col[level] += root->val;
    traverse(root->left, level + 1, col);
    traverse(root->right, level + 1, col);
}

int sort(long long *a, long long *b) { return *(long long *)b > *(long long *)a; }

long long kthLargestLevelSum(struct TreeNode *root, int k)
{
    if (!root)
        return 0;

    int h = height(root);
    if (k > h)
        return -1;

    long long *level_sum = calloc((h), sizeof(long long));
    traverse(root, 0, level_sum);
    qsort(level_sum, h, sizeof(long long), sort);
    long long max_sum = level_sum[k - 1];
    free(level_sum);
    return max_sum;
}

// @lc code=end

// Note: BFS + sorting