/*
 * @lc app=leetcode id=95 lang=c
 *
 * [95] Unique Binary Search Trees II
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
struct TreeNode **dfs(int start, int end, int *returnSize)
{
    if (start > end)
    {
        (*returnSize) = 1;
        struct TreeNode **ret = malloc(sizeof(struct TreeNode *));
        ret[0] = NULL;
        return ret;
    }

    *returnSize = 0;
    struct TreeNode **allTrees = malloc(0);
    for (int i = start; i <= end; i++)
    {
        int leftTreesSize;
        int rightTreesSize;
        struct TreeNode **leftTrees = dfs(start, i - 1, &leftTreesSize);
        struct TreeNode **rightTrees = dfs(i + 1, end, &rightTreesSize);

        for (int left = 0; left < leftTreesSize; left++)
        {
            for (int right = 0; right < rightTreesSize; right++)
            {
                struct TreeNode *currTree = malloc(sizeof(struct TreeNode));
                currTree->val = i;
                currTree->left = leftTrees[left];
                currTree->right = rightTrees[right];

                (*returnSize)++;
                allTrees = realloc(allTrees, (*returnSize) * sizeof(struct TreeNode *));
                allTrees[(*returnSize) - 1] = currTree;
            }
        }
        free(rightTrees);
        free(leftTrees);
    }
    return allTrees;
}

struct TreeNode **generateTrees(int n, int *returnSize)
{
    if (n == 0)
    {
        (*returnSize) = 0;
        return NULL;
    }
    return dfs(1, n, returnSize);
}
// @lc code=end

// Official Solution
// Note: backtracing
