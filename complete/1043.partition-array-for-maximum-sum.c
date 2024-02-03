/*
 * @lc app=leetcode id=1043 lang=c
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
int maxSumAfterPartitioning(int *arr, int arrSize, int k)
{
    int dp[arrSize + 1];
    memset(dp, 0, sizeof(dp));
    int max;
    int sum;
    int cur;
    for (int i = 0; i < arrSize; i++)
    {
        max = 0;
        sum = 0;
        for (int j = i; j >= fmax(0, i - k + 1); j--)
        {
            max = fmax(max, arr[j]);
            cur = max * (i - j + 1) + dp[j];
            sum = fmax(sum, cur);
        }
        dp[i + 1] = sum;
    }

    return dp[arrSize];
}
// @lc code=end

// Note: DP