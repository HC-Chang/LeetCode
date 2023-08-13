/*
 * @lc app=leetcode id=2369 lang=c
 *
 * [2369] Check if There is a Valid Partition For The Array
 */

// @lc code=start
bool validPartition(int *nums, int numsSize)
{
    bool *dp = calloc(numsSize + 1, sizeof(bool));
    dp[0] = true;
    for (int i = 0; i < numsSize; i++)
    {
        if (dp[i])
        {
            if (i + 1 < numsSize && nums[i] == nums[i + 1])
                dp[i + 2] = true;
            if (i + 2 < numsSize && ((nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) || (nums[i] == nums[i + 1]) && nums[i + 1] == nums[i + 2]))
                dp[i + 3] = true;
        }
    }

    bool b = dp[numsSize];
    free(dp);
    return b;
}
// @lc code=end

// Note: DP
