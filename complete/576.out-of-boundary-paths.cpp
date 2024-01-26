/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int mod = 1e9 + 7;

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int cnt = 0;

        vector<vector<int>> dp(m, vector<int>(n));
        int tmp_cnt;
        dp[startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; i++)
        {
            vector<vector<int>> tmp(m, vector<int>(n));
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    tmp_cnt = dp[j][k];
                    if (tmp_cnt > 0)
                    {
                        for (int s = 0; s < 4; s++)
                        {
                            int j1 = j + directions[s][0], k1 = k + directions[s][1];
                            if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n)
                                tmp[j1][k1] = (tmp[j1][k1] + tmp_cnt) % mod;
                            else
                                cnt = (cnt + tmp_cnt) % mod;
                        }
                    }
                }
            }
            dp = tmp;
        }
        return cnt;
    }
};
// @lc code=end

// Note: DP

// Official Solution