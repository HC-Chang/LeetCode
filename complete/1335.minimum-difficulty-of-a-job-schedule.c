/*
 * @lc app=leetcode id=1335 lang=c
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
int minDifficulty(int *jobDifficulty, int jobDifficultySize, int d)
{
    if (d > jobDifficultySize)
        return -1;

    int dp[jobDifficultySize][jobDifficultySize];
    for (int i = 0; i < jobDifficultySize; i++)
    {
        for (int j = 0; j < jobDifficultySize; j++)
            dp[i][j] = INT_MAX;
    }

    dp[0][0] = jobDifficulty[0];
    for (int j = 1; j < jobDifficultySize; j++)
    {
        dp[0][j] = fmax(dp[0][j - 1], jobDifficulty[j]);
    }

    int cur;
    for (int i = 1; i < d; ++i)
    {
        for (int j = i; j < jobDifficultySize; j++)
        {
            cur = jobDifficulty[j];
            for (int k = j; k >= i; k--)
            {
                cur = fmax(cur, jobDifficulty[k]);
                dp[i][j] = fmin(dp[i][j], dp[i - 1][k - 1] + cur);
            }
        }
    }
    return dp[d - 1][jobDifficultySize - 1];
}

// @lc code=end

// Note: DP