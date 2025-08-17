/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0)
            return 1.0;
        if (n >= k - 1 + maxPts)
            return 1.0;

        vector<double> dp(n + 1);
        double probablity = 0.0;
        double totalSum = 1.0;
        dp[0] = 1.0;
        for (int i = 1; i < n + 1; i++)
        {
            dp[i] = totalSum / maxPts;
            if (i < k)
                totalSum += dp[i];
            else
                probablity += dp[i];

            if (i >= maxPts)
                totalSum -= dp[i - maxPts];
        }

        return probablity;
    }
};
// @lc code=end

// Note: DP