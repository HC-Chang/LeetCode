/*
 * @lc app=leetcode id=2742 lang=cpp
 *
 * [2742] Painting the Walls
 */

// @lc code=start
class Solution
{
public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        int dp[n + 1];
        memset(dp, 0x3f, sizeof(dp));

        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = n; j >= 0; --j)
                dp[j] = min(dp[j], dp[max(0, j - (1 + time[i - 1]))] + cost[i - 1]);
        }

        return dp[n];
    }
};
// @lc code=end

// Note: DP