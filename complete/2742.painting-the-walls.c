/*
 * @lc app=leetcode id=2742 lang=c
 *
 * [2742] Painting the Walls
 */

// @lc code=start
int paintWalls(int *cost, int costSize, int *time, int timeSize)
{
    int dp[costSize + 1];
    memset(dp, 0x3f, sizeof dp);

    dp[0] = 0;
    for (int i = 1; i <= costSize; ++i)
    {
        for (int j = costSize; j >= 0; --j)
            dp[j] = fmin(dp[j], dp[(int)fmax(0, j - (1 + time[i - 1]))] + cost[i - 1]);
    }

    return dp[costSize];
}
// @lc code=end

// Note: DP