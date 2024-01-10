/*
 * @lc app=leetcode id=2385 lang=c
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
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
int traverse(struct TreeNode *root, int start, int *maxDistance)
{
    int depth = 0;
    if (!root)
        return depth;

    int leftDepth = traverse(root->left, start, maxDistance);
    int rightDepth = traverse(root->right, start, maxDistance);

    if (root->val == start)
    {
        *maxDistance = fmax(leftDepth, rightDepth);
        depth = -1;
    }
    else if (leftDepth >= 0 && rightDepth >= 0)
        depth = fmax(leftDepth, rightDepth) + 1;
    else
    {
        int distance = abs(leftDepth) + abs(rightDepth);
        *maxDistance = fmax(*maxDistance, distance);
        depth = fmin(leftDepth, rightDepth) - 1;
    }

    return depth;
}

int amountOfTime(struct TreeNode *root, int start)
{
    int maxDistance = 0;
    traverse(root, start, &maxDistance);
    return maxDistance;
}
// @lc code=end

// Official Solution

// Note: binary tree
