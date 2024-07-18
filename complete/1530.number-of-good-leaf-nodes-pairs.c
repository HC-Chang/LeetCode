/*
 * @lc app=leetcode id=1530 lang=c
 *
 * [1530] Number of Good Leaf Nodes Pairs
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
int *postOrder(struct TreeNode *currentNode, int distance)
{
    if (!currentNode)
        return calloc(12, sizeof(int));
    else if (!currentNode->left && !currentNode->right)
    {
        int *current = calloc(12, sizeof(int));
        current[0] = 1;
        return current;
    }

    int *left = postOrder(currentNode->left, distance);
    int *right = postOrder(currentNode->right, distance);

    int *current = calloc(12, sizeof(int));

    for (int i = 0; i < 10; i++)
        current[i + 1] = left[i] + right[i];

    current[11] += left[11] + right[11];

    for (int d1 = 0; d1 <= distance; d1++)
    {
        for (int d2 = 0; d2 <= distance; d2++)
        {
            if (2 + d1 + d2 <= distance)
                current[11] += left[d1] * right[d2];
        }
    }

    return current;
}
int countPairs(struct TreeNode *root, int distance)
{
    return postOrder(root, distance)[11];
}
// @lc code=end

// Note: DFS + binary tree

// Official Solution