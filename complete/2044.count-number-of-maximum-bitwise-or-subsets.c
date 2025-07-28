/*
 * @lc app=leetcode id=2044 lang=c
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
int countMaxOrSubsets(int *nums, int numsSize)
{
    int max = 0;
    int dp[1 << 17] = {0};

    dp[0] = 1;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = max; j >= 0; j--)
            dp[j | nums[i]] += dp[j];

        max |= nums[i];
    }

    return dp[max];
}
// @lc code=end

// Note: bit manipulation

// Official Solution