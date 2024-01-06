/*
 * @lc app=leetcode id=300 lang=c
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// Solution 2: DP
int lengthOfLIS(int *nums, int numsSize)
{
    int arr[numsSize];
    memset(arr, 0, sizeof(arr));
    int idx = 0;
    arr[idx++] = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > arr[idx - 1])
            arr[idx++] = nums[i];
        else
        {
            for (int j = 0; j < idx; j++)
            {
                if (nums[i] <= arr[j])
                {
                    arr[j] = nums[i];
                    break;
                }
            }
        }
    }

    return idx;
}
// @lc code=end

// Note: DP / greedy + B-Search

// Solution 1: DP
int lengthOfLIS(int *nums, int numsSize)
{
    int dp_max = 1;
    int *dp = calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = fmax(dp[i], dp[j] + 1);
        }
        if (dp[i] > dp_max)
            dp_max = dp[i];
    }

    free(dp);
    return dp_max;
}
