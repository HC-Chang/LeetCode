/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
class Solution
{
public:
    const int MODULO = 1000000007;

    int numWays(int steps, int arrLen)
    {
        int column = min(arrLen - 1, steps);
        vector<vector<int>> dp(steps + 1, vector<int>(column + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++)
        {
            for (int j = 0; j <= column; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;
                if (j + 1 <= column)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;
            }
        }
        return dp[steps][0];
    }
};
// @lc code=end

// Note: DP
// Official Solution
