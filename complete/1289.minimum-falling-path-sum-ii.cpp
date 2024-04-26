/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int res = INT_MAX;
        vector<int> dp = grid[0];

        for (int i = 0; i < n - 1; ++i)
        {
            int mn = INT_MAX;
            int idx = -1;
            int sm = INT_MAX;
            for (int j = 0; j < n; ++j)
            {
                if (dp[j] < mn)
                {
                    sm = mn;
                    mn = dp[j];
                    idx = j;
                }
                else if (dp[j] < sm)
                    sm = dp[j];
            }
            for (int j = 0; j < n; ++j)
                dp[j] = grid[i + 1][j] + (j == idx ? sm : mn);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end

// Note: DP