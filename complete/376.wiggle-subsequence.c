/*
 * @lc app=leetcode id=376 lang=c
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start

int wiggleMaxLength(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 1;
    }

    int state = 0;
    int count = 1;
    int *dp = calloc(numsSize, sizeof(int));
    dp[0] = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] - nums[i - 1] > 0)
        {
            dp[i] = 1;
        }
        else if (nums[i] - nums[i - 1] < 0)
        {
            dp[i] = -1;
        }

        if (state == 0 && dp[i] != 0)
        {
            state = dp[i];
        }

        if (state != 0 && dp[i] == state)
        {
            state = -state;
            count++;
        }

        // printf("%i\n", dp[i]);
    }

    free(dp);
    
    return count;
}
// @lc code=end