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

        printf("%i\n", dp[i]);
    }

    int state = 1;
    int start = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (start == 0 && (dp[i] == state || dp[i] == -state))
        {
            start = 1;
            state = dp[i];
        }
        if (start && dp[i] == state)
        {
            state = -state;
            count++;
        }
    }

    return count;
}
// @lc code=end