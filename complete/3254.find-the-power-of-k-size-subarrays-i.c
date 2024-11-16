/*
 * @lc app=leetcode id=3254 lang=c
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int check(int i, int *nums, int numsSize, int k)
{
    int n = numsSize;
    for (int j = 1; j < k; j++)
    {
        if (i + j >= n || nums[i + j] - nums[i + j - 1] != 1)
            return -1;
    }
    return nums[i + k - 1];
}

int *resultsArray(int *nums, int numsSize, int k, int *returnSize)
{
    *returnSize = numsSize + 1 - k;
    if (k == 1)
        return nums;

    int *ans = malloc((numsSize + 1 - k) * sizeof(int));
    int n = numsSize;
    ans[0] = check(0, nums, numsSize, k);
    int tmp;
    for (int i = 1; i + k - 1 < n; i++)
    {
        tmp = check(i, nums, numsSize, k);
        if (ans[i - 1] == -1)
            ans[i] = tmp;
        else if (tmp - ans[i - 1] == 1)
            ans[i] = tmp;
        else
            ans[i] = -1;
    }

    return ans;
}
// @lc code=end

// Note: sliding window