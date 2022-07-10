/*
 * @lc app=leetcode id=746 lang=c
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
int MIN(int a, int b)
{
    return a <= b ? a : b;
}

int minCostClimbingStairs(int *cost, int costSize)
{
    int *dp = calloc(costSize, sizeof(int));
    dp[costSize - 1] = cost[costSize - 1];
    dp[costSize - 2] = cost[costSize - 2];
    for (int i = costSize - 3; i >= 0; i--)
    {
        dp[i] = cost[i] + MIN(dp[i + 1], dp[i + 2]);
    }

    return MIN(dp[0], dp[1]);
}
// @lc code=end
