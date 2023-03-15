/*
 * @lc app=leetcode id=958 lang=c
 *
 * [958] Check Completeness of a Binary Tree
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
int count_node(struct TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + count_node(root->left) + count_node(root->right);
}

bool dfs(struct TreeNode *root, int index, int total)
{
    if (!root)
        return true;
    if (index > total)
        return false;

    return dfs(root->left, 2 * index, total) && dfs(root->right, 2 * index + 1, total);
}

bool isCompleteTree(struct TreeNode *root)
{
    int node_count = count_node(root);
    return dfs(root, 1, node_count);
}
// @lc code=end

// Note: BFS