/*
 * @lc app=leetcode id=658 lang=c
 *
 * [658] Find K Closest Elements
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *findClosestElements(int *arr, int arrSize, int k, int x, int *returnSize)
{
    // Solution 1: DP
    *returnSize = k;

    int *dp = calloc(arrSize, sizeof(int));
    for (int i = 0; i < arrSize; i++)
    {
        dp[i] = (arr[i] - x >= 0) ? (arr[i] - x) : -(arr[i] - x);
    }

    int small_index = 0;
    for (int i = 0; i < arrSize - k + 1; i++)
    {
        for (int j = i + 1; j < i + k; j++)
        {
            dp[i] += dp[j];
        }
        if (dp[small_index] > dp[i])
        {
            small_index = i;
        }
    }

    return arr + small_index;
}
// @lc code=end

// Solution 1: DP
// Solution 2: BST
